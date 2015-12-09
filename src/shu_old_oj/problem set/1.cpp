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
	int key;
	int id;
	int cas=1;
//	queue <char >que;
	while(cin>>key)
	{
		cin.ignore();
		CLR(a,0);
		CLR(b,0);
		CLR(vis,0);
		cin.getline(a,N,'\n');
		if(cas!=1)cout<<endl;
		int len=strlen(a);
		id=-1;
	//	while(que.size())
	//	{
	//		que.pop();
	//	}
		if(key>1)
		{
			int k=0;
			for(int i=0;i<len;i++)
			{
				int j=0;
				while(j<key)
				{
					if(!vis[k++])j++;
					k=k%len;
				}
				k--;
				if(k<0)
				k+=len;
				b[k]=a[i];
				vis[k]=1;
				k++;
				k=k%len;
			}
		//	for(int i=0;i<len;i++)
		//	{
		//		cout<<b[i];
		//	}
		//	cout<<endl;
				
		}
		else if(key<-1)
		{
			key=-key;
			int k=0;
			for(int i=0;i<len;i++)
			{
				int j=0;
				while(j<key)
				{
					if(!vis[k])j++;
					k++;
					k=k%len;
				}
				k--;
				if(k<0)
				k+=len;
				b[i]=a[k];
				vis[k]=1;
				k++;
				k=k%len;
			}
		}
		cout<<"Case "<<cas++<<": "<<endl;
		cout<<b<<endl;
	}
		
		
	return 0;
}


