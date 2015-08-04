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
int a[2010];
int id[2010];
bool cmp(int x,int y)
{
	return a[x]<a[y];
}
int main()
{
	ios::sync_with_stdio(false);
	int n;
	while(cin>>n)
	{
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			id[i]=i;
		}
		sort(id,id+n,cmp);
		//for(int i=0;i<n;i++)
		//{
	//		cout<<a[id[i]]<<" ";
	//	}
	//	cout<<endl;
		int num1,num2;
		num1=-1;
		num2=-1;
		for(int i=0;i<n-1;i++)
		{
			if(a[id[i]]==a[id[i+1]])
			{
				if(num1==-1)
				{
					num1=i;
				}
				else 
				{
					num2=i;
				}
				if(num1!=-1&&num2!=-1)break;
			}
		}
		if(num1==-1||num2==-1)
		{
			cout<<"NO"<<endl;
		}
		else
		{
			for(int i=0;i<n;i++)
			{
				id[i]++;
			}
			cout<<"YES"<<endl;
			if(num1==num2-1)
			{
				for(int i=0;i<num1;i++)
				{
					cout<<id[i]<<" ";
				}
				cout<<id[num1]<<" "<<id[num2]<<" "<<id[num2+1]<<" ";
				for(int i=num2+2;i<n;i++)
				{
					cout<<id[i]<<" ";
				}
				cout<<endl;
				for(int i=0;i<num1;i++)
				{
					cout<<id[i]<<" ";
				}
				cout<<id[num2]<<" "<<id[num1]<<" "<<id[num2+1]<<" ";
				for(int i=num2+2;i<n;i++)
				{
					cout<<id[i]<<" ";
				}
				cout<<endl;
				for(int i=0;i<num1;i++)
				{
					cout<<id[i]<<" ";
				}
				cout<<id[num1]<<" "<<id[num2+1]<<" "<<id[num2]<<" ";
				for(int i=num2+2;i<n;i++)
				{
					cout<<id[i]<<" ";
				}
				cout<<endl;
			}
			else
			{
				for(int i=0;i<num1;i++)
				{
					cout<<id[i]<<" ";
				}
				cout<<id[num1]<<" "<<id[num1+1]<<" ";
				for(int i=num1+2;i<num2;i++)
				{
					cout<<id[i]<<" ";
				}
				cout<<id[num2]<<" "<<id[num2+1]<<" ";
				for(int i=num2+2;i<n;i++)
				{
					cout<<id[i]<<" ";
				}
				cout<<endl;
				for(int i=0;i<num1;i++)
				{
					cout<<id[i]<<" ";
				}
				cout<<id[num1+1]<<" "<<id[num1]<<" ";
				for(int i=num1+2;i<num2;i++)
				{
					cout<<id[i]<<" ";
				}
				cout<<id[num2]<<" "<<id[num2+1]<<" ";
				for(int i=num2+2;i<n;i++)
				{
					cout<<id[i]<<" ";
				}
				cout<<endl;
				for(int i=0;i<num1;i++)
				{
					cout<<id[i]<<" ";
				}
				cout<<id[num1]<<" "<<id[num1+1]<<" ";
				for(int i=num1+2;i<num2;i++)
				{
					cout<<id[i]<<" ";
				}
				cout<<id[num2+1]<<" "<<id[num2]<<" ";
				for(int i=num2+2;i<n;i++)
				{
					cout<<id[i]<<" ";
				}
				cout<<endl;
			}
		}
	}
				
	return 0;
}



