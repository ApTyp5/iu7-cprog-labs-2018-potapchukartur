#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <time.h>

#define KVO_EL 10
#define MIN_KVO_PAR 3
#define SUCCESS_PROV 1
#define UNSUCCESS_PROV 0
#define HAPPY_END 0
#define FORMAT_ERROR -1
#define OPEN_FILE_ERROR -2

void format_help()
{
    printf("main <filename> <parametr1> <parametr2>...\n");
    printf("types of parametrs:\n");
    printf("1. '-sh' '--show' -- show the containment of file\n");
    printf("2. '-f' '--fill' -- fill the file with the rand ints\n");
    printf("3. '-s' '--sort' -- sort the containment of file in the ");
    printf("increasing range.");
}
int format_prov(int argc)
{
    if (argc >= MIN_KVO_PAR)
        return HAPPY_END;
    return FORMAT_ERROR;
}

int string_equiv(char *par,char *str1,char *str2)
{
    if (!strcmp(par,str1) || !strcmp(par,str2))
        return SUCCESS_PROV;
    else
        return UNSUCCESS_PROV;
}

void fill(FILE *f)
{
    // На входе файл, открытый на запись

    int num;
	
	srand(time(NULL));
	
    for (int i = 0; i < KVO_EL; i++)
    {
        num = rand();
        fwrite(&num,sizeof(int),1,f);
    }
	printf("\n");
}


void show(FILE *f)
{
    // На входе файл, открытый на чтение

    int num;
    while (fread(&num,sizeof(int),1,f)==1)
	{
        fprintf(stdout,"%d ",num);
	}
	
	fprintf(stdout,"\n");
}




void get_number_by_pos(FILE *f, int pos, int *num)
{
	fseek(f,pos,SEEK_SET);
	printf("%d\n",fread(num, sizeof(int),1,f));
	printf("\n%d",*num);
}

void set_number_by_pos(FILE *f, int kuda, int otkuda)
{
	int el;
	int vspom;
	
	fseek(f,otkuda,SEEK_SET);
	fread(&el,sizeof(int),1,f);
	fseek(f,otkuda,SEEK_SET);
	
	for (int i = otkuda; i < KVO_EL + 1; i++)
	{
		fread(&vspom,sizeof(int),1,f);
		printf("write:%d\n",(int)fwrite(&vspom,sizeof(int),1,f));
	}
	
	fseek(f,kuda,SEEK_SET);
}



void sort(char *filename)
{
	int j, i = 0;
	int num;
	int vspom;
	FILE *f;
	
	f = fopen(filename, "wb+rb");
	for (int n = 0; n < KVO_EL; n++)
	{
		get_number_by_pos(f,i,&num);
		for (j = i; j > 0; j--)
		{
			get_number_by_pos(f, j-1, &vspom);
			if (vspom <= num)
				break;
		}
		set_number_by_pos(f,j,i);
		i++;
	}
	
	fclose(f);
	
}


int open_file_prov(FILE **f,char *filename,char *mode)
{
    if (!(*f = fopen(filename, mode)))
    {
        perror("Open file error: ");
        return UNSUCCESS_PROV;
    }
    return SUCCESS_PROV;
}

int main(int argc, char **argv)
{
    FILE *f = 0;
	

    if (format_prov(argc))
    {
        format_help();

        return FORMAT_ERROR;
    }

	for (int i = 2; i < argc; i++)
    {

        if (string_equiv(argv[i],"-f","--fill"))
        {

            if (open_file_prov(&f,argv[1],"wb"))
			{
                fill(f);
			}
            else
                return OPEN_FILE_ERROR;

        }

        else if (string_equiv(argv[i],"-sh","--show"))
        {

            if (open_file_prov(&f,argv[1],"rb"))
			{
                show(f);
			}
			else

                return OPEN_FILE_ERROR;

        }

        else if (string_equiv(argv[i],"-s","-sort"))
        {
            sort(argv[1]);
        }

        fclose(f);
    }
    return HAPPY_END;
}
