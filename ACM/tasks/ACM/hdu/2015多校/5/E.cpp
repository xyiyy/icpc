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
double f[100]= {1312.0,2372.0,520.2,899.5,800.6,
				1086.5,1402.3,1313.9,1681.0,2080.7,
				495.8,737.7,577.5,786.5,1011.8,
				999.6,1251.2,1520.6,418.8,589.8,
				633.1,658.8,650.9,652.9,717.3,
				762.5,760.4,737.1,745.5,906.4,
				578.8,762,947,941,1139.9,
				1350.8,403,549.5,600,640.1,
				652.1,684.3,702,710.2,719.7,
				804.4,731.0,867.8,558.3,708.6,
				834,869.3,1008.4,1170.4,375.7};
double gao(int x){
	if(x==85)return 890;
	if(x==86)return 1037;
	return f[x-1];
}
int main()
{
	ios::sync_with_stdio(false);
	int a,b;
	double p,q;
	while(scanf("%d%d",&a,&b)!=EOF){
		p = gao(a);n
		q = gao(b);
		if(p>q)printf("FIRST BIGGER\n");
		else printf("SECOND BIGGER\n");
	}
	return 0;
}



