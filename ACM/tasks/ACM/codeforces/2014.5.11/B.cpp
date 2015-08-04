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
int n,k,x;
int l,r,temp;
int a[110];
int sum,maxx;

int main()
{
	ios::sync_with_stdio(false);
	while(cin>>n>>k>>x)
	{
		maxx=0;
		sum=0;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		for(int i=0;i<n-1;+i++)
		{
			if(a[i]==x&&a[i]==a[i+1])
			{
				l=i-1;
				temp=a[i];
				while(a[i+1]==temp)i++;
				r=i+1;
				sum=r-l-1;
				while(l>=0&&r<n)
				{
					temp=a[l];
					if(a[r]==temp&&(a[l-1]==temp||a[r+1]==temp))
					{
						while(a[l]==temp)
						{
							sum++;
							l--;
						}
						while(a[r]==temp)
						{
							sum++;
							r++;
						}
					}
					else break;
				}
				maxx=max(maxx,sum);
			}
		}
		cout<<maxx<<endl;
	}
				
	return 0;
}

