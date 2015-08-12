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
int a,b,c;
int num[30];
int main()
{
	ios::sync_with_stdio(false);
	int n;
	while(cin>>n)
	{
		int x,y,z;
		bool flag=1;
		int sum=0;
		a=b=c=0;
		for(int i=0;i<n;i++)
		{
			cin>>x>>y>>z;
			num[i]=5*x+10*y+20*z;
			if(num[i]<15)flag=0;
			num[i]-=15;
			a+=x;b+=y;c+=z;
			//sum+=num[i];
		}
		if(!flag)cout<<"Angry Yaoge!"<<endl;
		else 
		{
			for(int i=0;i<n;i++)
			{
				x=min(c,num[i]/20);
				c-=x;
				num[i]-=x*20;
				y=min(b,num[i]/10);
				b-=y;
				num[i]-=y*10;
				z=min(a,num[i]/5);
				a-=z;
				num[i]-=z*5;
				if(num[i])
				{
					flag=0;
					break;
				}
				//cout<<a<<" "<<b<<" "<<c<<" "<<endl;
			}
			if(!flag)cout<<"Sad Yaoge!"<<endl;
			else cout<<"Happy Yaoge!"<<endl;
		}
	}
	return 0;
}



