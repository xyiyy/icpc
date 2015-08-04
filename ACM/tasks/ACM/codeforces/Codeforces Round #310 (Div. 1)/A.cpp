
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

int num[100010];
int a[100010];
int main()
{
	ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    ll ans = n-1;
    for(int i=0;i<m;i++){
        cin>>num[i];
        for(int j=0;j<num[i];j++){
            cin>>a[j];
        }
        if(a[0]==1){
            for(int j=1;j<num[i];j++){
                if(a[j]==j+1){
                    ans--;
                }else{
                    ans+=num[i]-j;
                    break;
                }
            }
            continue;
        }
        ans += num[i]-1;
       // cout<<ans<<endl;

    }
    cout<<ans<<endl;

	return 0;
}


