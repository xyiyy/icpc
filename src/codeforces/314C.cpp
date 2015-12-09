#include <iostream>
#include <cstdio>
using namespace std;
#define MAXN 1000010
#define MAXX 1000000
typedef long long ll;
const int MOD=1000000007;
int bit[MAXN],dp[MAXN];
int sum(int x){
    int s=0;
    while(x>0){
        s+=bit[x];
        if(s>=MOD)s-=MOD;
        x-=x&-x;
    }
    return s;
}
void add(int i,int x){
    while(i<=MAXX){
        bit[i]+=x;
        if(bit[i]>=MOD)bit[i]-=MOD;
        i+=i&-i;
    }
}
int main(){
    ios::sync_with_stdio(false);
    int n;
    scanf("%d",&n);
    int x;
    int t;
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        ll temp=(ll)sum(x)*x+x;
        //cout<<temp<<endl;
        temp%=MOD;
        add(x,(temp-dp[x]+MOD)%MOD);
        dp[x]=temp;
    }
    cout<<sum(MAXN-10)<<endl;
    return 0;
}
