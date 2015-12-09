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
const int maxn=10010;
ll bestNum;
ll bestSum;
ll n=2000000000;
ll rprime[maxn][2];
ll prime[10]={2,3,5,7,11,13,17,19,23,29};

void getNum(ll num,ll k,ll sum,ll limit)
{
	if(num>n)return;
	if(sum>bestSum)
	{
		bestSum=sum;
		bestNum=num;
	}
	else if(sum==bestSum&&num<bestNum)
	{
		bestNum=num;
	}
	if(k>=10)return;
	for(ll i=1,p=1;i<=limit;i++)
	{
		p*=prime[k];
		if(p>n)return;
		getNum(num*p,k+1,sum*(i+1),i);
	}
}

ll log2()
{
	ll i=0;
	ll p=1;
	while(p<n)
	{
		p*=2;
		i++;
	}
	return i;
}
int getprime()
{
	int i=0;
//	rprime[0][0]=1;
//	rprime[0][1]=1;
	//cout<<n<<endl;
	while(n>0)
	{
		bestNum=1;
		bestSum=1;
		getNum(1,0,1,log2());
	//	cout<<bestNum<<endl;
		n=bestNum-1;
		rprime[i][0]=bestNum;
		rprime[i][1]=bestSum;
		i++;
	//	cout<<n<<endl;
		//cout<<"ok"<<endl;
	}
	rprime[i][0]=1;
	rprime[i][1]=1;
	return i+1;
}

int main()
{
	ios::sync_with_stdio(false);
	getprime();
	int a;
	while(cin>>a)
	{
		for(int i=1;;i++)
		{
			if(rprime[i][0]<=a)
			{
				cout<<rprime[i][0]<<endl;
				break;
			}
		}
	}
			
		
	return 0;
}



