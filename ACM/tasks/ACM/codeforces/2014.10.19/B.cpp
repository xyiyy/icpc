//gaoshenbaoyou  ------ pass system test
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
int a[1010];
priority_queue<PII,vector<PII>,less<PII> >q1;
priority_queue<PII,vector<PII>,greater<PII> >q2;
queue<PII> q;
int main()
{
	ios::sync_with_stdio(false);
	int n,k;
	while(cin>>n>>k)
	{
		while(!q1.empty())q1.pop();
		while(!q2.empty())q2.pop();
		while(!q.empty())q.pop();
		int sum=0;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			sum+=a[i];
	//		q1.push(a[i]);
		}
	//	cout<<q1.top()<<endl;
		int sum2=sum;
		sum2/=n;
		sum=(sum+n-1)/n;
		for(int i=0;i<n;i++)
		{
			if(a[i]>=sum)q1.push(MP(a[i],i));
			if(a[i]<=sum2)q2.push(MP(a[i],i));
		}
		//cout<<q1.top().first<<"  "<<q2.top().first<<endl;
		PII x,y;
		x=q1.top();
		y=q2.top();
		int temp,temp2;
		int t=0;
		//cout<<sum<<" "<<sum2<<endl;
		while(t<k&&((x.first)!=sum||(y.first)!=sum2))
		{
			t++;
			q1.pop();
			q2.pop();
			temp=1;
		//	temp2=sum2-y.first;
		//	temp=x.first-sum;
		//	cout<<temp<<" "<<temp2<<endl;
		//	temp=min(temp,temp2);
		//	cout<<temp<<endl;
		//	if(x.first==sum||y.first==sum2)temp=1;
			x.first-=temp;
			y.first+=temp;
			if(x.first>=sum)q1.push(x);
			if(y.first<=sum2)q2.push(y);
			q.push(MP(x.second,y.second));
			if(!q1.empty())
			x=q1.top();
			if(!q2.empty())
			y=q2.top();
		}
	//	cout<<sum<<" "<<sum2<<endl;
		int l,r;
		if(q1.empty())r=sum;
		else r=q1.top().first;
		if(q2.empty())l=sum2;
		else l=q2.top().first;
		cout<<r-l<<" "<<t<<endl;
		for(int i=0;i<t;i++)
		{
			x=q.front();
			q.pop();
			cout<<x.first+1<<" "<<x.second+1<<endl;
		}
	}
	return 0;
}



