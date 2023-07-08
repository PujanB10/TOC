//lab 7 :  pda implementation for a^n b^2n 


#include<stdio.h>
#include<string.h>

 char S[100]; // stack
  int tos = -1;

void Push(char ch)
{    
  tos = tos+1;
  S[tos] = ch;
}

char Pop()
{
  char ch ;
  ch = S[tos];
  tos = tos-1;  
    
}

int main()
{
    char cs ='A';
    int i= 0,flag = 1;
    char str[100],ch,chpop;
    printf("enter string\n");
    scanf("%s",str);
    while((ch=str[i])!='\0')
    {     
       
        if(cs == 'A' && ch =='a')
        {
        Push(ch);
        printf("a pushed into Stack \n");
        cs = 'A';
        }
        
       else if(cs =='A' && ch == 'b')
        {
        printf("Just read b \n");
          cs ='B';  
        }
        
        else if(cs =='B' && ch == 'b')
        {
            
            if(S[tos]=='a')
            {
            chpop =  Pop(); 
            printf("b Poped from Stack\n",chpop);
            cs ='C';
            }
            else
            {
            	break;
			}
           
        }
        
       else if(cs =='C' && ch == 'b')
        {            
          printf("Just read b \n");
          cs ='B';  
           
        }
        
        else
        {
        	flag = 0;
		}
        
        
        i++;
    }
    
    if(flag=1 && tos == -1 && i == strlen(str) )
    {
     printf("Accepted!!!!");   
    }
    
    else
    {
     printf("Rejected!!!!");      
    }
    
    return 0;
}

