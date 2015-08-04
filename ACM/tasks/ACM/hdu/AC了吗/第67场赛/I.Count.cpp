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

const int length=10000;
int Matrix[length][length];

int main()
{
	ios::sync_with_stdio(false);
	int N,M;
	
	while(cin>>N>>M)
	{
	int i,j;
	memset(Matrix,0,sizeof(Matrix));
	for(i=0;i<N;i++)
	{
		for(j=0;j<M;j++)
		{
			cin>>Matrix[i][j];
		}
	}
//	for(int k=0;k<=i;k++)
//		sort(Matrix[],)
	int x,y;
	while (cin>>x>>y)
	{
		int num=0;
		for(int k=0;k<=i;k++)
		{
			for(int l=0;l<=j;l++)
			{
				if(Matrix[k][l]>=x&&Matrix[k][l]<=y)num++;
			}
			
		}
		cout<<num<<endl;
	} 
}
	
	return 0;
}


