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
string dir[32010];
double pos[32010];
string name[32010];
int main()
{
	ios::sync_with_stdio(false);
	int n;
	double len,v;
	while(cin>>n&&n)
	{
		cin>>len>>v;
		for(int i=0;i<n;i++)
		{
			cin>>dir[i]>>pos[i]>>name[i];
		}
		double time=0;
		int index=0;
		for(int i=0;i<n;i++)
		{
			if(dir[i]=="p"||dir[i]=="P")
			{
				if((len-pos[i])/v>time+1e-6)
				{
					time=(len-pos[i])/v;
					index=i;
				}
			}
			else 
			{
				if(pos[i]/v>time+1e-6)
				{
					time=pos[i]/v;
					index=i;
				}
			}
		}
		int num=0;
		if(dir[index]=="p"||dir[index]=="P")
		{
			for(int i=index;i<n;i++)
			{
				if(dir[i]=="n"||dir[i]=="N")
				{
					num++;
				}
			}
		}
		else 
		{
			for(int i=index;i>=0;i--)
			{
				if(dir[i]=="p"||dir[i]=="P")
				{
					num--;
				}
			}
		}
		cout<<setw(13)<<fixed<<setprecision(2)<<(int(time*100))/100.0<<" "<<name[index+num]<<endl;
	}
	return 0;
}


