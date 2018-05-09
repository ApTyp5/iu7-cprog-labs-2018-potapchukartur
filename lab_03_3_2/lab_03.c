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
#define NON_HAPPY_END -1
#define FORMAT_ERROR -2
#define OPEN_FILE_ERROR -3
#define CLOSE_FILE_ERROR -4
#define SORTING_ERROR -5


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




int get_number_by_pos(FILE *f, int pos, int *num)
{
	if (fseek(f,pos*sizeof(int),SEEK_SET))
    {
        return NON_HAPPY_END;
    }
    
    
	if (!fread(num, sizeof(int),1,f))
    {
        return NON_HAPPY_END;
	}
    
    return HAPPY_END;
}

int set_number_by_pos(FILE *f, int to, int from)
{
	int el;
	int vspom;
	
	if (fseek(f,from*sizeof(int),SEEK_SET))
        return NON_HAPPY_END;
    
	if (!fread(&el,sizeof(int),1,f))
        return NON_HAPPY_END;
    
	if (fseek(f,from*sizeof(int),SEEK_SET))
        return NON_HAPPY_END;
	
    for (int i = from; i > to ; i--)
    {
        if (fseek(f,(i-1)*sizeof(int),SEEK_SET))
            return NON_HAPPY_END;
        
        if (!fread(&vspom,sizeof(int),1,f))
            return NON_HAPPY_END;
        
        if (fseek(f,i*sizeof(int),SEEK_SET))
            return NON_HAPPY_END;
        
        if (!fwrite(&vspom,sizeof(int),1,f))
            return NON_HAPPY_END;
    }
    
    if (fseek(f,to*sizeof(int),SEEK_SET))
        return NON_HAPPY_END;
    
    if (!fwrite(&el,sizeof(int),1,f))
        return NON_HAPPY_END;
    
    return HAPPY_END;
}



int sort(FILE *f)
{
	int j, i = 0;
	int num;
	int vspom;
	
	for (int n = 1; n <= KVO_EL; n++)
	{
		if (get_number_by_pos(f,i,&num))
        {
            return NON_HAPPY_END;
        }
        
		for (j = i; j > 0; j--)
		{
			if (get_number_by_pos(f, j-1, &vspom))
            {
                return NON_HAPPY_END;
            }
            
			if (vspom <= num)
				break;
		}
        
		if (set_number_by_pos(f,j,i))
        {
            return NON_HAPPY_END;
        }
		i++;
	}
    
    return HAPPY_END;
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
    int rc = HAPPY_END;
	

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
            {
                perror("Open file error: ");
                return OPEN_FILE_ERROR;
            }

        }

        else if (string_equiv(argv[i],"-sh","--show"))
        {

            if (open_file_prov(&f,argv[1],"rb"))
			{
                show(f);
			}
			else
            {
                perror("Open file error: ");
                return OPEN_FILE_ERROR;
            }
        }

        else if (string_equiv(argv[i],"-s","-sort"))
        {
            if (open_file_prov(&f, argv[1], "r+w"))
            {
                if (sort(f))
                {
                    perror("Error while sorting: ");
                    rc = SORTING_ERROR;
                }
            }
            else
            {
                perror("Open file error: ");
                return OPEN_FILE_ERROR;
            }
        }

        if (fclose(f))
        {
            perror("Close file error: ");
            return CLOSE_FILE_ERROR;
        }
    }
    
    return rc;
}