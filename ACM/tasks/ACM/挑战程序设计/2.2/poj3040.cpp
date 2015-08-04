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
int n,c;
ll ans;
struct key
{
	int v,num;
	bool operator<(const key &b)const 
	{
		return v<b.v;
	}
}money[20];
int use[20];
int main()
{
	ios::sync_with_stdio(false);
	while(cin>>n>>c)
	{
		ans=0;
		for(int i=0;i<n;i++)
		{
			cin>>money[i].v>>money[i].num;
		}
		sort(money,money+n);
		for(int i=0;i<n;i++)
		{
			if(money[i].v>=c)ans+=money[i].num,money[i].num=0;
		}
		while(1)
		{
			int flag=0;
			int temp=c;
			CLR(use,0);
			for(int j=n-1;j>=0;j--)
			{
				if(money[j].num)
				{
					int k=temp/money[j].v;
					int minn=min(money[j].num,k);
					temp-=minn*money[j].v;
					use[j]=minn;
					if(temp<=0)
					{
						flag=1;
						break;
					}
				}
			}
			if(temp>0)
			{
				for(int j=0;j<n;j++)
				{
					if(money[j].num>use[j])
					{
						while(use[j]<money[j].num)
						{
							temp-=money[j].v;
							use[j]++;
							if(temp<=0)
							{
								flag=1;
								break;
							}
						}
						if(temp<=0)break;
					}
				}
			}
			if(!flag)break;
			int mx=INF;
			for(int i=n-1;i>=0;i--)
			{
				if(use[i])mx=min(mx,money[i].num/use[i]);
			}
			ans+=mx;
			for(int i=n-1;i>=0;i--)
			{
				if(use[i])money[i].num-=mx*use[i];
			}
		}
		cout<<ans<<endl;
	}
				
				
					
		
		

	return 0;
}


