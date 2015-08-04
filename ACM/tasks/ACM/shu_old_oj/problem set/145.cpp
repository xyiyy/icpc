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
int a[11100],b[11100];
int c[111100];
char d[100000];
int main()
{
	ios::sync_with_stdio(false);
	int cas=1;
	int i=0,j=0,k=0;
	int x,y;
	while(cin.getline(d,100000))
	{
		istrstream ss(d);
		i=0;j=0;
		while(ss>>a[i])i++;
		CLR(d,0);
		cin.getline(d,100000);
		istrstream s(d);
		while(s>>b[j])j++;
		k=0;
		CLR(d,0);
		x=0;y=0;
		while(k<i+j)
		{
			if(a[x]<=b[y]&&x<i)
			{
				c[k++]=a[x];
				x++;
			}
			else if(a[x]>b[y]&&y<j)
			{
				c[k++]=b[y];
				y++;
			}
			else if(i==x)
			{
				c[k++]=b[y];
				y++;
			}
			else if(j==y)
			{
				c[k++]=a[x];
				x++;
			}
			
		}
		cout<<"Case "<<cas++<<":";
		for(int m=0;m<i+j;m++)
		{
			cout<<" "<<c[m];
		}
		cout<<endl;
	}
	return 0;
}


