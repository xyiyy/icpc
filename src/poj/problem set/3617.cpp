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
char a[2010]; 
char b[2010];

int main()
{
	ios::sync_with_stdio(false);
	int N;
//	int mm=0;
	while(cin>>N)
	{
		memset(a,'\0',sizeof(a));
		memset(b,'\0',sizeof(b));
		REP(i,N)
		{
			cin>>a[i];
		}
		int num=0;
		int i=0,n=N-1;
		int flag=0;
		while(num<=N-1)
		{
			//num++;
			if(a[i]<a[n])
			{ 
				flag=-1;
			//	i++;
			}
			else if(a[n]<a[i])
			{
				flag=1;
				//n--;
			}
			else
			{
				for(int j=0;j<n;j++)
				{
					if(a[i+j]<a[n-j])
					{
						flag=-1;
						break;
					}
					else if(a[i+j]>a[n-j])
					{
						flag=1;
						break;
					}
					else continue;
				}
			}
			if(flag==-1)
			{	
				b[num]=a[i];
				i++;
			}
			else if(flag==1)
			{
				b[num]=a[n];
				n--;
			}
		//	cout<<b[num]<<endl;
			num++;
		}
		num=0;
		for(int i=0;i<N;i++)
		{
			cout<<b[i];
			num++;
			if(num==80)
			{
				cout<<endl;
				num=0;
			}
		}
		if(num!=0)cout<<endl;
			
	
	}
	return 0;
}

