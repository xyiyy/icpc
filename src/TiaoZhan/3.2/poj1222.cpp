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
int equ,var;
const int maxn=40;
int a[maxn][maxn];
int x[maxn];
int free_x[maxn];
int free_num;

int guass()
{
	int k,col,max_r;
	for(k=0,col=0;k<equ&&col<var;col++,k++)
	{
		max_r=k;
		for(int i=k+1;i<equ;i++)
		{
			if(abs(a[i][col])>abs(a[max_r][col]))
				max_r=i;
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
		if(a[i][col])return -1;
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
	equ=30;
	var=30;
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<6;j++)
		{
			int t=i*6+j;
			a[t][t]=1;
			if(i>0)a[(i-1)*6+j][t]=1;
			if(j>0)a[i*6+j-1][t]=1;
			if(i<4)a[(i+1)*6+j][t]=1;
			if(j<5)a[i*6+j+1][t]=1;
		}
	}
	
}

		
int main()
{
	ios::sync_with_stdio(false);
	int t;
	int cas=1;
	cin>>t;
	while(t--)
	{
		init();
		for(int i=0;i<5;i++)
		{
			for(int j=0;j<6;j++)
			{
				cin>>a[i*6+j][30];
			}
		}
		cout<<"PUZZLE #"<<cas++<<endl;
		guass();
		for(int i=0;i<5;i++)
		{
			for(int j=0;j<6;j++)
			{
				if(j)cout<<" ";
				cout<<x[i*6+j];
			}
			cout<<endl;
		}
	}	
	return 0;
}


