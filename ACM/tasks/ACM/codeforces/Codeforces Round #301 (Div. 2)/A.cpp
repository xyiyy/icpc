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
string s1,s2;
int main()
{
	ios::sync_with_stdio(false);
    int n;
    cin>>n;
    cin>>s1>>s2;
    int ans=0;
    for(int i=0;i<n;i++){
        int l=s1[i]-'0';
        int r=s2[i]-'0';
        ans+=min(abs((l+10)-r),min(abs(l-(r+10)),abs(l-r)));
    }
    cout<<ans<<endl;;
	return 0;
}


