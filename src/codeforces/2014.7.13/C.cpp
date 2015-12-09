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
int n;
//int dp[100010],a[100010];
int dp[100010][2],a[100010];
int main()
{
	ios::sync_with_stdio(false);
	int ans=-1;
	int flag,index;
	while(cin>>n)
	{
		ans=-1;CLR(dp,0);
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
	//	a[0][0]=-INF;
		for(int i=0;i<n;i++)
		{
			dp[i][0]=1;
			for(int j=0;j<i;j++)
			{
				if(a[i]>a[j])
				{
					if(dp[j][1]==1)
					{
						if(dp[j][0]+1>dp[i][0])
						{
							dp[i][0]=dp[j][0]+1;
							dp[i][1]=1;
						}
					}
					else if(((i-j)>1)&&((a[i]-a[j])>1)&&(dp[j][1]==0))
					{
					//	cout<<i-j<<"  "<<a[i]-a[j]<<"   "<<endl;
					//	cout<<"ok"<<endl;
						if(dp[j][0]+2>dp[i][0])
						{
							dp[i][0]=dp[j][0]+2;
							dp[i][1]=1;
						}
					}
					else
					{
					//	cout<<"ok1"<<endl;
				//	cout<<dp[i][0]<<"  "<<dp[j][0]+1<<"  "<<dp[j][0]<<"  "<<j<<endl;
						if((dp[i][0]<=(dp[j][0]+1))&&dp[j][1]==0)
						{
							dp[i][0]=dp[j][0]+1;
							dp[i][1]=0;
						//	cout<<"ok"<<endl;
						}
					}
				}
				else if(dp[j][1]==0)
				{
				//	cout<<i<<"   "<<j<<endl;
					if(dp[j][0]+1>dp[i][0])
					{
						dp[i][0]=dp[j][0]+1;
						dp[i][1]=1;
					}
				}
			}
			if(dp[i][0]==1&&i!=0)
			{
				dp[i][0]=2;
				dp[i][1]=1;
			}
			ans=max(dp[i][0],ans);
		}
	/*	for(int i=0;i<n;i++)
		{
			for(int j=0;j<2;j++)
			{
				cout<<dp[i][j]<<" ";
			}
			cout<<endl;
		}*/
		cout<<ans<<endl;
	}
	return 0;
}


