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
const int N=100010;
bool vis[N*10];
char a[N];
int b[N];
int main()
{
	ios::sync_with_stdio(false);
	int i,k=1,num;
	while(cin.getline(a,N))
	{
		istrstream ss(a,N);
		CLR(b,0);
		CLR(vis,0);
		i=0;
		while(ss>>num) 
		{
			if(!vis[num])
			{
				b[i]=num;
				vis[num]=1;
				i++;
			}
			
		}
		cout<<"Case "<<k++<<":";
		for(int j=0;j<i;j++)
		{
			cout<<" "<<b[j];
		}
		cout<<endl;
		CLR(a,'\0');
	}
	
		
		
	return 0;
}

