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
//	freopen("C.in","r",stdin);
	int ax1,ay1,ax2,ay2,bx1,by1,bx2,by2;
	while(cin>>ax1>>ay1>>ax2>>ay2>>bx1>>by1>>bx2>>by2)
	{
	//	int a1,d1,a2,d2;
		if(ax1>by1&&ay2>bx2&&(ax1>by2&&ay2>bx1)||(ax2>by1&&ay1>bx2&&ax2>by2&&ay1>bx1))
		{
			cout<<"Team 1"<<endl;
		}
		else
		{
			if((ax1<by1&&ay2<bx2||(ax1<by2&&ay2<bx1))&&(ax2<by1&&ay1<bx2||(ax2<by2&&ay1<bx1)))
			{
				cout<<"Team 2"<<endl;
			}
			else
			{
				cout<<"Draw"<<endl;
			}
		}
				
		/*if(ax1>by1&&ay2>bx2&&(ax1>by2&&ay2>bx1)||(ax2>by1&&ay1>bx2&&ax2>by2&&ay1>bx1))
		{
			cout<<"Team 1"<<endl;
		}
		else if(ax1<by1&&ay2<bx2&&(ax2<by1&&ay1<bx2)||(ax1<by2&&ay2<bx1&&ax2<by2&&ay1<bx1))
		{
			cout<<"Team 2"<<endl;
		}
		else 
		{
			cout<<"Draw"<<endl;
		}*/
	}
	return 0;
}

