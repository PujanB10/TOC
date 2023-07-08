//lab 9 :pda implementation for a^n c b^n 


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
    int flag =1;
    int i= 0;
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
        
        else if(cs == 'A' && ch =='c')
        {
         cs = 'B';
        }
        else if(cs =='B' && ch == 'b')
        {
            
            if(S[tos]=='a')
            {
            chpop =  Pop(); 
            printf("b Poped from Stack\n",chpop);
            cs ='B';
            }
            else
            {
            break;	
			}
           
        }
        else
		{
		flag = 0;	
		}    
          
        i++;
    }
    
    if(flag == 1 && tos == -1 && i == strlen(str))
    {
     printf("Accepted!!!!");   
    }
    
    else
    {
     printf("Rejected!!!!");      
    }
    
    return 0;
}

