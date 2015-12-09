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

ll a,b,c,d,e;
ll COU;
ll num;
ll nn;

ll fun(ll x)
{
	ll temp;
	temp=x/100;
	if(temp*100==x)
	{
		return temp*100;
	}
	else 
	{
		return (temp+1)*100;
	}
}
	

int main()
{
	ios::sync_with_stdio(false);
	while(cin>>a>>b>>c>>d>>e)
	{
		if(b>=13)COU=8000;
		else if(b>=11)COU=6000;
		else if(b>=9)COU=4000;
		else if(b>=6)COU=3000;
		else 
		{
			COU = a*((1<<(b+2)));
			if(COU>2000)COU=2000;
		}
		//cout<<COU<<endl;
		if(c==0&&d==0)
		{
			num=COU*2;
			num=fun(num);
			cout<<num+e*100<<endl;
		}
		else if(c==0&&d==1)
		{
			num=COU*6;
			num=fun(num);
			cout<<num+e*300<<endl;
		}
		else if(c==1&&d==0)
		{
			num=COU*1;
			nn=COU*2;
		//	cout<<nn<<endl;
			num=fun(num);
			nn=fun(nn);
		//	cout<<nn<<endl;
			cout<<num+e*100<<" "<<nn+e*100<<endl;
		}
		else if(c==1&&d==1)
		{
			num=COU*4;
			num=fun(num);
			cout<<num+e*300<<endl;
		}
	}	
	return 0;
}

