#include<iostream>  
#include<string.h>
using namespace std;  
 
int main(int i,int j)  
{  
    int N;   
    int cash;  
    while(cin>>cash>>N)  
    {  
        int* n=new int[N+1]; 
        int* w=new int[N+1];  
        int* c=new int[N+1];  
        int* dp=new int[cash+1];
        int* count=new int[cash+1];
  
        for(i=1;i<=N;i++)  
        {  
            cin>>n[i]>>w[i];  
            c[i]=w[i];  
        }  
        memset(dp,0,4*(cash+1));  
 
          
        for(i=1;i<=N;i++)  
        {  
            memset(count,0,4*(cash+1)); 
            for(j=w[i];j<=cash;j++)      
                if(dp[j]<dp[j-c[i]]+w[i] && count[j-c[i]]<n[i])
                {                                           
                    dp[j] = dp[j-c[i]]+w[i];   
                    count[j]=count[j-c[i]]+1;   
                }  
        } 
          
        cout<<dp[cash]<<endl;  
        delete n;  
        delete w;  
        delete c;  
        delete dp;  
        delete count;  
    }  
      
    return 0;  
}  

