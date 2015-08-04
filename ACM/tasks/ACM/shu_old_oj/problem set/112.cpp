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
int y,m;
int month[14]={31,28,31,30,31,30,31,31,30,31,30,31,31,28};
int fun()
{
	return (((y%100)+(y%100)/4+y/400-2*y/100+(26*(m+1))/10+1-1)+7*10000)%7;
}
bool is_leapyear()
{
	if(y%4==0&&y%100!=0||y%100==0)
	return 1;
	else return 0;
}
int main()
{
	ios::sync_with_stdio(false);
	int k=1;
	int d;
	//char a[7]={Sun Mon Tue Wed Thu Fri Sat};
	while(cin>>y>>m)
	{
		
		d=1;
		if(is_leapyear())month[13]++;
		cout<<"Case "<<k++<<": "<<y<<"-"<<m<<endl;
		cout<<" Sun Mon Tue Wed Thu Fri Sat"<<endl;
		if(m==1||m==2){m+=12;y-=1;}
		for(int i=0;d<=month[m-1];i++)
		{
			if(i<fun())
			cout<<setw(4)<<" ";
			else 
			cout<<setw(4)<<d++;
			if(i%7==6)cout<<endl;
		//	else if(d>1) cout<<" ";
			if(d==month[m-1]+1&&i%7!=6)cout<<endl;
		}
		
		month[13]=28;
	//	cout<<endl;
	}
	return 0;
}

