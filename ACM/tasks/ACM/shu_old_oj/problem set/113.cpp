#include <iostream>
#include <sstream>
#include <strstream>
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
double a[1010];
int id[1010];
int b[1010];
bool cmp(int x,int y)
{
	return a[x]>=a[y];
}
int main()
{
	ios::sync_with_stdio(false);
	char str[10010];
	int i=0;
	int k=1;
	int j=0,r;
	while(cin.getline(str,10010,'\n'))
	{
		memset(id,0,sizeof(id));
		memset(b,0,sizeof(b));
		istrstream ss(str);
		i=0;
		while(ss>>a[i])
		{
			id[i]=i;
			i++;
		}
	//	i--;
	//	cout<<i<<endl;
		//for(int m=0;m<i;m++)cout<<a[m]<<"  ";
	//	cout<<endl;
		sort(id,id+i,cmp);
		r=1;
	//	for(int m=0;m<i;m++)cout<<id[m]<<" ";
	//	cout<<endl;
		b[id[0]]=1;
		for(j=1;j<i;j++)
		{
			if(a[id[j]]==a[id[j-1]])
			{
				b[id[j]]=b[id[j-1]];
				r++;
			}
			else 
			{	
				b[id[j]]=b[id[j-1]]+r;
				r=1;
			}
		}
		cout<<"Case "<<k++<<":"<<endl;
		if(i)
		cout<<b[0];
		for(j=1;j<i;j++)
		{
			cout<<", "<<b[j];
		}
		cout<<endl;
	//	cin.ignore();
		memset(str,'\0',sizeof(str));
	}
			
	return 0;
}

