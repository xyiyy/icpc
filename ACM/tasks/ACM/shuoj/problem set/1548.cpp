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

int vis[2010];
int k[2010];
int f[2010];
int main()
{
	ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int l,n;
        cin>>l>>n;
        for(int i=0;i<n;i++)cin>>k[i],vis[k[i]]++;;
        for(int i=0;i<n;i++)cin>>f[i];
        int sum=0;
        for(int i=0;i<n;i++)sum+=max(f[i]-k[i],0);
        int ans = INF;
        int num = 0;
        int p = 0;
        int temp = sum;
        for(int i=0;i<=l;i++){
            temp = 0;
            for(int j=0;j<n;j++){
                temp += max(f[j]-abs(k[j]-i),0);
            }
            if(temp < ans){
                p = i;
                ans = temp;
            }
        }
        cout<<p<<" "<<ans<<endl;
    }
	return 0;
}


