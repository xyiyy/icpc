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


set<int>aaa,bbb,vis;
const int maxn=0x7ffffff;
ll minn=0x7ffffff;
int a[50010],b[50010];
int fla,res;
int cir[maxn];
bool ccc[maxn];

void dfs(const int i,const int pos)
{
	ccc[fla]=a[pos];
	if(vis.find(a[pos])==vis.end())
	{
		vis.insert(a[pos]);
	}
	else
	{
		ll temp=cir[fla];
		ll minm=cir[fla];
		ll cnt=1;
		fla--;
		while(cir[fla]!=a[pos]&&fla>0)
		{
			set<int> :: iterator it =vis.find(cir[fla]);
			vis.erase(it);
			minm=min(minm,(ll)cir[fla]);
			temp+=cir[fla];
			cnt++;
			fla--;
		}
		if(cnt>1)
		{
			res+=temp+min(minm*(cnt-2),minn*(cnt+1)+minm);
		}
		return ;
	}
	int next=b[pos];
	set<PII>::iterator it=aaa.lower_bound(MP(next,-1));
	while(it!=aaa.end())
	{
		int nex=it->second;
		ccc[nex]=true;
		aaa.earse(it);
		fla++;
		dfs(i+1,nex);
		if(i>=fla)return ;
		it=aaa.lower_bound(MP(next,-1));
	}
}
		
		
		

int main()
{
	ios::sync_with_stdio(false);
	int n,k=1;
	while(cin>>n&&n)
	{
		cout<<"Case "<<K++<<": ";
		res=0;
		memset(ccc,flase,sizeof(ccc));
		minm=maxn;
		vis.clear();
		aaa.clear();
		bbb.clear();
		
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			aaa.inset(MP(a[i],i))
			minn=min(a[i],minn);
		}
		for(int i=0;i<n;i++)
		{
			cin>>b[i];
			bbb.inset(MP(a[i],i));
		}
		for(int i=0;i<n;i++)
		{
			if(!ccc[i])
			{
				fla=0;
				vis.clear;
				ccc[i]=1;
				dfs(0,i);
			}
		}
		cout<<res<<endl;	
	}
	return 0;
}


