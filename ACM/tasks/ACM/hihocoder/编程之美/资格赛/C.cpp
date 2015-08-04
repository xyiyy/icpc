#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdlib>
using namespace std;
typedef long long ll;
ll ax[1010],ay[1010];
ll bx[1010],by[1010];
ll cao1(ll a,ll b,ll x){
    return a*x*x-b*x;
}

int main(){
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    int cas=1;
    int n,m,a,b;
    while(t--){
        cin>>n>>m>>a>>b;
        ll l=1,r=n;
        ll tx=l;
        ll tot2=0;
        ll totx=0,toty=0;
        for(int i=0;i<a;i++){
            cin>>ax[i]>>ay[i];
            totx+=ax[i];
            toty+=ay[i];
            tot2+=ax[i]*ax[i]+ay[i]*ay[i];
        }
        for(int i=0;i<b;i++){
            cin>>bx[i]>>by[i];
        }
        l=1,r=n;
        ll minx=1LL<<62;
        totx<<=1;
        toty<<=1;
        if(cao1(a,totx,l)<cao1(a,totx,r))tx=l;
        else tx=r;
        minx=cao1(a,totx,tx);
        int fuc=0;
        while(l<=r&&fuc<1000){
            fuc++;
            ll ml=(l*2+r)/3;
            ll mr=(r*2+l)/3;
            ll t1=cao1(a,totx,ml);
            ll t2=cao1(a,totx,mr);
            if(t1>=t2){
                tx=mr;
                minx=min(minx,t2);
                l=ml;
            }else{
                tx=ml;
                minx=min(minx,t1);
                r=mr;
            }
        }
        l=1,r=m;
        ll ty=l;
        ll miny;
        if(cao1(a,toty,l)<cao1(a,toty,r))ty=l;
        else ty=r;
        miny=cao1(a,toty,ty);
        fuc=0;
        while(l<=r&&fuc<1000){
            fuc++;
            ll ml=(l*2+r)/3;
            ll mr=(r*2+l)/3;
            ll t1=cao1(a,toty,ml);
            ll t2=cao1(a,toty,mr);
            if(t1>=t2){
                tx=mr;
                miny=min(miny,t2);
                l=ml;
            }else{
                tx=ml;
                miny=min(miny,t1);
                r=mr;
            }
        }
        int nx,ny;
        ll ans=1LL<<62;
        for(int i=-50;i<=50;i++){
            nx=tx+i;
            if(nx<=0||nx>n)continue;
            for(int j=-50;j<=50;j++){
                ny=ty+j;
                if(ny<=0||ny>m)continue;
                for(int k=0;k<b;k++){
                    ans=min(ans,tot2+cao1(a,totx,nx)+cao1(a,toty,ny)+abs(bx[k]-nx)+abs(by[k]-ny));
                }

            }
        }
        cout<<"Case #"<<cas++<<": ";
        cout<<ans<<endl;
    }
    return 0;
}
