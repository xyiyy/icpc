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

struct point 
{
	int x,y;
	bool operator<(const point &a)const
	{
		if (x!=a.x) return x<a.x;
 		return y<a.y;      
 	}
}d1[200],d2[2000];
 
int n,m,f[200][200];
ll tx,ty,gx,gy;


int main()
{
	int times=0;
	ios::sync_with_stdio(false);
	while(cin>>n>>m)
	{
		int i,j,k,ans=0;
		memset(f,0,sizeof(f));
		for(i=1;i<=n;i++)
		cin>>d1[i].x>>d1[i].y;
		for(i=1;i<=m;i++)
		cin>>d2[i].x>>d2[i].y;
		sort(d1+1,d1+1+n);
		for (i=1;i<n;i++)
  			for (j=i+1;j<=n;j++)
   				if (d1[i].x!=d1[j].x)
    				for (k=1;k<=m;k++)
     				{
     					if (d2[k].x<d1[i].x||d2[k].x>d1[j].x) continue;
     					tx=d2[k].x-d1[i].x;ty=d2[k].y-d1[i].y;
     					gx=d1[j].x-d1[i].x;gy=d1[j].y-d1[i].y;
     					if (gx*ty-tx*gy>0) f[i][j]++;     
     				}
 		for (i=1;i<n-1;i++)
  			for (j=i+1;j<n;j++)
   				for (k=j+1;k<=n;k++)
    				if (d1[i].x!=d1[k].x)
     				{
     					tx=d1[j].x-d1[i].x;ty=d1[j].y-d1[i].y;
     					gx=d1[k].x-d1[i].x;gx=d1[k].y-d1[i].y;
     					if (gx*ty-tx*gy>0)
      					{
      						if ((f[i][k]-f[i][j]-f[j][k])&1) ans++;
      						continue;     
      					}     
    					if ((f[i][j]+f[j][k]-f[i][k])&1) ans++;
     				}
		cout<<"Case "<<++times<<": "<<ans<<endl;
	}
	return 0;
}

