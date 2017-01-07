/*
TEAM MEMBERS:
1)	HARSHDEEP SINGH(14UCS045)
2)	JEET KANJANI(14UCS052)
3)	INDRESH KHANDELWAL(14UCS049)
4)	DIGVIJAY SINGH SHEKHAWAT(14UCS038)
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int reg[16]={0};
int flag[32]={0};
int program;FILE *fpf;
int check=0;

int powe(int a,int b)
{
	int i,p=1;
	for(i=0;i<b;i++)
	{
		p=p*a;
	}

return p;
}

int add(int x, int y)
{  
    while (y != 0)
    {
        int carry = x & y;  
        x = x ^ y; 
        y = carry << 1;
    }
    return x;
}

int subtract(int x, int y)
{

    while (y != 0)
    {
        int borrow = (~x) & y;
        x = x ^ y;
        y = borrow << 1;
    }
    return x;
}

int multiply(int x, int y)
{
  
   if(y == 0)
     return 0;
 
  
   if(y > 0 )
     return (x + multiply(x, y-1));
  
   if(y < 0 )
     return -multiply(x, -y);
}

void hlt()
{	
	int k,i;	

	for(i=0;i<16;i++)
	{
		fprintf(fpf,"reg[%d]=%d \n",i,reg[i]);
	}fputs("\n",fpf);	

	if(program==0)
	{
		if(reg[0]==0)
		{
			printf("EVEN \n");
			fputs("GIVEN NUMBER IS EVEN",fpf);
		}

		else 
		{
			printf("ODD \n");
			fputs("GIVEN NUMBER IS ODD",fpf);
		}
	}

	
	exit(0);
}

void solve(char *st,char *bincode,char *opcode)
{
	fputs("\n",fpf);
	fputs(st,fpf);
	fputs(":  ",fpf);
	fputs(opcode,fpf);
	fputs("\n",fpf);	
	if(strcmp(st,"MOVI")==0)
	{

		int i,reg_val=0,imm_val=0;
		
		for(i=strlen(opcode);i<(strlen(opcode)+8);i++)
		{
			int tempo= (int) (bincode[i] - '0');
			imm_val+= powe(2, 7- ( i - strlen(opcode) ) )*tempo;
		}

		for(i=strlen(opcode)+8;i<32;i++)
		{
			int tempo= (int) (bincode[i] - '0');
			reg_val+= powe(2, 3- ( i - (strlen(opcode)+8) ) )*tempo;
		}
		
		fputs("Reg no = ",fpf);
		fprintf(fpf, "%d",reg_val); 
		fputs(" || ",fpf);
		fputs("Value = ",fpf);
		fprintf(fpf, "%d\n",imm_val);
		
		
		
		reg[reg_val]=imm_val;			
	}

	if(strcmp(st,"IN")==0)
	{

		int i,reg_val=0,imm_val=0;
		
		for(i=strlen(opcode);i<(strlen(opcode)+4);i++)
		{
			int tempo= (int) (bincode[i] - '0');
			reg_val+= powe(2,3-(i-strlen(opcode) ) )*tempo;
		}

		if(check==0)
		{
			printf("EVEN OR ODD \n");
			program=0;
		}

		else
		{
			printf("DISPLAY FACTORS \n");
			program=1;
		}
			
		int n;printf("Enter the number : ");
		scanf("%d",&n);
		fputs("Reg no = ",fpf);
		fprintf(fpf, "%d \n",reg_val); 

		reg[reg_val]=n;
	}

	if(strcmp(st,"MOV")==0)
	{
		int i,reg1_val=0,reg2_val=0;
		
		for(i=strlen(opcode);i<(strlen(opcode)+4);i++)
		{
			int tempo= (int) (bincode[i] - '0');
			reg1_val+= powe(2,3-(i-strlen(opcode) ) )*tempo;
		}

		for(i=strlen(opcode)+4;i<32;i++)
		{
			int tempo= (int) (bincode[i] - '0');
			reg2_val+= powe(2,3-(i-  (strlen(opcode)+4)   )   )*tempo;
		}
		fputs("Reg1 no = ",fpf);
		fprintf(fpf, "%d",reg1_val); 
		fputs(" || ",fpf);
		fputs("Reg2 no = ",fpf);
		fprintf(fpf, "%d",reg2_val);
		fputs("\n",fpf);		
		reg[reg1_val]=reg[reg2_val];
	}

	if(strcmp(st,"OUT")==0)
	{
		int i,reg_val=0,imm_val=0;
		
		for(i=strlen(opcode);i<(strlen(opcode)+4);i++)
		{
			int tempo= (int) (bincode[i] - '0');
			reg_val+= powe(2,3-(i-strlen(opcode) ) )*tempo;
		}

		fputs("Reg no = ",fpf);
		fprintf(fpf, "%d \n",reg_val); 
		
		printf("factor := %d \n",reg[reg_val]);
		if(program==1)
		{
			fprintf(fpf,"%d----> IS A FACTOR \n",reg[reg_val]);
		}
	}

	if(strcmp(st,"SUB")==0)
	{
		int i,reg1_val=0,reg2_val=0;

		for(i=strlen(opcode);i<(strlen(opcode)+4);i++)
		{
			int tempo= (int) (bincode[i] - '0');
			reg1_val+= powe(2,3-(i-strlen(opcode) ) )*tempo;
		}

		for(i=strlen(opcode)+4;i<32;i++)
		{
			int tempo= (int) (bincode[i] - '0');
			reg2_val+= powe(2,3-(i-  (strlen(opcode)+4)   )   )*tempo;
		}
		fputs("Reg1 no = ",fpf);
		fprintf(fpf, "%d",reg1_val); 
		fputs(" || ",fpf);
		fputs("Reg2 no = ",fpf);
		fprintf(fpf, "%d\n",reg2_val);
		fputs("ALU : 0000 \n",fpf);
		

		reg[reg1_val]=subtract(reg[reg1_val],reg[reg2_val]);
	}

	if(strcmp(st,"ADD")==0)
	{
		int i,reg1_val=0,reg2_val=0;

		for(i=strlen(opcode);i<(strlen(opcode)+4);i++)
		{
			int tempo= (int) (bincode[i] - '0');
			reg1_val+= powe(2,3-(i-strlen(opcode) ) )*tempo;
		}

		for(i=strlen(opcode)+4;i<strlen(bincode);i++)
		{
			int tempo= (int) (bincode[i] - '0');
			reg2_val+= powe(2,3-(i-  (strlen(opcode)+4)   )   )*tempo;
		}
		fputs("Reg1 no= ",fpf);
		fprintf(fpf, "%d",reg1_val); 
		fputs(" || ",fpf);
		fputs("Reg2 no = ",fpf);
		fprintf(fpf, "%d\n",reg2_val);
		
		fputs("ALU : 0001 \n",fpf);
		//reg[reg1_val]+=reg[reg2_val];
		reg[reg1_val]=add(reg[reg1_val],reg[reg2_val]);
	}

	if(strcmp(st,"MUL")==0)
	{
		int i,reg1_val=0,reg2_val=0;
		
		for(i=strlen(opcode);i<(strlen(opcode)+4);i++)
		{
			int tempo= (int) (bincode[i] - '0');
			reg1_val+= powe(2,3-(i-strlen(opcode) ) )*tempo;
		}

		for(i=strlen(opcode)+4;i<strlen(bincode);i++)
		{
			int tempo= (int) (bincode[i] - '0');
			reg2_val+= powe(2,3-(i-  (strlen(opcode)+4)   )   )*tempo;
		}
		fputs("Reg1 no = ",fpf);
		fprintf(fpf, "%d",reg1_val); 
		fputs(" || ",fpf);
		fputs("Reg2 no = ",fpf);
		fprintf(fpf, "%d\n",reg2_val);
		
		fputs("ALU : 0010 \n",fpf);
		
		reg[reg1_val]=multiply(reg[reg1_val],reg[reg2_val]);
	}

	if(strcmp(st,"DIV")==0)
	{
		int i,reg1_val=0,reg2_val=0;

		for(i=strlen(opcode);i<(strlen(opcode)+4);i++)
		{
			int tempo= (int) (bincode[i] - '0');
			reg1_val+= powe(2,3-(i-strlen(opcode) ) )*tempo;
		}

		for(i=strlen(opcode)+4;i<strlen(bincode);i++)
		{
			int tempo= (int) (bincode[i] - '0');
			reg2_val+= powe(2,3-(i-  (strlen(opcode)+4)   )   )*tempo;
		}
		fputs("Reg1 no = ",fpf);
		fprintf(fpf, "%d",reg1_val); 
		fputs(" || ",fpf);
		fputs("Reg2 no = ",fpf);
		fprintf(fpf, "%d\n",reg2_val);
		
		fputs("ALU : 0101 \n",fpf);
		reg[reg1_val]/=reg[reg2_val];
	}

	if(strcmp(st,"INC")==0)
	{
		int i,reg_val=0,imm_val=0;

		for(i=strlen(opcode);i<(strlen(opcode)+4);i++)
		{
			int tempo= (int) (bincode[i] - '0');
			reg_val+= powe(2,3-(i-strlen(opcode) ) )*tempo;
		}

		fputs("Reg2 no = ",fpf);
		fprintf(fpf, "%d\n",reg_val); 
		fputs("ALU : 0101 \n",fpf);
		
		reg[reg_val]=add(reg[reg_val],1);
	}

	if(strcmp(st,"DEC")==0)
	{
		int i,reg_val=0,imm_val=0;
		
		for(i=strlen(opcode);i<(strlen(opcode)+4);i++)
		{
			int tempo= (int) (bincode[i] - '0');
			reg_val+= powe(2,3-(i-strlen(opcode) ) )*tempo;
		}
		fputs("Reg2 no = ",fpf);
		fprintf(fpf, "%d\n",reg_val); 
		fputs("ALU : 0110 \n",fpf);

		
		reg[reg_val]=subtract(reg[reg_val],1);
	}

	if(strcmp(st,"HLT")==0)
	{
		hlt();
	}

	int i=0;
	for(i=0;i<16;i++)
	{
		fprintf(fpf,"reg[%d]=%d \n",i,reg[i]);
	}fputs("\n",fpf);
}
			
int main(void)
{
	printf("FOR CHECKING EVEN OR ODD USE FILE FINAL1.c\n");
	printf("FOR DISPLAYING FACTORS OF A NUMBER USE FILE FINAL2.c\n");
	printf("\n");
	printf("INPUT 0 FOR EVEN ODD OR AND 1 FOR DISPLATING FACTORS");
	scanf("%d",&check);
	FILE *ft,*fp,*fpreg,*fpb,*fpop;
	if(check==0)
	{
		fp = fopen("FINAL1.txt","r+");
		fpf = fopen("OUTPUT1.txt","w+");
	}

	else
	{
		fp = fopen("FINAL2.txt","r+");
		fpf = fopen("OUTPUT2.txt","w+");
	}
	fpop = fopen("OPCODES.txt","r");
	fpreg = fopen("REGISTERS.txt","r");

	char word[50],store[400][33],oper[400][5],code[400][33];
	char wtemp[50],otemp[50],otemp2[3],wtemp2[3];
	int len=1,i=0,j=0,k=0;	

	 while( fgets (word, 50, fp)!=NULL ) 
	{
		if(word[0]=='\0')
		{
			i=i;
		}
		else
		{
			strcpy(store[i],word);
			
		}
		i++;
	}

	int size_bin=i;
	i=0;

	while(fscanf(fpop,"%s",word)!=EOF)
	{	
	
		if(i%2==0)
		{		
			strcpy(oper[i/2],word);
		}

		if(i%2!=0)
		{		
			strcpy(code[i/2],word);
		}
		i++;
	}
	
	int size_op=i/2;

	for(i=0;i<size_bin;i++)
	{
		strcpy(word,store[i]);
		for(j=0;j<4;j++)
		{
			wtemp[j]=store[i][j];
		}

		wtemp[4]='\0';
		
		for(j=0;j<size_op;j++)
		{
			for(k=0;k<4;k++)
			{
				otemp[k]=code[j][k];
			}
				 
			otemp[4]='\0';
			
			if(strcmp(wtemp,otemp)==0)
			{
				len=strlen(code[j]);

				wtemp2[0]=store[i][len-2];
				wtemp2[1]=store[i][len-1];
				wtemp2[2]='\0';

				otemp2[0]=code[j][len-2];
				otemp2[1]=code[j][len-1];
				otemp2[2]='\0';
				int pp=strlen(wtemp2);
				
				if(strcmp(wtemp2,otemp2)==0)
				{	
					int line=0;
					
					if(strcmp(oper[j],"CMPI")==0)
					{
	
						int t,reg_val=0,imm_val=0;
		
						for(t=strlen(code[j]);t<(strlen(code[j])+8);t++)
						{
							int tempo= (int) (store[i][t] - '0');
							imm_val+= powe(2, 7- ( t - strlen(code[j]) ) )*tempo;
						}

						for(t=strlen(code[j])+8;t<32;t++)
						{	
							int tempo= (int) (store[i][t] - '0');
							reg_val+= powe(2, 3- ( t - (strlen(code[j])+8) ) )*tempo;
						}

						fputs("\n",fpf);
						fputs(oper[j],fpf);
						fputs(":  ",fpf);
						fputs(code[j],fpf);
						fputs("\n",fpf);
						fputs("Reg no = ",fpf);
						fprintf(fpf, "%d",reg_val); 
						fputs(" || ",fpf);
						fputs("Value = ",fpf);
						fprintf(fpf, "%d\n",imm_val);	


					       if(reg[reg_val]>imm_val)
						{
							flag[0]=1;
							fputs("Zero flag up : ",fpf);
							for(k=0;k<32;k++)
							{
								fprintf(fpf,"%d ",flag[k]);
							}fputs("\n",fpf);

							for(k=0;k<32;k++)
							{
								flag[k]=0;
							}
							
						}						

					       if(reg[reg_val]>imm_val)
						{
							i++;
						}

						else if(reg[reg_val]<imm_val)
						{
							i=i+2;
							flag[1]=1;
							fputs("Negative flag up  ",fpf);
							for(k=0;k<32;k++)
							{
								fprintf(fpf,"%d ",flag[k]);
							}fputs("\n",fpf);

							for(k=0;k<32;k++)
							{
								flag[k]=0;
							}
						}


						for(k=0;k<16;k++)
						{
							fprintf(fpf,"reg[%d]=%d \n",k,reg[k]);
						}fputs("\n",fpf);		
					}

					else
					{
						if(strlen(code[j])==27)
						{
							for(k=27;k<32;k++)
							{
								int tempo = (int) (store[i][k] - '0');
								
								line= line + ( powe( 2,(4 - ( k-27 )) ) * tempo );
								
							}
							
							if(program==0)
							{
								i=line-3;
							}

							else if(program==1)
							{
								i=line-2; 
							}

							line=0;
						}
						
						else
						{	
							solve(oper[j],store[i],code[j]);
							
						}
					}
				}
			}
		}
		
		
	}
				
	fclose(ft);
	fclose(fp);
	fclose(fpop);
	fclose(fpreg);
	fclose(fpf);

	return 0;
}

	

