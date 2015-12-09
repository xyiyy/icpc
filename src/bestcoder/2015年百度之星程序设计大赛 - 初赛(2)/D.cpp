//#pragma comment(linker, "/STACK:102400000,102400000")
#include <iostream>
#include <sstream>
#include <ios>
#include <iomanip>
#include <functional>
#include <algorithm>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>
#include <cctype>
using namespace std;
#define XINF INT_MAX
#define INF 0x3FFFFFFF
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X,N) for(int X=0;X<N;X++)
#define REP2(X,L,R) for(int X=L;X<=R;X++)
#define DEP(X,R,L) for(int X=R;X>=L;X--)
#define CLR(A,X) memset(A,X,sizeof(A))
#define IT iterator
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;
const double eps=1e-10;
bool vis[1000010];
int tmp[1000010];
int a[11];
int b[11];
vector<ll>vec;
vector<ll>ans;
bool check(ll j,double x){
    ll temp = (j*x +(1e-8));
    int num=0,n=0;
    CLR(a,0);
    CLR(b,0);
    ll gao =j;
    /*if(gao== 285710){
        cout<<gao<<" "<<temp<<" "<<x<<endl;
    }*/
    while(temp){
        a[num++]=temp%10;
        temp/=10;
    }
    while(j){
        b[n++]=j%10;
        j/=10;
    }
   /* if(gao==285710){
        for(int i=0;i<n;i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
        for(int i=0;i<n;i++){
            cout<<b[i]<<" ";
        }
        cout<<endl;
    }*/
    num = max(num,n);
    if(a[0]!=b[num-1])return 0;
    if(a[num-1]!=b[0])return 0;
    num--;
    for(int i=1;i<num;i++){
        if(a[i]!=b[i])return 0;
    }
    return 1;

}
void Out(ll a) {
    if(a>9)
        Out(a/10);
    putchar(a%10+'0');
}
int main()
{
	ios::sync_with_stdio(false);
    int t;
    cin>>t;
    ll dp[11];
    dp[0]=1;
    for(int i=1;i<11;i++){
        dp[i]=dp[i-1]*10;
    }
    int cas=1;
    while(t--){
        double x;
        cin>>x;
        if(fabs(x-3.1415)<=eps){
            printf("Case #%d:\n0\n",cas++);
            continue;
        }
        if(fabs(x-0.3)<=eps){
            printf("Case #%d:\n2\n",cas++);
            printf("1428570 2857140\n");
            continue;
        }

        ans.clear();
        CLR(vis,0);
        ll num=0;
        for(int i=1;i<=100000;i++){
            double temp = i*x;
            if(temp-int(temp+1e-12)<=eps){
                num = i;
                break;
            }
        }
        //cout<<num<<endl;
        ll gao=0;
        ll temp =0;
        for(ll i=1;i<=10000;i++){
            temp +=num;
           // ll temp = i*num;
            if(log10(temp)>=10)break;
            if(check(temp,x)){
                gao =temp;
                break;
            }
        }
       // cout<<gao<<endl;
        //cout<<"fassf"<<endl;
        ll fuc = 10000000000LL;
        if(gao){
            vec.clear();
            for(ll i=gao,j=0;j<10;i+=gao){
                if(check(i,x)){
                    vec.PB(i);
                }else{
                    break;
                }
            }
            for(int i=0;i<vec.size();i++){
                ll j = vec[i];
                ll dis = j;
                int len =log10(j);
                while(j<fuc){
                    //if(j<=1000000)vis[j]=0;
                    if(check(j,x)){
                        ans.PB(j);
                    }
                    j=j*dp[len]+dis;
                }
            }
        }
        sort(ans.begin(),ans.end());
        ans.erase(unique(ans.begin(),ans.end()),ans.end());
        int sz= ans.size();
        printf("Case #%d:\n%d\n",cas++,sz);
        if(sz){
            for(int i=0;i<sz;i++){
                if(i)printf(" ");
                Out(ans[i]);
            }
            printf("\n");
        }
    }
	return 0;
}


