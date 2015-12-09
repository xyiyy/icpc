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
int num[100010];
map<int,int>m;
map<int,int>m1;
int temp[100010];
int main()
{
	ios::sync_with_stdio(false);
	int n,a,b;
	cin>>n>>a>>b;
	for(int i=0;i<n;i++)
	{
		cin>>num[i];
		m.insert(MP(num[i],i));
	//	temp[i]=
	}
	sort(num,num+n);
	num[n]=INF;
	int x,y;
	bool flag=1;
	int size=0;
	//cout<<num[n-1]<<endl;
	if(num[n-1]>=max(a,b))flag=0;
	for(int i=0;i<n;i++)
	{
		
	
	
	/*
	for(int i=0;i<n&&flag;i++)
	{
		if(2*num[i]==a||2*num[i]==b)
		{
			temp[size++]=num[i];
			continue;
		}
	//	if(a-num[i]<0)x=
		x=lower_bound(num,num+n,a-num[i])-num;
		y=lower_bound(num,num+n,b-num[i])-num;
		if(x>=n&&y>=n)
		{
			flag=0;
			break;
		}
		cout<<num[x]<<"  "<<num[y]<<endl;
		if(x<n&&num[x]==a-num[i]&&(!m1.count(m[num[x]])||(m1.count(m[num[x]])&&m1[m[num[x]]]==0)))
		{
			m1.insert(MP(m[num[i]],0));
			
			//else if(m1)
			//	m1.insert(MP(m[num[i]],0));
		//	m1[m[num[i]]]=0;
		}
		if(y<n&&num[y]==b-num[i]&&(!m1.count(m[num[y]])||(m1.count(m[num[y]])&&m1[m[num[y]]]==1)))//&&b-num[i]!=(a/2)*2)
		{
			m1.insert(MP(m[num[i]],1));
		//	else flag=0;
		//	m1.insert(MP(m[num[i]],1));
			//m1[m[num[i]]]=1;
		}
	//	else if(a-num[i]!=(b/2)*2||b-num[i]!=(a/2)*2)
	//	{
			
		else 
		{
			flag=0;
		}
	}
	for(int i=0;i<size;i++)
	{
		if(2*temp[i]==a)
		{
			x=lower_bound(temp,temp+size,b-temp[i])-temp;
			if(temp[x]==b-temp[i]&&m1[m[temp[x]]]==1)
			{
				m1.insert(MP(m[temp[i]],1));
				//m1[m[v[i]]]=1;
			}
			else 
			{
			//	flag=0;
				m1.insert(MP(m[temp[i]],0));
			//	m1[m[v[i]]]=0;
			}
		}
		else 
		{
			x=lower_bound(temp,temp+size,a-temp[i])-temp;
			if(temp[x]==a-temp[i]&&m1[m[temp[x]]]==0)
			{
				m1.insert(MP(m[temp[i]],0));
			//	m1[m[v[i]]]=0;
			}
			else 
			{
			//	flag=0;
				m1.insert(MP(m[temp[i]],1));
			//	m1[m[v[i]]]=1;
			}
		}
	}
	if(flag)
	{
		cout<<"YES"<<endl;
		for(int i=0;i<n;i++)
		{
			cout<<m1[i]<<" ";
		}
		cout<<endl;
	}
	else 
	{
		cout<<"NO"<<endl;
	}
	*/
	
	return 0;
}



