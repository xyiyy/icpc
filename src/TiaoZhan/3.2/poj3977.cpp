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
typedef pair<ll,int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;
ll ll_abs(ll x)
{
	return x>=0?x:-x;
}
ll number[36];
int main()
{
	ios::sync_with_stdio(false);
	int n;
	while(cin>>n&&n)
	{
		for(int i=0;i<n;i++)
		{
			cin>>number[i];
		}
		map<ll,int>dp;
		PII res(ll_abs(number[0]),1);
		for(int i=0;i<1<<(n/2);i++)
		{
			ll sum=0;
			int num=0;
			for(int j=0;j<(n/2);j++)
			{
				if((i>>j)&1)
				{
					sum+=number[j];
					num++;
				}
			}
			if(num==0)continue;
			res=min(res,MP(ll_abs(sum),num));
			map<ll,int>::IT it=dp.find(sum);
			if(it!=dp.end())
			{
				it->second=min(it->second,num);
			}
			else
			{
				dp[sum]=num;
			}
		}
		for(int i=0;i<1<<(n-n/2);i++)
		{
			ll sum=0;
			int num=0;
			for(int j=0;j<n-n/2;j++)
			{
				if((i>>j)&1)
				{
					sum+=number[n/2+j];
					num++;
				}
			}
			if(num==0)continue;
			res=min(res,MP(ll_abs(sum),num));
			map<ll,int>::IT it=dp.lower_bound(-sum);
			if(it!=dp.end())
			{
				res=min(res,MP(ll_abs(sum+it->first),num+it->second));
			}
			if(it!=dp.begin())
			{
				it--;
				res=min(res,MP(ll_abs(sum+it->first),num+it->second));
			}
		}
		cout<<ll_abs(res.first)<<" "<<res.second<<endl;
	}
	
	return 0;
}


