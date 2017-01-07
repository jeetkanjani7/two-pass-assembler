
/*
TEAM MEMBERS:
1)	HARSHDEEP SINGH(14UCS045)
2)	JEET KANJANI(14UCS052)
3)	INDRESH KHANDELWAL(14UCS049)
4)	DIGVIJAY SINGH SHEKHAWAT(14UCS038)

*/

#include<stdio.h>
#include<stdbool.h>
#include <ctype.h>
int main(void)
{
	int check;
	printf("FOR EVEN OR ODD USE FILE CODE1.c\n");
	printf("FOR DISPLAYING FACTORS OF A NUMBER USE FILE CODE2.c\n");
	printf("\n");
	printf("INPUT 0 FOR EVEN ODD OR AND 1 FOR DISPLATING FACTORS");
	scanf("%d",&check);

	FILE *fp,*fptr;
	if(check==0)
	{
		fp=fopen("CODE1.txt","r+");
		fptr=fopen("SYMBOL TABLE1.txt","w+");
	}

	else
	{
		fp=fopen("CODE2.txt","r+");
		fptr=fopen("SYMBOL TABLE2.txt","w+");
	}
	//fptr=fopen("SYMBOL TABLE1.txt","w+");
	char store[500],buff[500];
	int i=0,line=1,j;

	while(fgets(store, 500 , (FILE*)fp)!=NULL)
	{
		char temp=store[0];

		i=0;
		while(1)
		{
			if(isalnum(temp))
			{
				i++;
			}

			else if(temp==':')
			{
				i++;
			}

			else
			{
				line++;
				break;
			}

			temp=store[i];
		}

		if(store[i-1]==':')
		{
			store[i-1]='\0';
			fprintf(fptr,"$");
			fputs(store,fptr);

			int line2=line;
			char ar[]="00000";
			int p=4;
			while(line2)
			{
				if(line2%2==1)
				{
					ar[p]='1';
				}

				line2=line2/2;
				p--;
			}

			fprintf(fptr,"  %s \n",ar);
		}
	}

	fclose(fp);
}
