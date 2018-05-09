#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>
#include <string.h>
#define KVO_NUMBERS 10
#define WRONG_FORMAT -1
#define OPEN_FILE_ERROR -2
#define WRONG_INPUT -3
#define HAPPY_END 0

void format_help()
{
    printf("Wrong call format\n");
    printf("Frame of the right call: \nmain <filename.txt> <args>...\n");
    printf("<args>:\n 1. '-f', '--fill' - Заполнение <filename.txt> случайными числами.");
    printf("\n 2. '-sh', '--show' - Вывод на экран содержимого <filename.txt>");
    printf("\n 3. '-s', '--sort' - Сортировка содержимого <filename.txt>");
    printf("\n P.S. Параметры <args> будут выполняться в порядке слева направо любое ");
    printf("\nколичество раз.");
}
void fill(FILE *f)
{
    int t;
    for (int i = 0; i < KVO_NUMBERS; i++)
    {
        t = rand();
        fwrite(&t,4,1,f);
    }
}

void show(FILE *f)
{
    int x;
    while (1)
    {
        if (feof(f))
            break;
        if (fread(&x,4,1,f) == 1)
            printf("%d ",x);
    }
    printf("\n");
}

void copy(FILE *f, FILE *vspom)
{
    int i;
    while (fread(&i,4,1,f) == 1)
        fwrite(&i,4,1,vspom);
}

void put_number_by_pos(FILE *f, int num, int pos)
{
    fseek(f,pos,SEEK_CUR);
    fwrite(&num, sizeof(int),1,f);
}

int get_number_by_pos(FILE *f, int pos)
{
    int viv;
    fseek(f,pos,SEEK_CUR);
    if (fread(&viv,sizeof(int),1,f) == 1)
        return viv;
    else
        return EOF;

}

void sort(FILE *f,char *argv)
{
    FILE *vspom;
    // schet - СЧЁТчик
    int schet = 0;
    int numv = -1;
    int numf;
    int i;

    vspom = fopen(".vspom","wb");
    copy(f,vspom);
    fclose(vspom);
    vspom = fopen(".vspom","rb");

    fclose(f);

    schet = 0;
    while (1)
    {
        numv = get_number_by_pos(vspom,schet);
        if (numv == EOF)
            break;
        f = fopen(argv,"rb");
        for (i = schet - 1; i > -1; i--)
        {
            numf = get_number_by_pos(f,i);
            if (numv >= numf)
                break;
        }
        fclose(f);
        f = fopen(argv,"wb");
        put_number_by_pos(f,numv,i+1);
        fclose(f);
        schet += 1;
    }

    fclose(vspom);
}

int main(int args, char **argv)
{
    FILE *f;
    int rc = HAPPY_END;

    if (args <= 2)
    {
	format_help();
        rc = WRONG_FORMAT;
    }
    else
    {
        f = fopen(argv[1], "wb");
        if (f)
            for (int i = 2; i < args; i++)
            {
                if (!strcmp(argv[i],"-f") || !strcmp(argv[i],"--fill"))
                {
                    fclose(f);
                    f = fopen(argv[1], "wb");
                    fill(f);
                    rc = HAPPY_END;
                    continue;
                }
                if (!strcmp(argv[i],"-sh") || !strcmp(argv[i],"--show"))
                {
                    fclose(f);
                    f = fopen(argv[1], "rb");
                    show(f);
                    rc = HAPPY_END;
                    continue;
                }
                if (!strcmp(argv[i],"-s") || !strcmp(argv[i],"--sort"))
                {
                    fclose(f);
                    f = fopen(argv[1], "rb");
                    sort(f,argv[1]);
                    continue;
                }
            }

        else
            rc = OPEN_FILE_ERROR;
        fclose(f);
    }
    return rc;
}

