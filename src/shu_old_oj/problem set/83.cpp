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
char b[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
int a;
char c[10];
int len;
int main()
{
	ios::sync_with_stdio(false);
	
//	int b;
//	while(cin.getline(c,10,'\n'))
//	{
//		a=0;
	//	len=strlen(c);
		//for(int i=len-1;i>=0;i--)
		//{
		//	a*=10;
		//	a+=c[i]-'0';
		//}
	while(cin>>a)
	{		
		cout<<setfill('0')<<setw(3)<<(int)a<<" "
			<<"0x"<<b[int(a/16)]<<b[int(a%16)]<<" "
			<<"'";
		if(a<32||(a>=127&&a<=159)||a==255)
		cout<<".";
		else cout<<(char)a;	
		cout<<"' ";
		if(a<32||(a>=127&&a<=159)||a==255)
		{
			cout<<"Control";
		}
		else if(a>='0'&&a<='9')
		{
			cout<<"Digital";
		}
		else if(a>='a'&&a<='z')
		{
			cout<<"Lower";
		}
		else if(a>='A'&&a<='Z')
		{
			cout<<"Upper";
		}
		else {
			cout<<"Other";
		}
		cout<<endl;	
	}
	return 0;
}

