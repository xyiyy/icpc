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
int flag;
int main()
{
	ios::sync_with_stdio(false);
	int k=1;
	int n;
	cin>>n;
	cin.ignore();
	while(n--)
	//while(cin.getline(a,100010,'\n'))
	{
		cin.getline(a,100010,'\n');
		flag=1;
		for(int i=0;i<strlen(a);i++)
		{
			if(a[i]!=a[strlen(a)-1-i])
			{
				flag=0;
				break;
			}
		}
		cout<<"Case "<<k++<<": ";
		if(flag)cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	
	return 0;
}

