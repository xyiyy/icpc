#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
#define MAXN 100010
int T[MAXN*4];

int main(){
    //ios::sync_with_stdio(false);
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        int t=1;
       // for(int i=0;i<MAXN;i++)T[i]=0;
        while(t<=n+2)t<<=1;
        memset(T,0,sizeof(T));
        for(int i=1;i<=n;i++){
            scanf("%d",T+t+i);
        }
        for(int tmp=t-1;tmp;tmp--)T[tmp]=T[tmp<<1]+T[tmp<<1|1];
        int x,y,z,ans;
        while(m--){
            scanf("%d%d%d",&x,&y,&z);
            if(x==1){
                y+=t;
                T[y]+=z;
                for(y>>=1;y;y>>=1)T[y]=T[y<<1]+T[y<<1|1];
            }else{
                ans=0;
                for(y+=t-1,z+=t+1;y^z^1;y>>=1,z>>=1){
                    if(~y&1)ans+=T[y+1];
                    if(z&1)ans+=T[z-1];
                }
                printf("%d\n",ans);
            }
        }
    }
    return 0;
}
