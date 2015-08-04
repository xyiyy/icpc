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
int Scan()
{
	int res, ch=0;
	while(!(ch>='0'&&ch<='9')) ch=getchar();
	res=ch-'0';
	while((ch=getchar())>='0'&&ch<='9')
		res=res*10+ch-'0';
	return res;
}
void Out(int a)
{
    if(a>9)
        Out(a/10);
    putchar(a%10+'0');
}
int h[100100];
int q[100100];
int p[100100];
int px[100100];
int ans[100100];
bool cmp(int x,int y){
	if(q[x]==q[y])return x<y;
	return q[x]<q[y];
}
bool cmp1(int x,int y){
	return h[x]<h[y];
}
int main()
{
	//ios::sync_with_stdio(false);
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		h[n+1]=-1;h[0]=-1;
		for(int i=1;i<=n;i++)h[i]=Scan();
		for(int i=1;i<=n;i++)px[i]=i;
		sort(px+1,px+n+1,cmp1);
		for(int i=1;i<=m;i++)q[i]=Scan();
		for(int i=1;i<=m;i++)p[i]=i;
		sort(p+1,p+m+1,cmp); 
		int j=1;
		//for(int i=1;i<=n;i++){
		//	if(h[i]<=q[p[0]])h[i]=-1;
		//}
		//int cs=0;
		//for(int i=)
		ans[0]=1;
		p[0]=0;
	//	for(int i=1;i<=n)
		for(int i=1;i<=m;i++){
			ans[p[i]]=ans[p[i-1]];
			while(j<=n&&h[px[j]]<=q[p[i]]){
				h[px[j]]=-1;
				if(h[px[j]-1]==-1&&h[px[j]+1]==-1)ans[p[i]]--;
				else if(h[px[j]-1]>0&&h[px[j]+1]>0)ans[p[i]]++;
			//	cout<<j<<"  "<<ans[p[i]]<<endl;
				j++;
			}
		//	cout<<i<<endl;
		}
		for(int i=1;i<=m;i++){
			printf("%d\n",ans[i]);
		}
	/*	int j=0;
		for(int i=0;i<n;i++){
			if(h[i]<=q[p[0]]){
				h[i]=-1;
			}
		}
		int cs=0;
		for(int i=0;i<n;i++){
			if(i==0&&h[i]!=-1)cs++;
			else if(i==0);
			else if(h[i]>0&&h[i-1]==-1)cs++;
		}
		ans[p[0]]=cs;
		while(j<n&&h[px[j]]<=q[p[0]])j++;
		for(int i=1;i<m;i++){
			ans[p[i]]=ans[p[i-1]];
			int beg=j;
			while(j<n&&h[px[j]]<=q[p[i]]){
				if(px[j]==0){
					if(h[1]<0)ans[p[i]]--;
				}else if(px[j]==)
				*/
	}
	return 0;
}



