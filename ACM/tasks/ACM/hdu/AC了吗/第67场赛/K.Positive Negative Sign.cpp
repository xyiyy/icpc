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

//int sum[110];
long long  a[110],b[110],c[110];
int main()
{
	ios::sync_with_stdio(false);
	int n,m,k=1,T;
	cin>>T;
	while(T--)
	{
	//	memset(sum,0,sizeof(sum));
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
	//	memset(temp,'\0',sizeof(temp));
		cin>>m>>n;
		cout<<"Case "<<k++<<": ";
		int nn=n;
		for(int i=100;nn!=0;i--)
		{
			a[i]=nn%10;
			nn/=10;
		}
	//	for(int i=90;i<=100;i++)cout<<a[i];
		nn=0;
		for(int i=100;i>=80;i--)
		{
			b[i]=(a[i]*n+nn)%10;
			nn=(a[i]*n+nn)/10;
		}
	//	cout<<b[98];
	//	for(int i=80;i<=100;i++)cout<<b[i];
		int temp=(m/2/n);
	//	nn=temp;
	//	cout<<nn<<endl;
	//	memset(a,0,sizeof(a));
	//	for(int i=100;nn!=0;i--)
	//	{
	//		a[i]=nn%10;
	//		nn/=10;
	//	}
		nn=0;
		for(int i=100;i>=70;i--)
		{
			c[i]=(b[i]*temp+nn)%10;
			//cout<<b[i]<<endl;
			nn=(b[i]*temp+nn)/10;
		//	cout<<nn<<endl;
		}
		//for(int i=70;i<=100;i++)cout<<c[i];
		int j;
		for(j=70;c[j]==0;j++)
		{
			;
		}
		for(int i=j;i<=100;i++)
		{
			cout<<c[i];
		}
		cout<<endl;
		 
		 //char temp[]
		 //long long temp=n*n%1000000000*(m/2/n)%1000000000;
		 //long te=n*n%1000000000*(m/2/n)/1000000000;
		 //<<temp<<endl;
	}
	
		 
	return 0;
}

