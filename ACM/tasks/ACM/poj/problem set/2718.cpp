#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;
int a[20],b[20],vis[20];
int n,ans;

void solve(int sum1)
{
    int num=0;
    int sum2=0;
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            b[num++]=a[i];
            sum2=sum2*10+a[i];
        }
    }
    //cout<<"sum1="<<sum1<<" sum2="<<sum2<<endl;
    if((b[0]!=0)||(b[0]==0&&num==1)) ans=min(ans,abs(sum1-sum2));
    while(next_permutation(b,b+num))
    {
        if(b[0]==0) continue;
        sum2=0;
        for(int i=0;i<num;i++) sum2=sum2*10+b[i];
        ans=min(ans,abs(sum1-sum2));
    }
    //cout<<"sum1="<<sum1<<" sum2="<<sum2<<endl;
}

void dfs(int res,int sum)
{
    if(res>n/2)
    {
        solve(sum);
        return;
    }
    for(int i=0;i<n;i++)
    {
        if(res==1&&a[i]==0) continue;
        //cout<<"i="<<i<<endl;
        if(vis[i]) continue;
        vis[i]=1;
        dfs(res+1,sum*10+a[i]);
        vis[i]=0;
    }
}

int main()
{
    int T;
    char str[20];
    scanf("%d",&T);
    getchar();
    while(T--)
    {
        n=0;ans=1e9;
        memset(vis,0,sizeof(vis));
        gets(str);
        int len=strlen(str);
        for(int i=0;i<len;i+=2) a[n++]=str[i]-'0';
        //for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<endl;
        dfs(1,0);
        printf("%d\n",ans);
    }
    return 0;
}
