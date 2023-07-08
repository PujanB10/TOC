//Lab 16 : implementation of storage in state Turing machine that accepts String (ab*  + ba*)

#include<stdio.h>
#include<conio.h>
#define MAX 100

char tape[MAX];
struct state
{
	char cs;
	char a;
};

void display()
{
	int j;
    for (j = 0; j < MAX ; j++) {
        printf("%c" ,tape[j]);
    }     
}

int main()
{
	int  flag = 0 ;
   struct state q0;
      q0.cs = 'A';
      q0.a = 'B';
   char ch;
    int i= 1 ;
	printf("Enter string\n");
    scanf("%s",tape);
    
    while(1)
    {
    	
    	
    	 ch = tape[i];
    	if(q0.cs == 'A' && q0.a== 'B'  && ch =='a')
       {
          q0.cs = 'A';
          q0.a = 'a';
          i++;
       }     
       
       else if(q0.cs == 'A' && q0.a == 'a'  && ch =='b')
       {
        i++;
       }
		else if(q0.cs == 'A' && q0.a == 'a'  && ch =='B')
       {
          flag = 1;
          break;
       }
       else if(q0.cs == 'A' && q0.a == 'B'  && ch =='b')
       {
          q0.cs = 'A';
          q0.a = 'b';
          i++;
       }     
       
       else if(q0.cs == 'A' && q0.a == 'b'  && ch =='a')
       {
        i++;
       }
		else if(q0.cs == 'A' && q0.a == 'b'  && ch =='B')
       {
          flag = 1;
          break;
       }
       
       
       else
       {
       	break;
	   }    
	display();
   
    printf("\n");	
		
	}
	
    if(flag == 1)
    {
     printf("Accepted\n");  
    }
    else
    {
     printf("Rejected\n");    
    }
    
	return 0;
}



