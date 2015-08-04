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
int box[7];
int a[4]={0,5,3,1};
int b[4]={0,7,6,5};
int main()
{
	ios::sync_with_stdio(false);
	int sum;//,flag;
	int maxx=0;
	while(cin>>box[1])
	{
		maxx=box[1];
		for(int i=2;i<7;i++)
		{
			cin>>box[i];
			maxx=max(maxx,box[i]);
		}
		if(maxx==0)break;
		
		//flag=0;
		sum=box[6]+box[5]+box[4]+(box[3]+3)/4;
		int num=box[4]*5+a[box[3]%4];
		if(num<box[2])
		{
			//flag=1;
			sum+=(box[2]-num+8)/9;
		}
		int num2=0;
		num2=sum*36-4*box[2]-9*box[3]-16*box[4]-25*box[5]-36*box[6];
		if(num2<box[1])
		{
			sum+=(box[1]-num2+35)/36;
		}
		cout<<sum<<endl;
	}
		
		
	return 0;
}


