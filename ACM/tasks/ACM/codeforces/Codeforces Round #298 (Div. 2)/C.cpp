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
ll a[200010];
int main()
{
	ios::sync_with_stdio(false);
    int n;
    ll s;
    cin>>n>>s;
    ll tot=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        tot+=a[i];
    }
    ll minn=n-1,maxx=0;
    for(int i=0;i<n;i++){
        maxx=tot-a[i];

        if(maxx<s){
            if(minn+a[i]>=s)cout<<s-maxx-1+minn+a[i]-s<<" ";
            else cout<<(s-maxx-1)<<" ";
        }else if(maxx-s>a[i]){
            if(n-1+a[i]<=s)
                cout<<0<<" ";
            else {
                cout<<a[i]+minn-s<<" ";
            }
        }else {
            if(n-1+a[i]<=s){
                cout<<0<<" ";
            }else cout<<a[i]+minn-s<<" ";
        }
    }
    cout<<endl;

	return 0;
}



