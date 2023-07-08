//Lab 10 : implementation of Turing machine for palindrome (even and odd)

#include<stdio.h>


void display();
char tape[100];

int main()
{
    int  flag =0 ;
    char ch,cs ='A';
    int i= 0 ;
	printf("Enter string\n");
    scanf("%s",tape);
    
    while(1)
    {
       
       ch = tape[i];
       
       if(cs=='A' && ch =='B')
       {
       	cs = 'A';
        i++;
       }
       else if(cs=='A' && ch =='a')
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
       
      else if((cs=='B' && ch == 'B') || (cs=='B' && ch=='Y'))
       {
          cs='C';
          i--;
       }
        else if(cs=='C' && ch =='a')
       {
          tape[i] = 'Y';
          cs='D';
          i--;
       }
      else if(cs=='D' && (ch =='a' || ch =='b'))
       {
          cs='D';
          i--;
       }
       
        else if(cs=='D' && ch =='X')
       {
          cs='A';
          i++;
       }
       
       
      else if(cs=='A' && ch =='b')
       {
          tape[i] = 'X';
          cs='E';
          i++;
       }
      else if(cs=='E' && (ch =='a' || ch =='b'))
       {
          cs='E';
          i++;
       }
       
     else if(cs=='E' && (ch =='B' || ch=='Y'))
       {
          cs='F';
          i--;
       }
     else if(cs=='F' && ch =='b')
       {
          tape[i] = 'Y';
          cs='D';
          i--;
       }
       
      else if((cs=='A' && ch =='Y') )
       {
         flag = 1;
         break;
       }
       else if((cs=='C' && ch =='X') || (cs=='F' && ch =='X') )
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


void display()
{
	int j;
    for (j = 0; j < 100; j++) {
        printf("%c" ,tape[j]);
    }
     
}

