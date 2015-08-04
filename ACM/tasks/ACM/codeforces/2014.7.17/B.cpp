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
int vis1[26];
int vis2[26];
int main()
{
	ios::sync_with_stdio(false);
	string a,b;
	int len1,len2;
	bool flag1,flag2,flag3,flag4;
	while(cin>>a>>b)
	{
		flag1=0;
		flag2=0;
		flag3=0;flag4=0;
		len1=a.length();
		len2=b.length();
		int i=0,j=0;
		CLR(vis1,0);
		CLR(vis2,0);
		while(i<len2)
		{
			if(b[i]==a[j])
			{
				i++;
			}
			j++;
			if(j==len1)break;
		}
		if(i==len2)flag1=1;
		if(flag1)
		{
			cout<<"automaton"<<endl;
		}
		else 
		{
			for(int i=0;i<len1;i++)
			{
				vis1[a[i]-'a']++;
			}
			for(int i=0;i<len2;i++)
			{
				vis2[b[i]-'a']++;
			}
		//	cout<<vis1[0]<<" "<<vis2[0]<<endl;
			
			flag2=1;
			for(int i=0;i<26;i++)
			{
				if(vis1[i]>vis2[i])
				{
					flag2=0;
					flag4=1;
				}
				if(vis1[i]<vis2[i])
				{
					flag2=0;
					flag3=1;
				}
			}
			if(flag2)
			{
				cout<<"array"<<endl;
			}
			else if(flag3)
			{
				cout<<"need tree"<<endl;
			}
			else if(flag4)
			{
				cout<<"both"<<endl;
			}
		}
		a.clear();
		b.clear();
	}
					
			
	return 0;
}


