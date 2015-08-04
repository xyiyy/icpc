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
int a[10010];
bool b[10010];

int main()
{
	ios::sync_with_stdio(false);
	int n;
	while(cin>>n&&n)
	{
		memset(b,false,sizeof(b));
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		int c=1;
		int k=0;
		for(int i=0;i<n-1;i++)
		{
			k = abs(a[i]-a[i+1]);
        	if(k&&k<n&&!b[k])b[k]=true;
        	else
			{
        		c = 0;
            	break;
           }
       }
       if(c)
         cout<<"Jolly\n";
    	else	cout<<"Not jolly\n";
   }
   return 0;
}
	

