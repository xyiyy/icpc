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
double gao(double a,double b,double c){
	double c1 = sqrt(a*a+b*b+2.0*a*b*0.5);
	double sina = a / c1 * (sqrt(3.0)/2.0);
	double tmp = asin(sina);
	sina = sin(2.0/3*acos(-1.0)-tmp);
	//cout<<sina<<endl;
	double ret = (sqrt(3.0)/4)*a*b+ 0.5 *sina* c1*c;
	//cout<<ret<<endl;
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	int a1,a2,a3,a4,a5,a6;
	cin>>a1>>a2>>a3>>a4>>a5>>a6;
	double ans = 0;
	ans += gao(a1,a2,a3);
	ans += gao(a6,a5,a4);
	ans = ans/(sqrt(3.0)/4.0);
	//cout<<ans<<endl;
	int num = ans + 1e-3;
	cout<<num<<endl;
	//cout<<cos(60/180.0*acos(-1.0))<<endl;
	return 0;
}



