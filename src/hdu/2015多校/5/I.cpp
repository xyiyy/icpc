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
string str[110];
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	str[1] = "b";
	str[2] = "a";
	for(int i=3;i<20;i++)str[i] = str[i-1]+ str[i-2];
	while(t--){
		int n,m;
		cin>>n;
		int len = str[n].length();
		cout<<"#########  "<<n<<" ########"<<endl;
		cout<<str[n]<<endl;
		cout<<len<<endl;
		for(int i=1;i<=len;i++){
			int ans = 0;
			for(int j=1;j<i;j++){
				if(str[n].substr(0,j)==str[n].substr(i-j,j))ans = j;
			}
			cout<<i<<"  "<<ans<<endl;
		}
	}
	return 0;
}



