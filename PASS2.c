/*
TEAM MEMBERS:
1)	HARSHDEEP SINGH(14UCS045)
2)	JEET KANJANI(14UCS052)
3)	INDRESH KHANDELWAL(14UCS049)
4)	DIGVIJAY SINGH SHEKHAWAT(14UCS038)

*/
#include<stdio.h>
#include<string.h>
int main(void)
{
	int check;
	printf("FOR EVEN OR ODD USE FILE CODE1.c\n");
	printf("FOR DISPLAYING FACTORS OF A NUMBER USE FILE CODE2.c\n");
	printf("\n");
	printf("INPUT 0 FOR EVEN ODD OR AND 1 FOR DISPLATING FACTORS");
	scanf("%d",&check);

	FILE *fp,*fpop,*fpreg,*fpcons,*fplab,*fpf;
	char word[500],temp1[500],temp2[500],temp3[500],temp4[500];
	char c,c1,c2,c3;

	if(check==0)
	{
		fp = fopen("CODE1.txt","r");
		fplab = fopen("SYMBOL TABLE1.txt","r+");
		fpf = fopen("FINAL1.txt","w+");
	}

	else
	{
		fp = fopen("CODE2.txt","r");
		fplab = fopen("SYMBOL TABLE2.txt","r+");
		fpf = fopen("FINAL2.txt","w+");
	}
	fpop = fopen("OPCODES.txt","r");
	fpreg = fopen("REGISTERS.txt","r");

	while(fscanf(fp,"%s",word)!=EOF)
	{

		if(word[0]=='#')
		{	char t[500];
			int l=strlen(word),val;
			int k;
			for(k=1;k<l;k++)
			{
				t[k-1]=word[k];
			}
			t[l-1]='\0';
			val=atoi(t);

			char ar[]="00000000";

			int p=7;
			while(val)
			{
				if(val%2==1)
				{
					ar[p]='1';
				}

				val=val/2;
				p--;
			}

			fprintf(fpf,"%s",ar);
		}

		else
		{
			while(fscanf(fpop,"%s",temp1)!=EOF)
			{
				if(strcmp(word,temp1)==0)
				{
					fscanf(fpop,"%s",temp1);
					fputs(temp1,fpf);

				}
			}
			rewind(fpop);

			while(fscanf(fpreg,"%s",temp2)!=EOF)
			{
				if(strcmp(word,temp2)==0)
				{
					fscanf(fpreg,"%s",temp2);
					fputs(temp2,fpf);

				}
			}
			rewind(fpreg);


			while(fscanf(fplab,"%s",temp4)!=EOF)
			{
				if(strcmp(word,temp4)==0)
				{
					fscanf(fplab,"%s",temp4);
					fputs(temp4,fpf);

				}
			}
			rewind(fplab);

			c=fgetc(fp);
			c1='\n';
			if(c!=' ')
			{
				fputc(c1,fpf);
			}
		}
	}



	fclose(fp);
	fclose(fpop);
	fclose(fpreg);
	fclose(fplab);
	fclose(fpf);

return  0;
}
