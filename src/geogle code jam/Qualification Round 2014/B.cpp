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
#define delta 0.00000001
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long ll;
double c,f,x;
double minn;
double rate;
//double ra[10];
//double 

int main()
{
	ios::sync_with_stdio(false);
	int t; 
	freopen("B-large.in","r",stdin);
	freopen("blarge.out","w",stdout);
	cin>>t;
	int k=1;
	while(t--)
	{
		cin>>c>>f>>x;
	//	memset(ra,0,sizeof(ra));
		//memset(sav,0,sizeof(sav));
	//	memset(nu,0,sizeof(nu));
		
		double t1,t2;
		t1=c/2.0;
	//	t2=0x7fffff;
		minn=x/2.0;
		rate=2.0;
	//	int flag=0;
		if(c>=x)
		{
			minn=x/2.0;
		}
		else
		{
			t2=(x-c)/rate+t1;
			rate+=f;
			t1=(x)/rate+t1;
			while(t1<t2+1e-7)
			{
			//	if(flag)
			//	{
			//	
			//	t2=t1;
		//	}
				t2=t1;
				//t3=t1;
			//	flag=1;
			//	t2=t1+(x-c)/rate;
				t1-=(x-c)/rate;
				rate+=f;
				t1+=x/(rate);
				if(t2-t1<1e-10)break;
			}
			minn=t2;
		}
	//	cout<<""<<k++<<": ";
	//	printf("Case #%d: %.7lf\n",k,minn);
	//	cout<<endl;
	cout<<"Case #"<<k++<<": ";
	cout<<fixed<<setprecision(7)<<minn<<endl;
	
		//k++;
	}
		
		
			
			
			
			
	//	for(int i)
		
		
	return 0;
}

