#include<stdio.h>   
#include<string.h>   
#include<iostream>   
using namespace std;   
int main()   
{   
    char ch[10006];   
    int i,len,h,a,p,y;   
    while(gets(ch))   
    {   
        len=strlen(ch);   
        if(len==0)   
            break;   
        h=a=p=y=0;   
        for(i=0;i<len;i++)   
        {   
            switch(ch[i])   
            {   
            case 'h':   
                h++;   
                break;   
            case 'a':   
              if(a<h)   
                a++;   
              break;   
            case 'p':   
              if(p<a<<1)   
                p++;   
              break;   
            case 'y':   
              if(y<p>>1)   
                y++;   
              break;   
            }   
        }   
        printf("%d\n",y);   
    }   
}
 
