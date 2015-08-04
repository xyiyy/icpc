#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int a[1010];
int dp[1010];
int main(){
    ios::sync_with_stdio(false);
    int t;
    //freopen("B-large.in","r",stdin);
    //freopen("b.out","w",stdout);
    cin>>t;
    int cas=1;
    while(t--){
        int n;
        cin>>n;
        int u;
        for(int i=0;i<n;i++)cin>>a[i];
        int ans=1000;
        int tmp;
        for(int i=1;i<1001;i++){
                tmp =0;
            for(int j=0;j<n;j++){
                tmp+=(a[j]+i-1)/i-1;
            }
            ans=min(tmp+i,ans);
        }
        cout<<"Case #"<<cas++<<": ";
        cout<<ans<<endl;
        /*for(int i=0;i<1010;i++)a[i]=0;

        int ans=0;
        for(int i=0;i<n;i++){
            cin>>u;
            a[u]++;
            ans=max(ans,u);
        }
        int l=0,r=ans;
        int ans=0;
        int maxx=r;
        int tmp=0;
        while(l<=r){
            int mid=(l+r)>>1;
            tmp=0;
            int fuc=0;
            for(int i=0;i<1010;i++){
                if(i>mid){
                    tmp+=(i+mid-1)/mid*a[u];
                }else fuc=i;
            }
            bool flag=0;
            for(int i=tot;i<mid;i++){
                flag=1;
                for(int j=fuc+1;j<maxx;)
                if(flag)break;
            }

        }*/

    }
    return 0;
}

