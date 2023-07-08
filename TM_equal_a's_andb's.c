//Lab 11 : implementation of Turing machine for String (equal no. of  a and b)

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
       
       else if(cs=='A' && ch =='Y')
       {
          cs = 'A';
          i++;
       }
       
       else if((cs=='B' && ch =='a') || (cs=='B' && ch =='Y'))
       {
          cs='B';
          i++;
       }
		else if(cs=='B' && ch =='b')
       {
          tape[i] = 'Y';
          cs = 'C';
          i--;
       }
			
		  else if((cs=='C' && ch =='a') || (cs=='C' && ch =='Y'))
       {
          cs='C';
          i--;
       }
       
       
       else if(cs=='C' && ch =='X')
       {
          
          cs = 'A';
          i++;
       }
       
       //starting from b
       
       else if(cs=='A' && ch =='b')
       {
          tape[i] = 'X';
          cs = 'E';
          i++;
       }
       
          
       else if((cs=='E' && ch =='b') || (cs=='E' && ch =='Y'))
       {
          cs='E';
          i++;
       }
		else if(cs=='E' && ch =='a')
       {
          tape[i] = 'Y';
          cs = 'D';
          i--;
       }
			
		  else if((cs=='D' && ch =='b') || (cs=='D' && ch =='Y'))
       {
          cs='D';
          i--;
       }
             
       else if(cs=='D' && ch =='X')
       {
          
          cs = 'A';
          i++;
       }
       
        else if(cs=='A' && ch =='B')
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



