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
char a[100010];
char b[100010];
char c[4];
int flag;
int main()
{
	ios::sync_with_stdio(false);
	int k=1;
	int n;
	//cin>>n;
//	cin.ignore();
//	while(n--)
	while(cin.getline(a,100010,'\n'))
	{
	//	cin.getline(a,100010,'\n');
		flag=1;
		for(int i=0;i<strlen(a);i++)
		{
			if(a[strlen(a)-1-i]<0)
			{
				//cout<<"ok"<<endl;
				b[i]=a[strlen(a)-2-i];
				b[i+1]=a[strlen(a)-1-i];
				i++;
				cout<<c;
			}
			else 
			{
				b[i]=a[strlen(a)-1-i];
			//	cout<<a[strlen(a)-1-i];
			}
			//if(a[i]!=a[strlen(a)-1-i])
			//{
			//	flag=0;
			//	break;
			//}
		}
		
		cout<<"Case "<<k++<<": ";
		cout<<"\"";
		cout<<b<<"\""<<endl;
		memset(a,'\0',sizeof(a));
		memset(b,'\0',sizeof(b));
	}
	
	return 0;
}

