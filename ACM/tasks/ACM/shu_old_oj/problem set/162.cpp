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
int b[10];
int c[26];
int d[26];
int main()
{
	ios::sync_with_stdio(false);
	int n,len,flag,num;
	cin>>n;
	cin.ignore();
	while(n--)
	{
		flag=0;
		CLR(a,0);
		CLR(b,0);
		CLR(c,0);
		CLR(d,0);
		//cin>>a;
		cin.getline(a,100010,'\n');
		len=strlen(a);
		num=0;
		for(int i=0;i<len;i++)
		{
			if(a[i]>='0'&&a[i]<='9')b[a[i]-'0']++;
			else if(a[i]>='a'&&a[i]<='z')c[a[i]-'a']++;
			else if(a[i]>='A'&&a[i]<='Z')d[a[i]-'A']++;
		}
		for(int i=0;i<10;i++)
		{
			if(b[i]&1)num++;
		}
		for(int i=0;i<26;i++)
		{
			if(c[i]&1)num++;
			if(d[i]&1)num++;
		}
		if(len&1)
		{
			if(num==1)cout<<"Yes"<<endl;
			else cout<<"No"<<endl;
		}
		else 
		{
			if(num==0)cout<<"Yes"<<endl;
			else cout<<"No"<<endl;
		}
	}

	return 0;
}


