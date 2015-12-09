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
using namespace std;
#define XINF INT_MAX
#define INF 0x3FFFFFFF
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X,N) for(int X=0;X<N;X++)
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long ll;
char a[151][41];
char b[151][41];
int e[151];
int n,l;
int numa1[151];
int numb1[151];
int change[151];
int time;
bool flag;
bool flag1;
int num;
int id[151];
int lllen;
void check()
{
	memset(e,0,sizeof(e));
	flag1=1;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(!e[j])
			{
				if(!strcmp(a[j],b[i]))
				{
					e[j]=1;
					break;
				}
				else continue;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		if(e[i]==0)flag1=0;
	}
}
void dfs(int x)
{
	//if(!flag1)
	//cout<<x<<endl;
	if(x>=lllen)return;
	check();
	if(flag1)
	{
		return;
	}
	if(!flag1)
	dfs(x+1);
	if(flag1)return;

		for(int j=0;j<n;j++)
		{
			if(b[j][id[x]]=='0')b[j][id[x]]='1';
			else if(b[j][id[x]]=='1')b[j][id[x]]='0';
		}
		num++;
	
	if(!flag1)
	dfs(x+1);
	if(flag1)return;
	
		num--;
		for(int j=0;j<n;j++)
		{
			if(b[j][id[x]]=='0')b[j][id[x]]='1';
			else if(b[j][id[x]]=='1')b[j][id[x]]='0';
		}
	
}
	

int main()
{
	ios::sync_with_stdio(false);
	freopen("A-small-attempt1.in","r",stdin);
	freopen("Asmall.out","w",stdout);
	int T;
	cin>>T;
	int k=1;
	while(T--)
	{
		memset(b,'\0',sizeof(b));
		memset(a,'\0',sizeof(a));
		memset(numa1,0,sizeof(numa1));
		memset(numb1,0,sizeof(numb1));
		memset(change,0,sizeof(change));
		flag=true;
		num=0;
		flag1=0;
		cin>>n>>l;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<l;j++)
			{
				cin>>a[i][j];
			}
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<l;j++)
			{
				cin>>b[i][j];
			}
			
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<l;j++)
			{
				if(a[i][j]=='1')numa1[j]++;
				if(b[i][j]=='1')numb1[j]++;
			}
		}
		for(int i=0;i<l;i++)
		{
			if(numa1[i]==numb1[i])change[i]=1;
			else if(numa1[i]+numb1[i]==n)
			{
				change[i]=0;
				num++;
			}
			else 
			{	
				flag=0;break;
			}
		}
		if(flag)
		{
			for(int i=0;i<l;i++)
			{
				if(!change[i])
				{
					for(int j=0;j<n;j++)
					{
						if(b[j][i]=='0')b[j][i]='1';
						else if(b[j][i]=='1')b[j][i]='0';
					}
				}
			}
			lllen=0;
			memset(id,0,sizeof(id));
			for(int i=0;i<l;i++)
			{
				if(change[i])id[lllen++]=i;
			}
			dfs(0);
		//	check();
		}
		cout<<"Case #"<<k++<<": ";
		if(flag&&flag1)
		{cout<<num<<endl;
	}
		else cout<<"NOT POSSIBLE"<<endl;
	
		
		
		
	}
	return 0;
}

