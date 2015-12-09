//gaoshenbaoyou  ------ pass system test
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
int p[110],p2[110];
map<int,int>A,B;
int main()
{
	ios::sync_with_stdio(false);
	int n,a,b;
	cin>>n>>a>>b;
	for(int i=0;i<n;i++)
	{
		cin>>p[i];
		if(A.find(p[i])==A.end())
		{
			A[p[i]]=1;
		}
		else 
		{
			A[p[i]]++;
		}
	}
	for(int i=0;i<n;i++)
	{
		if(A.find(p[i])!=A.end())
		{
			int x=a-p[i];
			if((A.find(x)==A.end()))
			{
				B[p[i]]==A[p[i]];
		//		B.insert(p[i]);
				A.erase(p[i]);
			}
		}
		
	}
	int tail=0;
	for(map<int,int>::iterator it=B.begin();it!=B.end();it++)
	{
		p2[tail++]=it->first;
	}
	bool flag=1;
	for(int i=0;i<tail;i++)
	{
		int x=b-p2[i];
		if(B.find(x)==B.end())
		{
			if(A.find(x)!=A.end())
			{
				if(A[x]>1)
				{
					B[x]=1;
					if(B.find(a-x)==B.end())
					{
						B[a-x]=1;
						//p2[tail++]=a-x;
					}
					else
					{
						B[a-x]++;
					}
					A[x]--;
					//A[a-x]--;
				}
					else
					{
						B[x]=A[x];
						if(B.find(a-x)==B.end())
						{
							B[a-x]=A[a-x];
							p2[tail++]=a-x;
						}
						else
						{
							B[a-x]=A[a-x];
						}
						A.erase(x);
						A.erase(a-x);
					}
				}
				else
				{
					flag=0;
					break;
				}
			}
		}
		if(!flag)
		{
			cout<<"NO"<<endl;
		}
		else
		{
			cout<<"YES"<<endl;
			for(int i=0;i<n;i++)
			{
				if(i)cout<<" ";
				if(A[p[i]])
				{
					A[p[i]]--;
					cout<<0;
				}
				else
				{
					cout<<1;
				}
			}
		}
		
	return 0;
}



