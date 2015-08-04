#include <iostream>     
#include <fstream>     
#include <algorithm>     
#include <string>     
#include <set>     
#include <map>     
#include <queue>     
#include <utility>     
#include <stack>     
#include <list>     
#include <vector>     
#include <cstdio>     
#include <cstdlib>     
#include <cstring>     
#include <cmath>     
#include <ctime>     
#include <ctype.h>
#include <iomanip>
#include <stdio.h>
using namespace std;
int main()
{
 int s[1005];  
    char str[1005];  
    int i,j,sum,k,len;  
    while(scanf("%s",str)!=EOF)  
    {  
        len=strlen(str);  
        str[len]='5';  
        sum=0;  
        i=j=0;  
        while(str[i++]=='5');  
        for(i--;i<=len;++i)  
        {  
            if(i>0&&str[i]=='5'&&str[i-1]=='5') 
                continue;  
            if(str[i]!='5')  
                sum=sum*10+str[i]-'0';  
            else  
            {  
                s[j++]=sum;  
                sum=0;  
            }  
        }  
        sort(s,s+j);  
        for(i=0;i<j-1;i++)  
            printf("%d ",s[i]);  
        printf("%d\n",s[i]);  
    }  
    return 0;  
}  
