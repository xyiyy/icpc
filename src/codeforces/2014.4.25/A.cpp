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
using namespace std;
#define XINF INT_MAX
#define INF 0x3FFFFFFF
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X,N) for(int X=0;X<N;X++)
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long ll;
char a[1000]; 

int main()
{
	ios::sync_with_stdio(false);
	int n;
	while(cin>>n)
	{
		//cin>>a;
		//int len=strlen(a);
		memset(a,'\0',sizeof(a));
		int num1=0;
		int num2=0;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			if(a[i]=='x')num1++;
			if(a[i]=='X')num2++;
		}
		cout<<abs(num1-num2)/2<<endl;
		if(num1==num2)
		{
			cout<<a<<endl;
		}
		else if(num1<num2)
		{
			for(int i=0;num1<n/2;i++)
			{
				if(a[i]=='X'){a[i]='x';
				num1++;}
			}
			cout<<a<<endl;
		}
		else if(num1>num2)
		{
			for(int i=0;num2<n/2;i++)
			{
				if(a[i]=='x')
				{a[i]='X';
				num2++;}
			}
			cout<<a<<endl;
		}
	}
		
	return 0;
}

