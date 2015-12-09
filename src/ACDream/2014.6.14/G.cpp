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

char a[1010][1010];
int b[1010][1010];
int main()
{
	ios::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	
		int sx,sy;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			cin>>a[i][j];
		}
	/*	for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			cout<<a[i][j];
			cout<<endl;
		}*/
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(a[i][j]=='T')
				{
					sx=i;sy=j;
				}
			}
		}
		int dirx[4]={-1,0,1,0},diry[4]={0,1,0,-1};
		int dirt,maxx=0,sum;
		int k=1;
		for(int i=0;i<4;i++)
		{
			memset(b,0,sizeof(b));
			dirt=i;
			sum=0;
			int x=sx,y=sy;
		//	cout<<k++<<":----"<<endl;
			while(x>=0&&x<n&&y>=0&&y<m)
			{
				if(a[x][y]=='*')break;
				if(a[x][y]=='E')
				{
					sum++;
					a[x][y]='e';
				}
				if(a[x][y]=='/')
				{
					b[x][y]++;
					if(b[x][y]>30)break;
					if(dirt==0)dirt=1;
					else if(dirt==1)dirt=0;
					else if(dirt==2)dirt=3;
					else if(dirt==3)dirt=2;
				}
				if(a[x][y]=='\\')
				{
					if(dirt==0)dirt=3;
					else if(dirt==1)dirt=2;
					else if(dirt==2)dirt=1;
					else if(dirt==3)dirt=0;
				}
				x+=dirx[dirt];
				y+=diry[dirt];
			//	cout<<x<<"  "<<y<<endl;
			}
			maxx=max(maxx,sum);
			for(int mm=0;mm<n;mm++)
			{
				for(int nn=0;nn<m;nn++)
				{
					if(a[mm][nn]=='e')a[mm][nn]='E';
				}
			}
		}
		cout<<maxx<<endl;
	
			
			
				
					
					
	 
	return 0;
}

