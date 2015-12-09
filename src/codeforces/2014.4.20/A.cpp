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
int a[110];
int b[110];

int main()
{
	ios::sync_with_stdio(false);
	int n,m,maxx,minn;
	while(cin>>n>>m>>minn>>maxx)
	{
		memset(a,0,sizeof(a));
		int max1=-0x7fff,min1=0x7fff;
		for(int i=0;i<m;i++)
		{
			cin>>a[i];
		
			if(a[i]<min1)min1=a[i];
			if(a[i]>max1)max1=a[i];
		}
		if(n==1)
		{
			if(minn==maxx&&m==n&&a[0]==minn)
			{
				cout<<"Correct"<<endl;
			}
			else 
			{
				cout<<"Incorrect"<<endl;
			}
		}
		else if(n==2)
		{
			if(m==1)
			{
				if(a[0]==minn||a[0]==maxx)
				{
					cout<<"Correct"<<endl;
				}
				else 
				{
					cout<<"Incorrect"<<endl;
				}
			}
			else if(m==2)
			{
				if((a[0]==minn&&a[1]==maxx)||(a[0]==maxx&&a[1]==minn))
				{
					cout<<"Correct"<<endl;
				}
				else 
				{
					cout<<"Incorrect"<<endl;
				}
			}
			else cout<<"Incorrect"<<endl;
		}
		else if(n>2)
		{
			if(n-m>=2)
			{
				if(min1>=minn&&max1<=maxx&&max1>=min1)
				{
					cout<<"Correct"<<endl;
				}
				else 
				{
					cout<<"Incorrect"<<endl;
				}
			}
			else if(n-m==1)
			{
				if((min1>=minn&&max1==maxx&&max1>=min1)||(min1==minn&&max1<=maxx&&max1>=min1))
				{
					cout<<"Correct"<<endl;
				}
				else 
				{
					cout<<"Incorrect"<<endl;
				}
			}
			else if(n-m==0)
			{
				if(min1==minn&&max1==maxx)
				{
					cout<<"Correct"<<endl;
				}
				else 
				{
					cout<<"Incorrect"<<endl;
				}
			}
					
			else cout<<"Incorrect"<<endl;
				
		}
	}
	return 0;
}

