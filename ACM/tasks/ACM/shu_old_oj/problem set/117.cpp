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
int n,k=1,num;
	queue <int > que;
int main()
{
	ios::sync_with_stdio(false);
	
	while(cin>>n)
	{
		cout<<"Case "<<k++<<": "<<endl;
		que.push(1);
	//	cout<<"   "<<setw(6)<<1<<endl;
		for(int i=1;i<n+2;i++)
		{
			for(int j=0;j<n+1-i;j++)
			{
			//	if(j<n-i)
				cout<<"   ";
			//	else cout<<"  ";
			}
			
			for(int j=0;j<i+1;j++)
			{
				if(j==0||j==i)
				{	
					que.push(1);
				//	cout<<"PS1";
				}
				else 
				{
					num=que.front();
					cout<<setw(6)<<num;
					que.pop();
					que.push(num+que.front());
				}	
			}
			if(i)
			{
				cout<<setw(6)<<que.front();
				que.pop();
				cout<<endl;
			}
			
		}
		while(!que.empty())
		{
			que.pop();
		}
	}
	return 0;
}

