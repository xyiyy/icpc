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
const int N=100010;
char a[N];
char b[N];
bool vis[N];
int main()
{
	ios::sync_with_stdio(false);
	int k=1,num=0,j;
	while(cin.getline(a,N,'\n'))
	{
		//strlwr(a);
		j=0;
		for(num=0;num<strlen(a);num++)
			if(a[num]!=' ')break;
		for(int i=strlen(a);i>=num;i--)
		{
		//	cout<<i<<"  ok"<<endl;
			if(i==num&&!vis[i]&&((a[i]>='a'&&a[i]<='z')||(a[i]>='A'&&a[i]<='Z')))
			{
				while(a[i]!=' '&&i<strlen(a))
				{
					b[j++]=a[i];
					vis[i]=1;
					i++;
					
				}
			}
			else if(a[i]==' '&&i<strlen(a)-1&&!vis[i+1]&&((a[i+1]>='a'&&a[i+1]<='z')||(a[i+1]>='A'&&a[i+1]<='Z')))
			{
				i++;
				while(a[i]!=' '&&i<strlen(a))
				{
					b[j++]=a[i];
					vis[i]=1;
					i++;
					
				}
				b[j++]=' ';
			}
		}
		cout<<"Case "<<k++<<": "<<b<<endl;
		//num=0;
		memset(a,'\0',sizeof(a));
		memset(b,'\0',sizeof(b));
		CLR(vis,0);
	}
	return 0;
}

