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

char str[10005][50];
ll num1[26],num2[26];
int id[500050];
int ini;
int dic[500050][26];
int one[26];
int init()
{
	ini=1;
	CLR(dic[0],0);
	for(int i=0;i<26;i++)
	{
		id[i+'a']=i;
	}
}
ll sum1,sum2;
void insert1(int i)
{
	int u=0,first=1;
	int len=strlen(str[i]);
	for(int j=0;j<len;j++)
	{
		if(!dic[u][id[str[i][j]]])
		{
			CLR(dic[ini],0);
			sum1++;
			if(!first)
			{
				num1[id[str[i][j]]]++;
			}
			dic[u][id[str[i][j]]]=ini;
			ini++;
		}
		first=0;
		u=dic[u][id[str[i][j]]];
	}
}
void insert2(int i)
{
	int u=0,first=1;
	int len=strlen(str[i]);
	for(int j=0;j<len;j++)
	{
		if(!dic[u][id[str[i][j]]])
		{
			CLR(dic[ini],0);
			sum2++;
			if(!first)
			{
				num2[id[str[i][j]]]++;
			}
			dic[u][id[str[i][j]]]=ini;
			ini++;
		}
		first=0;
		u=dic[u][id[str[i][j]]];
	}
}

int main()
{
	ios::sync_with_stdio(false);
	int n,len;
	while(cin>>n)
	{
		CLR(num1,0);
		CLR(num2,0);
		init();
		CLR(one,0);
		sum1=0;sum2=0;
		for(int i=0;i<n;i++)
		{
			cin>>str[i];
			len=strlen(str[i]);	
			if(len==1)one[str[i][0]-'a']=1;
			insert1(i);
			for(int i=0;i<26;i++)
			{
				cout<<num1[i]<<" ";
			}
			cout<<endl;
		}
	
		cout<<endl;
		init();
		for(int i=0;i<n;i++)
		{
			len=strlen(str[i]);	
			reverse(str[i],str[i]+len);
			insert2(i);
			for(int i=0;i<26;i++)
			{
				cout<<num2[i]<<" ";
			}
			cout<<endl;
		}
		cout<<sum1<<"  "<<sum2<<endl;
		ll ans=sum1*sum2;
		
		for(int i=0;i<26;i++)
		{
			if(one[i])ans++;
			ans-=num1[i]*num2[i];
		}
		cout<<ans<<endl;
	}
		
	return 0;
}

