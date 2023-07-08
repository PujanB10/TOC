//Lab 15 : implementation of Turing machine for String (a^n b^n+1)

#include<stdio.h>
#include<conio.h>
#define MAX 100

char tape[MAX];

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
    char ch,cs ='A';
    int i= 1 ;
	printf("Enter string\n");
    scanf("%s",tape);
    
    while(1)
    {
    	
    	 ch = tape[i];
    	if(cs=='A' && ch =='a')
       {
          tape[i] = 'X';
          cs = 'B';
          i++;
       }     
       
       else if((cs=='B' && ch =='a') || (cs=='B' && ch =='b'))
       {
          cs='B';
          i++;
       }
		else if((cs=='B' && ch =='B') || (cs=='B' && ch =='Y'))
       {
          cs = 'C';
          i--;
       }
       
       else if(cs=='C' && ch =='b')
       {
          tape[i] = 'Y';
          cs = 'D';
          i--;
       }
			
		  else if((cs=='D' && ch =='a') || (cs=='D' && ch =='b'))
       {
          cs='D';
          i--;
       }
       
       
       else if(cs=='D' && ch =='X')
       {
          
          cs = 'A';
          i++;
       }
       
       
        else if(cs=='A' && ch =='b')
       {
          cs = 'F';
          i++;
       }
       
       else if(cs=='F' && ch =='Y')
       {
          flag =1 ;
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



