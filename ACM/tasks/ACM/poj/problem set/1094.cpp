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
int m,n,tot,j,cnt,flag;

struct chart
{
	char c;
	chart *next;
}G[100];

int main()
{
	char aa,b,cc;
	ios::sync_with_stdio(false);
	while(cin>>m>>n&&m&&n)
	{
		cnt=0;
		for(int i=0;i<m;i++)
		{
			G[i].next=NULL;
		}
		for(int i=0;i<n;i++)
		{
			flag=0;
			cin>>aa>>b>>cc;
			G[int(aa-65)].c=cc;
			chart *ppp=new chart;
			
			//cout<<aa<<endl;	
			if(!flag)
			{
				cnt++;
			for(j=0;j<m;j++)
			{
				tot=0;
				chart *p=&G[j];
				while(p->next!=NULL)
				{
					p=p->next;tot++;
					if(tot>m)
					{
						flag=-1;
						break;
					}
				}
				cout<<tot;
				if(tot==m){flag=1;}
				if(flag)break;
			}
				//else if(tot>m)
			}
		}
		if(flag==1)
		{
			chart *p=&G[j];
			cout<<"Sorted sequence determined after "<<cnt<<" relations: ";
			while(p->next!=NULL)
			{
				cout<<p->c;
				p=p->next;
			}
			cout<<'.'<<endl;
		}
		if(flag==-1)
		{
			cout<<"Inconsistency found after "<<cnt<<" relations."<<endl;
		}
		if(flag==0)
		{
			cout<<"Sorted sequence cannot be determined."<<endl;
		}
	}
		
	

	return 0;
}

