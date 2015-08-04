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
char a[100100],b[100100];
int main()
{
	ios::sync_with_stdio(false);
	int len1,len2;
	int i,j,flag=0;
	int T;
	cin>>T;
	cin.ignore();
	while(T--)
	{
		flag=0;
		cin.getline(a,100100);
		cin.getline(b,100100);
		len1=strlen(a);
		len2=strlen(b);
		for(i=0;i<len1;i++)
		{
			if(a[i]>='A'&&a[i]<='Z')a[i]+='a'-'A';
		}
		for(i=0;i<len2;i++)
		{
			if(b[i]>='A'&&b[i]<='Z')b[i]+='a'-'A';
		}
		i=0;j=0;
		while(i<len1||j<len2)
		{
			if(a[i]==' ')
			{
				i++;
				continue;
			}
			else if(b[j]==' ')
			{
				j++;
				continue;
			}
			else if(a[i]==b[j])
			{
				i++;
				j++;
			}
			else
			{
				flag=1;
				break;
			}
		}
		if(i!=len1||j!=len2)flag=1;
		if(flag)cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}
		
	return 0;
}


