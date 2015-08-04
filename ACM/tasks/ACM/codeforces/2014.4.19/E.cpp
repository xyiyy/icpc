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

char a[1000010];
bool b[1000010];
bool c[1000010];

int main()
{
	ios::sync_with_stdio(false);
	cin>>a;
	int len=strlen(a);
	int x=0,y=0;
	int num=0;
	int num1,num2;
	for(int i=0;i<len;i++)
	{
		if(a[i]=='@')
		{
			int flag=0;
			num1=num2=0;
			for(int j=i+1;j<len&&!flag;j++)
			{
				if(a[j]>='0'&&a[j]<='0'||(a[j]>='a'&&a[j]<='z')||(a[j]>='A'&&a[j]<='Z')||a[j]=='.')
				{
				
					if(a[j]=='.')
					{
						num2=0;flag=1;
						for(int k=j+1;k<len;k++)
						{
							if((a[k]>='a'&&a[k]<='z')||(a[k]>='A'&&a[k]<='Z'))
							{
								num2++;
							}
							else break;
						}
					}
					else continue;
					
				}
				else break;
			}
			num1=0;
			for(int j=i-1;j>=0&&a[j]!='.'&&a[j]!='@';j--)
			{
				if((a[j]>='a'&&a[j]<='z')||(a[j]>='A'&&a[j]<='Z'))
				{
					num1++;
				}
			}
			num+=num1*num2;
		}
	}
	cout<<num<<endl;
				
	return 0;
}

