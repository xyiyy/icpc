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
#define MAXN 200100
int A[MAXN*4];


int main()
{
	ios::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	int t=1<<n;
	for(int i=0;i<t;i++)cin>>A[i+t];
	for(int i=n;i>0;i--){
		int l=1<<(i-1),r=1<<(i);
		if((n-i)&1){
			while(l<r){
				A[l]=A[l<<1]^A[l<<1|1];
				l++;
			}
		}else{
			while(l<r){
				A[l]=A[l<<1]|A[l<<1|1];
				l++;
			}
		}
	}
	int u,v,x;
	for(int i=0;i<m;i++){
		cin>>u>>v;
		u+=(1<<n)-1;
		x=1;
		A[u]=v;
		u>>=1;
		while(u){
			if(x){
				A[u]=A[u<<1]|A[u<<1|1];
			}else{
				A[u]=A[u<<1]^A[u<<1|1];
			}
			u>>=1;
			x^=1;
		}
		cout<<A[1]<<endl;
	}
	return 0;
}



