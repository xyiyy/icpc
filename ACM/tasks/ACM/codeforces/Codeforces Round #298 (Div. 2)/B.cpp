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
int a[10010];
int b[10010];
int main()
{
	ios::sync_with_stdio(false);/*
    double v1,v2;
    double d,t;
    cin>>v1>>v2>>t>>d;
    if(d==0){
        cout<<v1*t<<endl;
        return 0;
    }
    double t1=(t*d+v2-v1)/2/d;
    double t2=t-t1;
    cout<<t1<<" "<<t2<<endl;
    double vt=(t1*d+v1);
    cout<<vt<<endl;
    double ans=(v1+vt)*t1/2+(v2+v2)*t2/2;
    cout<<ans<<endl;*/
    int v1,v2,d,t;
    cin>>v1>>v2>>t>>d;
    a[1]=v1;
    for(int i=2;i<=t;i++){
        a[i]=a[i-1]+d;
    }
    b[t]=v2;
    for(int i=t-1;i;i--){
        b[i]=b[i+1]+d;
    }
    int ans=0;
    for(int i=1;i<=t;i++){
        ans+=min(a[i],b[i]);
    }
    cout<<ans<<endl;
	return 0;
}



