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
ll dp[10010];
int a[4]={10,20,50,100};
int main()
{
	ios::sync_with_stdio(false);
    dp[0]=1;

    int n;
    while(cin>>n){
        int ans = 0;
        for(int i=0;i*10<=n;i++){
            for(int j=0;i*10+j*20<=n;j++){
                for(int k =0;i*10+j*20+k*50<=n;k++){
                    if((n-i*10-j*20-k*50)%100==0)ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
	return 0;
}



