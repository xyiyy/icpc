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
const int maxn=30;
int equ,var;
int a[maxn][maxn];//增广矩阵 
int x[maxn];//解集
int free_x[maxn];//存储自由变元
int free_num;//自由变元个数
int guass()
{
	int max_r,col,k;
	free_num=0;
	for(k=0,col=0;k<equ&&col<var;k++,col++)
	{
		max_r=k;
		for(int i=k+1;i<equ;i++)
		{
			if(abs(a[i][col])>abs(a[max_r][col]))
			{
				max_r=i;
			}
		}
		if(a[max_r][col]==0)
		{
			k--;
			free_x[free_num++]=col;
			continue;
		}
		if(max_r!=k)
		{
			for(int j=col;j<var+1;j++)
			{
				swap(a[k][j],a[max_r][j]);
			}
		}
		for(int i=k+1;i<equ;i++)
		{
			if(a[i][col]!=0)
			{
				for(int j=col;j<var+1;j++)
				{
					a[i][j]^=a[k][j];
				}
			}
		}
	}
	for(int i=k;i<equ;i++)
	{
		if(a[i][col]!=0)
		{
			return -1;
		}
	}
	if(k<var)return var-k;
	for(int i=var-1;i>=0;i--)
	{
		x[i]=a[i][var];
		for(int j=i+1;j<var;j++)
		{
			x[i]^=(a[i][j]&&x[j]);
		}
	}
	return 0;
}
		
 
void init()
{
	CLR(a,0);
	CLR(x,0);
	equ=20;
	var=20;
	for(int i=0;i<20;i++)
	{
		a[i][i]=1;
		if(i>0)a[i-1][i]=1;
		if(i<19)a[i+1][i]=1;
	}
}
void solve()
{
	int t=guass();
	if(t==-1)
	{
		cout<<"inf"<<endl;
	}
	else if(t==0)
	{
		int ans=0;
		for(int i=0;i<20;i++)
		{
			ans+=x[i];
		}
		cout<<ans<<endl;
		return ;
	}
	else
	{
		int ans=INF;
		int tot=(1<<t);
		for(int i=0;i<tot;i++)
		{
			int cnt=0;
			for(int j=0;j<t;j++)
			{
				if(i&(1<<j))
				{
					x[free_x[j]]=1;
					cnt++;
				}
				else x[free_x[j]]=0;
			}
			for(int j=var-t-1;j>=0;j--)
			{
				int idx;
				for(idx=j;idx<var;idx++)
				{
					if(a[j][idx])
						break;
				}
				x[idx]=a[j][var];
				for(int l=idx+1;l<var;l++)
				{
					if(a[j][l])
						x[idx]^=x[l];
				}
				cnt+=x[idx];
			}
			ans=min(ans,cnt);
		}
		cout<<ans<<endl;
	}
}
	
		
	
int main()
{
	ios::sync_with_stdio(false);
	init();
	for(int i=0;i<20;i++)
	{
		cin>>a[i][20];
	}
	solve();	
	return 0;
}


