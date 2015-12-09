#include<iostream>

using namespace std;  
int vis[30005];  
int max_fl;  
int  judge(int t)  
{  
    int i,j;  
    int num=0;         
    i=t/20+2;         
    while(i<=max_fl)   
    {  
        while(i<=max_fl&&!vis[i])       
        i++;  
        if(10*num+4*(i-1)>t)  
        return 0;               
        j=(t-10*num+20*i+4)/24;    
        i=(t-10*num+16*j+4)/20+1;  
        num++;                     
    }  
    return 1;  
}  
int main()  
{  
    int n,fl;  
    while(cin>>n,n)  
    {  
        max_fl=0;  
        for(int i=0;i<30005;i++)
        vis[i]=0;
        while(n--)  
        {  
        cin>>fl;  
        vis[fl]=1;  
        max_fl=max(max_fl,fl);  
        }  
        int low=0,high=20*(max_fl-1);  
        int mid;  
        while(low<=high)  
        {  
            mid=(low+high)>>1;  
            if(judge(mid))  
            high=mid-1;  
            else  
            low=mid+1;  
        }  
        cout<<low<<endl;  
    }  
    return 0;  
}  
