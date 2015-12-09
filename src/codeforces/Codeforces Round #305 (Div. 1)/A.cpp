#include <iostream>
#include <cstring >
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long ll;
ll MOD;
#define MAXN 1000010
int num[MAXN];
ll tx1,ty1,tx2,ty2;
ll g1,g2;
void extgcd(ll a,ll b,ll &d,ll &x,ll &y){
    if(!b){
        d=a;x=1;y=0;
    }else{
        extgcd(b,a%b,d,y,x);
        y-=x*(a/b);
    }
}
ll cal(ll s1,ll s2,ll p1,ll p2,ll len1 , ll len2){
    if(p1==-1||p2== -1)return -1;
    if(p1<s1&&p2<s2){
        if(p1==p2)return p2;
        else return -1;
    }
    if(p1<s1&&p2>=s2){
        int now =p2;
        ll temp= g2;
        while(now <p1){
            temp = (temp*tx2+ty2)%MOD;
            now ++;
        }
        if(temp==g2)return p1;
        else return -1;

    }
    if(p1>=s1&&p2<s2){
        int now = p1;
        ll temp=g1;
        while(now <p2){
            temp = (temp*tx1+ty1)%MOD;
            now++;
        }
        if(temp == g1)return p2;
        else return -1;
    }
    ll x,y,d;
    //cout<<"gao"<<endl;
    d= p2-p1;
    if(d==0){
        return p1;
    }
    //ll t = ((abs(d)+min(len1,len2)-1)/min(len1,len2));
    //if(d<0)d+=t*min(len1,len2);
    //cout<<len1<<" "<<len2<<" "<<d<<endl;
    //if(len1%d!=0||len2%d!=0){
    //    return -1;
    //}else{
        extgcd(len1/d,len2/d,d,x,y);
        return len1%d==0&&len2%d==0 ? len2*x+p2 : -1;//+t*min(len1,len2);
    //}

}
int main(){
    cin>>MOD;
    for(int i=0;i<MOD ;i++)num[i]=-1;
    ll h,a,x,y;
    cin>>h>>a>>x>>y;
    int now=0;
    while(num[h]==-1){
        num[h]=now++;
        h=(x*h+y)%MOD;
    }
    int len1=now-num[h];
    int p1 = num[a];
    int s1 = num[h];
    tx1=x,ty1=y;
    g1=a;
    cin>>h>>a>>x>>y;
    tx2=x,ty2=y;
    g2= a;
    for(int i=0;i<MOD;i++){
        num[i]=-1;
    }
    now = 0;
    while(num[h]==-1){
        num[h]=now++;
        h=(x*h+y)%MOD;
    }
    int len2= now -num[h];
    int p2=num[a];
    int s2=num[h];
    //cout<<s1<<" "<<s2<<" "<<p1<<" "<<p2<<" "<<len1<<" "<<len2<<endl;
    cout << cal(s1,s2,p1,p2,len1,len2)<<endl;
    return 0;
}
