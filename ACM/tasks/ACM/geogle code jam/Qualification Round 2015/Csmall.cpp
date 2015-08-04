#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long ll;
int a[100010];
int b[100010];
int c[100010];
int fuc[4][4]={1,2,3,4,2,-1,4,-3,3,-4,-1,2,4,3,-2,-1};
int d[100010];
int e[100010];
int cao(int x,int y){
    int f=0;
    if(x<0)f++;
    if(y<0)f++;
    x=abs(x);
    y=abs(y);
    x--;
    y--;
    return fuc[x][y]*((f&1)==1?-1:1);
}
string str;
int main(){
    int t;
    int cas=1;
    freopen("C-large.in","r",stdin);
    freopen("clarge.out","w",stdout);
    cin>>t;
    while(t--){
        ll x,l;
        cin>>x>>l;
        cin>>str;
        ll len=str.length();
        for(int i=0;i<len;i++){
            if(str[i]=='i')a[i]=2;
            else if(str[i]=='j')a[i]=3;
            else if(str[i]=='k')a[i]=4;
        }
        b[0]=1;
        ll maxx=min(len*(ll)12,x*len);
        int f1=0,f2=0;
        for(int i=1;i<=maxx;i++){
            b[i]=cao(b[i-1],a[(i-1)%len]);
            if(b[i]==2)f1=1;
            if(f1&&b[i]==4){
                f2=1;
                break;
            }
        }
        b[0]=1;
        cout<<"Case #"<<cas++<<": ";
        if(!f2){
            cout<<"NO"<<endl;
            continue;
        }
        for(int i=1;i<=len;i++){
            b[i]=cao(b[i-1],a[i-1]);
        }
        int tmp=1;
        int t=0;
        l%=4;
        while(l){
            tmp=cao(tmp,b[len]);
            l--;
            t++;
        }
        if(tmp==-1)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;


    }
}
