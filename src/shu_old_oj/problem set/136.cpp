#include <iostream>
#include <sstream>
#include <strstream>
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
const int N=10010;
char str[N];
int a[110][110];
int b[110][110];
int dirx[9]={-1,-1,-1,0,0,0,1,1,1};
int diry[9]={-1,0,1,-1,0,1,-1,0,1};
int main()
{
	ios::sync_with_stdio(false);
	int k=1,r=0,c;
	while(cin.getline(str,N,'\n'))
	{
		if(strlen(str)>0)
		{
			istrstream ss(str,N);
			c=0;
			while(ss>>a[r][c])
			{
				c++;
			}
			r++;
		}
		else 
		{
			CLR(b,0);
			REP(x,r)
			{
				REP(y,c)
				{
					REP(j,9)
					{
						if(x+dirx[j]<0||x+dirx[j]>=r||y+diry[j]<0||y+diry[j]>=c)
							continue;
						else 
						{
							b[x][y]+=a[x+dirx[j]][y+diry[j]];
						}
					}
				}
			}
			CLR(a,0);
			cout<<"Case "<<k++<<":"<<endl;
			REP(x,r)
			{
				REP(y,c-1)
				{
					cout<<b[x][y]<<" ";
				}
				cout<<b[x][c-1]<<endl;
			}
			r=0;
		}
	}
	CLR(b,0);
	REP(x,r)
	{
		REP(y,c)
		{
			REP(j,9)
			{
				if(x+dirx[j]<0||x+dirx[j]>=r||y+diry[j]<0||y+diry[j]>=c)
					continue;
				else 
				{
					b[x][y]+=a[x+dirx[j]][y+diry[j]];
				}
			}
		}
	}
	CLR(a,0);
	cout<<"Case "<<k++<<":"<<endl;
	REP(x,r)
	{
		REP(y,c-1)
		{
			cout<<b[x][y]<<" ";
		}
		cout<<b[x][c-1]<<endl;
	}
	r=0;
	return 0;
}

