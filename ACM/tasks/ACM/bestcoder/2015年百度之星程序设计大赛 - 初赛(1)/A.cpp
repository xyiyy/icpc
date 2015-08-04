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
ll n,m,k;
ll a[100010];
bool gao(){
    int lx =-1;
    int x;
    while(1){
        x = lower_bound(a,a+n,m)-a;
        if(x==n)return 1;
        if(a[x]>m)x--;
        if(x<=lx)break;
        lx=x;
        if(a[x]+k>m)m=a[x]+k;
        if(k>0)k--;
        if(m>=a[n-1])return 1;
    }
    return 0;
}
int main()
{
	ios::sync_with_stdio(false);
    int t;
    cin>>t;
    int cas=1;
    while(t--){

        scanf("%I64d%I64d%I64d",&n,&m,&k);
        for(int i=0;i<n;i++){
            scanf("%I64d",&a[i]);
        }
        sort(a,a+n);
        bool flag=1;
        if(m<a[0])flag=0;
        else flag = gao();


        cout<<"Case #"<<cas++<<":"<<endl;
        if(flag){
            cout<<"why am I so diao?"<<endl;
        }else{
            cout<<"madan!"<<endl;
        }
    }
	return 0;
}


