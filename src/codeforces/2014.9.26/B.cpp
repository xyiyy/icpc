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

int a[6];
int main()
{
	ios::sync_with_stdio(false);
	map<int ,int>m;
	while(cin>>a[0])
	{
		m.clear();
		m[a[0]]=1;
		for(int i=1;i<6;i++)
		{
			cin>>a[i];
			if(!m.count(a[i]))m[a[i]]=1;
			else m[a[i]]++;
		}
		map<int,int>::IT it;
		bool flag=0;
		int x,y;
		x=-1;
		y=-1;
		for(it=m.begin();it!=m.end();it++)
		{
			if(it->second>=4)
			{
				it->second-=4;
				flag=1;
			}
			//if(it->second>4)x=it->first;
			while(it->second>=1)
			{
				if(x==-1)
				{
					x=it->first;
				}
				else if(y==-1)
				{
					y=it->first;
				}
				it->second--;
			}
		//	else if(it->second>=2&&it->second<4)
		//	{
		//		x=it->first;
		//		y=it->first;
		//	}
		}
		if(flag)
		{
			if(x==y)
			{
				cout<<"Elephant"<<endl;
			}
			else
			{
				cout<<"Bear"<<endl;
			}
		}
		else
		{
			cout<<"Alien"<<endl;
		}
	}
			
	return 0;
}



