//#####################
//Author:fraud
//Blog: http://www.cnblogs.com/fraud/
//#####################
//#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>
using namespace std;
#define XINF INT_MAX
#define INF 0x3FFFFFFF
#define mp(X,Y) make_pair(X,Y)
#define pb(X) push_back(X)
#define rep(X,N) for(int X=0;X<N;X++)
#define rep2(X,L,R) for(int X=L;X<=R;X++)
#define dep(X,R,L) for(int X=R;X>=L;X--)
#define clr(A,X) memset(A,X,sizeof(A))
#define IT iterator
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;

map<long long,int>ms;
vector<long long>vs;
int main()
{
    ios::sync_with_stdio(false);
    #ifdef LOCAL
       // freopen("in.txt","r",stdin);
    #endif // LOCAL
    ll num = 1LL;
    vs.clear();
    ll temp;
    for(int i=1;i<64;i++){
        num = ((num<<1)|1LL);
        for(int j=0;j<i;j++){
            temp = (1LL << j)^num;
            if(temp>0)vs.pb(temp);
        }
    }
    //cout <<vs.size()<<endl;
    sort(vs.begin(),vs.end());
   // for(int i=0;i<vs.size();i++)cout <<vs[i]<<" ";
    ll a,b;
    while(cin>>a>>b){
        cout << upper_bound(vs.begin(),vs.end(),b) - lower_bound(vs.begin(),vs.end(),a)<<endl;
    }
    return 0;
}

