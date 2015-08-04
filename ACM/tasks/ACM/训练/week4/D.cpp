#include <iostream>
#include <cstdio>
using namespace std;
int a[1010];
int b[1010];
int main(){
    ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    int x,y;
    for(int i = 0;i<m;i++){
        cin>>x>>y;
        x--;
        y--;
        a[x]=1;
        b[y]=1;
    }
    int ans=0;
    for(int i=1;i<n-1;i++){
        if(!a[i])ans++;
        if(!b[i])ans++;
    }
    if(n%2==1&&a[n/2]==0&&b[n/2]==0)ans--;
    ans=max(ans,0);
    cout<<ans<<endl;
    return 0;
}
