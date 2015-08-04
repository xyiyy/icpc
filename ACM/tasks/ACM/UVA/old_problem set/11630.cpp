//#####################
//Author:fraud
//Blog: http://www.cnblogs.com/fraud/
//#####################
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
#define MAXN 1000010
int a[MAXN];
int main()
{
	int n;
	while(scanf("%d",&n)&&n){
		 a[1]=3;
		 a[2]=1;
		 for(int i=3;i<=n;i++){
		 	if(i&1)a[i]=i+2;
		 	else a[i]=i-2;
		 }
		 if(n&1)a[n]=n-1;
		 else{
		 	a[n]=n-2;
		 	a[n-1]=n;
		 }
		 printf("%d",a[1]);
		 for(int i=2;i<=n;i++){
		 	printf(" %d",a[i]);
		 }
		 printf("\n");
	}
	return 0;
}

