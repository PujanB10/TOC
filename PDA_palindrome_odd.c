//lab 8 :  pda implementation for palindrome(wcw^r)

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
    int i=0;
    char str[100],ch,chpop;
    printf("enter string\n");
    scanf("%s",str);
    while((ch=str[i])!='\0')
    {
        
        if(cs == 'A' && (ch=='a' || ch=='b'))
        {
        Push(ch);
        printf("%c pushed into Stack \n" ,ch);
        cs = 'A';
        }
        
        else if(cs =='A' && ch == 'c')
        {
        
          cs ='B';  
        }
        
        else if(cs =='B' )
        {
            
            if((ch == 'b' && S[tos]=='b') || (ch == 'a' && S[tos]=='a') )
            {
            chpop =  Pop(); 
            printf("Poped from Stack\n");
            }
           
        }
        
        
        i++;
    }
    
    if(tos == -1)
    {
     printf("Accepted!!!!");   
    }
    
    else
    {
     printf("Rejected!!!!");      
    }
    
    return 0;
}

