//#####################
//Author:fraud
//Blog: http://www.cnblogs.com/fraud/
//#####################
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
const double eps = 1e-6;
bool dfs(double a,int n,int step){
	if(step==n&&fabs(a-24)<eps)return 1;
	else if(step==n)return 0;
	for(int i=0;i<4;i++){
		if(i==0){
			if(dfs(a+n,n,step+1)){
                    cout<<i<<endl;
                    return 1;
			}
		}else if(i==1){
			if(dfs(a-n,n,step+1)){
                    cout<<i<<endl;
                    return 1;
			}
		}else if(i==2){
			if(dfs(a*n,n,step+1)){
                    cout<<i<<endl;
                    return 1;
			}
		}else if(dfs(a/n,n,step+1)){
		    cout<<i<<endl;
		    return 1;
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	int n = 5;
	//while(n){
		if(dfs((double)n,n,1))cout<<n<<endl;
	//}
	return 0;
}



