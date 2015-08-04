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
int fish[maxn],dis[maxn],ans[maxn],tem[maxn],time[maxn];
int ff[maxn];
int main()
{
	ios::sync_with_stdio(false);
	int n,h,cas=0,t;
	while(cin>>n&&n)
	{
		cin>>h;
		h*=60;
		REP(i,n)
			cin>>fish[i];
		REP(i,n)
			cin>>dis[i];
		time[0]=0;
		REP2(i,1,n-1)
		{
			cin>>t;
			time[i]=time[i-1]+t*5;
		}
		CLR(ans,0);
		int maxx=-1;
		REP(i,n)
		{
			int sum=0,le_t=h-time[i];
			REP2(j,0,i)
				ff[j]=fish[j];
			CLR(tem,0);
			while(le_t>0)
			{
				int maxx1=0,id=0;
				REP2(j,0,i)
					if(ff[j]>maxx1)
					{
						maxx1=ff[j];
						id=j;
					}
				if(maxx1==0)break;
				sum+=maxx1;
				tem[id]+=5;
				ff[id]-=dis[id];
				le_t-=5;
			}
			if(le_t>0)
				tem[0]+=le_t;
			if(sum>maxx)
			{
				maxx=sum;
				REP2(j,0,i)
					ans[j]=tem[j];
			}
		}
		if(cas>0)cout<<endl;
		REP(i,n)
		{
			if(i)cout<<", ";
			cout<<ans[i];
		}
		cout<<endl;
		cout<<"Number of fish expected: "<<maxx<<endl;
		cas++;
	}
			
		
	return 0;
}


