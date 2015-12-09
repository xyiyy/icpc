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
int a[200010];
int main()
{
	ios::sync_with_stdio(false);
	int n,l,x,y;
	while(cin>>n>>l>>x>>y)
	{
		bool flag=0,flag1=0;
		int b,temp,temp1;
		int ans=INF;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			//a[i]-=a[0];
			if(x==a[i])flag=1;
			if(y==a[i])flag1=1;
			if(!flag)
			{
				temp=*lower_bound(a,a+i,a[i]-x);
				if(temp==a[i]-x)flag=1;
			//	temp=*lower_bound(a,a+i,x-a[i]);
			//	cout<<i<<" "<<temp<<endl;
			}
			if(!flag1)
			{
				temp=*lower_bound(a,a+i,a[i]-y);
				if(temp==a[i]-y)flag1=1;
			//	cout<<i<<"      "<<temp<<endl;
			}
			temp=*lower_bound(a,a+i,a[i]-y);
			temp1=*lower_bound(a,a+i,temp+x);
			if(temp!=a[i]-y&&temp1==a[i]-y+x&&a[i]-y>=0)
			{
				//flag=1;
				//flag1=1;
				ans=1,b=temp;
			}
		//	if(temp>=0)
		//			ans=1,b=temp;
			//temp=*lower_bound(a,a+i,a[i]-y);
			temp=*lower_bound(a,a+i,a[i]-y-x);
			temp1=*lower_bound(a,a+i,a[i]-x);
			if(temp==a[i]-x-y&&a[i]-x-y>=0&&temp1!=a[i]-x)
			{
				ans=1,b=temp1;
			//	flag=1;
			//	flag1=1;
			}
			temp=*lower_bound(a,a+i,a[i]-y-x);
			temp1=*lower_bound(a,a+i,a[i]-y);
			if(temp==a[i]-x-y&&a[i]-x-y>=0&&temp1!=a[i]-y)
			{
				ans=1,b=temp1;
			//	flag=1;
			//	flag1=1;
			}
		//	if(temp>=0)
		//			ans=1,b=temp;
		}
		for(int i=0;i<n;i++)
		{
			temp=*lower_bound(a,a+n,a[i]+y);
			temp1=*lower_bound(a,a+n,temp-x);
			if(temp!=a[i]+y&&temp1==a[i]+y-x&&a[i]+y<=l)
			{
				//flag=1;
				//flag1=1;
				ans=1,b=temp;
			}
		}
		if(flag&&flag1)cout<<0<<endl;
		else 
		{
			if(ans==1)
			{
				cout<<1<<endl;
				cout<<b<<endl;
			}
			else 
			{
		//		cout<<"ok"<<endl;
				if((!flag1)&&(!flag))
				{
					cout<<2<<endl;
					cout<<x<<" "<<y<<endl;
				}
				else if(flag)
				{
					cout<<1<<endl;
					cout<<y<<endl;
				}
				else
				{
					cout<<1<<endl;
					cout<<x<<endl;
				}
			}
		}
	/*	int ans=2-flag-flag1;

			
		vector<int> v;
		if(ans==1)
		{
			if(flag==0)
			{
				if(a[0]+x<=l)v.PB(a[0]+x);
				else if(a[n-1]-x>=0)v.PB(a[n-1]-x);
				else {
					v.PB(0);
					v.PB(x);
				}
			}
			else
			{
				if(a[0]+y<=l)v.PB(a[0]+y);
				else if(a[n-1]-y>=0)v.PB(a[n-1]-y);
				else {
					v.PB(0);
					v.PB(y);
				}
			}
		}
		else if(ans==2)
		{
			if((a[0]+x<=l||a[n-1]-x>=0)&&(a[0]+y<=l||a[n-1]-y>=0))
			{
				if(a[0]+x<=l)v.PB(a[0]+x);
				else if(a[n-1]-x>=0)v.PB(a[n-1]-x);
				if(a[0]+y<=l)v.PB(a[0]+y);
				else if(a[n-1]-y>=0)v.PB(a[n-1]-y);
			}
			else
			{
				v.PB(0);
				v.PB(x);
				v.PB(y);
			}
		}
		ans=v.size();
		cout<<ans<<endl;
		//sort(v,v+ans);
		for(int i=0;i<ans;i++)
		{
			cout<<v[i]<<" ";
		}*/
		//if(!flag)cout<<x+a[0]<<" ";
		//if(!flag1)cout<<y+a[0]<<" ";
		//if(ans)cout<<endl;
	}
	return 0;
}



