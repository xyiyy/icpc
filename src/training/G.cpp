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
string str;
int a[110];
int b[100010];
bool flag=0;
int n;
int tot;
int dfs(int d,int lx,int rx){
	if(d==n){
		flag=1;
		return 1;
	}
	int x;
	x=upper_bound(a,a+tot,lx-rx)-a;
	for(int i=x;i<tot;i++){
		if(a[i]==b[d-1])continue;
		b[d]=a[i];
		if(dfs(d+1,rx+a[i],lx)){
			return 1;
		}
	}
	return 0;
}
		
		
int main()
{
	ios::sync_with_stdio(false);
	cin>>str;
	cin>>n;
	tot=0;
	fill(a,a+110,INF);
	for(int i=0;i<str.length();i++)
		if(str[i]=='1')a[tot++]=i+1;
	ll lx=0,rx=0;
	int ans=0;
	int last=0;
	int i;
	int x=0;
	for(int i=0;i<tot;i++){
		b[0]=a[i];
		if(dfs(1,a[i],0))break;
	}
	if(flag){
		cout<<"YES"<<endl;
		for(int i=0;i<n;i++){
			if(i)cout<<" ";
			cout<<b[i];
		}
		cout<<endl;
	}
	else cout<<"NO"<<endl;
	
			
		
	
	return 0;
}



