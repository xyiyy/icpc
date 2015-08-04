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
int t,n;
string a;
double pro[4][3]={2.0/3.0,5.0/16.0,1.0/16.0,1.0/3.0,0.5,1.0/6.0,3.0/14.0,2.0/7.0,0.5,1.0/16.0,5.0/16.0,5.0/8.0};
int main()
{
	ios::sync_with_stdio(false);
	double s,c,r;
	double ls,lc,lr;
	int len,flag,last=0;
	double maxx=0;
	int cas=1;
	cin>>t;
	while(t--)
	{
		cout<<"Case #"<<cas++<<":"<<endl;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>a;
			len=a.length();
			/*if(len==3)
			{
				maxx=2.0/3.0;
				flag=1;
			}
			else if(len==5)
			{
				maxx=5.0/8.0;
				flag=3;
			}
			else if(len==4)
			{
				maxx=0.5;
				flag=3;
			}
			else if(len==6)
			{
				maxx=0.5;
				flag=2;
			}*/
			if(len==3)
			{
				flag=0;
			}
			else if(len==6)flag=1;
			else if(len==4)flag=2;
			else if(len==5)flag=3;
			if(i)
			{
				s=ls*0.5+lc*0.25+lr*0.25;//+pro[flag][0];
				c=ls*0.375+lc*0.125+lr*0.375;//+pro[flag][1];
				r=ls*0.125+lc*0.625+lr*0.375;//+pro[flag][2];
			}else
			{
				s=0.63;c=0.17;r=0.2;
			}
		//	cout<<s<<" "<<c<<"  "<<r<<endl;
			if((s>c&&s>r&&s>maxx)||(flag==1&&maxx>c&&maxx>r))
			{
				flag=1;
			}else if((r>s&&r>c&&r>maxx)||(flag==3&&maxx>s&&maxx>c))
			{
				flag=3;
			}else if((c>s&&c>r&&c>maxx)||(flag==2&&maxx>s&&maxx>r))
			{
				flag=2;
			}
			ls=s;lc=c;lr=r;
			if(flag==1)
			{
				cout<<"Sunny"<<endl;
			}else if(flag==2)
			{
				cout<<"Cloudy"<<endl;
			}else if(flag==3)
			{
				cout<<"Rainy"<<endl;
			}
				
		}
			
	}
	return 0;
}


