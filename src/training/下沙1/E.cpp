
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
ll C[1010][1010];
const ll MOD  = 1000000007 ;
int main()
{
	ios::sync_with_stdio(false);
    int n,m,k;
    cin>>n>>m>>k;
    k=k*2;
    if(k>n-1||k>m-1){
        cout<<0<<endl;
        return 0;
    }
    //if()
    C[0][0]=1;
    for(int i=0;i<1010;i++){
        C[i][0]=C[i][i]=1;
        for(int j=1;j<i;j++){
            C[i][j]=C[i-1][j-1]+C[i-1][j];
            C[i][j]%=MOD;
        }
    }
    cout<<C[n-1][k]*C[m-1][k]%MOD<<endl;

	return 0;
}


