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
int a[100];
int G[110][110];
int main()
{
	ios::sync_with_stdio(false);
    //freopen("B-small-attempt1.in","r",stdin);
	//freopen("b.out","w",stdout);
	int t;
	cin>>t;
	int cas=1;
	while(t--){
        int r,c,n;
        cin>>r>>c>>n;
        cout<<"Case #"<<cas++<<": ";
        if(n<=(r*c+1)/2){
            cout<<0<<endl;
            continue;
        }
        if(r<c)swap(r,c);
        if(n<=(r+1)/2*c+r/2){
            int temp=n-(r*c+1)/2;
            if()
        }
        cout<<ans<<endl;
	}
	return 0;
}



