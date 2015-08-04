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
string str;
double leaf[3][4]={0.6,0.20,0.15,0.05,
					0.25,0.3,0.2,0.25,
					0.05,0.10,0.35,0.50};
double wea[3][3]={0.5,0.375,0.125,
					0.25,0.125,0.625,
					0.25,0.375,0.375};
										
int main()
{
	ios::sync_with_stdio(false);
	int flag,T,n,len;
	double s,c,r,ls,lc,lr;
	double ps,pc,pr;
	int cas=1;
	cin>>T;
	while(T--)
	{
		cin>>n; 
		cout<<"Case #"<<cas++<<":"<<endl;
		ls=s=0.63;lc=c=0.17;lr=r=0.2;
		for(int i=0;i<n;i++)
		{
			cin>>str;
			len=str.length();
			if(len==3)flag=0;
			else if(len==6)flag=1;
			else if(len==4)flag=2;
			else if(len==5)flag=3;
			if(!i)
			{
			//	s=ls*0.5+lc*0.25+lr*0.25;
			//	c=ls*0.375+lc*0.125+lr*0.375;
			//	r=ls*0.125+lc*0.625+lr*0.375;
				//for(int i=0;i<3;i++)cout<<leaf[i][flag]<<"  ";
				//cout<<endl;
				ps=s*leaf[0][flag]/(s*leaf[0][flag]+c*leaf[1][flag]+r*leaf[2][flag]);
				pc=c*leaf[1][flag]/(s*leaf[0][flag]+c*leaf[1][flag]+r*leaf[2][flag]);
				pr=r*leaf[2][flag]/(s*leaf[0][flag]+c*leaf[1][flag]+r*leaf[2][flag]);
			}
			else 
			{
				s=ls*0.5+lc*0.25+lr*0.25;
				c=ls*0.375+lc*0.125+lr*0.375;
				r=ls*0.125+lc*0.625+lr*0.375;
				ps=s*leaf[0][flag]/(s*leaf[0][flag]+c*leaf[1][flag]+r*leaf[2][flag]);
				pc=c*leaf[1][flag]/(s*leaf[0][flag]+c*leaf[1][flag]+r*leaf[2][flag]);
				pr=r*leaf[2][flag]/(s*leaf[0][flag]+c*leaf[1][flag]+r*leaf[2][flag]);
			}
			ls=ps;lc=pc;lr=pr;
		//	cout<<ls<<"  "<<lc<<"  "<<lr<<endl;
			//cout<<ls+lc+lr<<endl;
			if(ps>pc&&ps>pr)
			{
				cout<<"Sunny"<<endl;
			//	lc=0;lr=0;
			}
			else if(pc>ps&&pc>pr)
			{
				cout<<"Cloudy"<<endl;
			//	ls=0;lr=0;
			}
			else if(pr>ps&&pr>pc)
			{
				cout<<"Rainy"<<endl;
			//	ls==0;lc=0;
			}
		}
	}
	return 0;
}


