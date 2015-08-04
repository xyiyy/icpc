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


int main()
{
	ios::sync_with_stdio(false);
	int n,k;
	string s;
	while(cin>>n>>k)
	{
		cin>>s; 
		if(2*k<=n)
		{
			while(k-->1)
			{
				cout<<"LEFT"<<endl;
			}
			for(int i=0;i<n;i++)
			{
				cout<<"PRINT "<<s[i]<<endl;
				if(i<n-1)
				{
					cout<<"RIGHT"<<endl;
				}
				
			}
			
		}
		else 
		{
			while((k++)<n)
			{
				cout<<"RIGHT"<<endl;
			}
			for(int i=n-1;i>=0;i--)
			{
				cout<<"PRINT "<<s[i]<<endl;
				if(i>0)
				{
					cout<<"LEFT"<<endl;
				}
			}
		}
	}
	
	return 0;
}

