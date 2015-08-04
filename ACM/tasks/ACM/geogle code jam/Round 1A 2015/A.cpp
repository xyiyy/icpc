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
int a[100010];
int main()
{
	ios::sync_with_stdio(false);
	freopen("A-large.in","r",stdin);
	freopen("a.out","w",stdout);
    int t;
    cin>>t;
    int cas=1;
    while(t--){
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int tot=0;
        for(int i=1;i<n;i++){
            if(a[i]<a[i-1])tot+=a[i-1]-a[i];
        }
        int maxx=0;
        for(int i=1;i<n;i++){
            maxx=max(a[i-1]-a[i],maxx);
        }
        int ans=0;
        for(int i=1;i<n;i++){
            if(a[i-1]>maxx)ans+=maxx;
            else ans+=a[i-1];
        }
        cout<<"Case #"<<cas++<<": "<<tot<<" "<<ans<<endl;

    }

	return 0;
}


