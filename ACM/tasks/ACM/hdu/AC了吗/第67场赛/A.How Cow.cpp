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


int main()
{
	ios::sync_with_stdio(false);
	int T,M;
	int x1,y1,x2,y2,x,y;
	int k=1; 
	cin>>T;
	while(T--)
	{		
		cout<<"Case "<<k++<<":"<<endl;
		cin>>x1>>y1>>x2>>y2;
		cin>>M;
		while(M--)
		{
			cin>>x>>y;
			if(x>=x1&&x<=x2&&y>=y1&&y<=y2)cout<<"Yes"<<endl;
			else cout<<"No"<<endl;
		}
	}
			
		
	return 0;
}

