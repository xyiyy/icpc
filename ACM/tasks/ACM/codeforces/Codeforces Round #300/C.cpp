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
int a[100010],b[100010];
int main()
{
	ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    int ans=0;
    cin>>a[0]>>b[0];
    ans=b[0];
    if(a[0]!=1){
        ans=a[0]+b[0]-1;
    }
    bool flag=0;
    for(int i=1;i<m;i++){
        cin>>a[i]>>b[i];
        int d=a[i]-a[i-1]-1;
        int temp=d-abs(b[i]-b[i-1]);

        if(abs(b[i]-b[i-1])>a[i]-a[i-1])flag=1;
        else ans=max(ans,(temp+1)/2+max(b[i],b[i-1]));

    }
    int d=n-a[m-1];
    ans=max(ans,b[m-1]+d);
    if(flag)cout<<"IMPOSSIBLE"<<endl;
    else cout<<ans<<endl;

	return 0;
}



