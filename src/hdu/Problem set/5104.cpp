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
#define PRIME_MAXN 10010
int vis[PRIME_MAXN];
int prime[PRIME_MAXN], n_prime;
int phi[PRIME_MAXN];
void Eular()
{
	n_prime=0;
	phi[1]=1;
	for(int i = 2; i < PRIME_MAXN; i++)
	{
		if(!vis[i]){
			prime[n_prime++] = i;
			phi[i] = i-1;
		}
		for(int j = 0; j < n_prime && i * prime[j] < PRIME_MAXN; j++)
		{
			vis[i * prime[j]] = 1;
			if(i % prime[j]) phi[i * prime[j]] = phi[i] * phi[prime[j]];  
			else {
				phi[i * prime[j]] = phi[i] * prime[j]; 
				break;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	int n;
	Eular();
	while(cin>>n)
	{
		int ans=0;
		for(int i=0;i<n_prime;i++)
		{
			if(prime[i]>=n)break;
			for(int j=i;j<n_prime;j++)
			{
				if(prime[j]>=n)break;
				if(n-prime[i]-prime[j]>=prime[j]&&!vis[n-prime[i]-prime[j]])ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}



