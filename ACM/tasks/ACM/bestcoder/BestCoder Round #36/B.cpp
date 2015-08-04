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

int a[1000100];
int b[1000100];
int h[1000100];
int p[1000100];
int ans[1000100];
bool cmp(int x,int y){
	if(h[x]==h[y])return x<y;
	return h[x]<h[y];
}
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


int main()
{
	ios::sync_with_stdio(false);
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		for(int i=0;i<n;i++)
			a[i]=Scan();
		sort(a,a+n);
		b[0]++;
		int tot=0;
		for(int i=1;i<n;i++){
			if(a[i]==a[i-1])b[tot]++;
			else b[++tot]=1;
		}
		//cout<<tot<<endl;
		//for(int i=0;i<tot;i++)cout<<b[i]<<endl;
		for(int i=0;i<m;i++)h[i]=Scan();
		for(int i=0;i<m;i++)p[i]=i;
		sort(p,p+m,cmp);
		//for(int i=0;i<m;i++)cout<<h[p[i]]<<endl;
		int j=0;
		int k=0;
		for(int i=0;i<m;i++){
			if(j>=n)break;
			while(a[j]<h[p[i]]){
				j++;
				if(j>=n)break;
				if(a[j]!=a[j-1])k++;
			}
		//	cout<<j<<endl;
		//	cout<<k<<endl;
			if(j>=n)break;
			if(h[p[i]]==a[j]){
				ans[p[i]]=b[k];
				b[k]=0;
			}
		}
		for(int i=0;i<m;i++){
			Out(ans[i]);
			puts("");
		}
	}
			
				
		
			
			
	return 0;
}



