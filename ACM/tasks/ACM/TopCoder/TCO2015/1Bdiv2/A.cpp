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

#define PRIME_MAXN 10100
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
vector<int>vec[1010];
class TheNicePair{
public :
    int solve(vector<int> A){
        Eular();
        for(int i=0;i<1001;i++)vec[i].clear();
        for(int i=0;i<A.size();i++){
                for(int j=0;prime[j]*prime[j]<=A[i];j++){
                    if(A[i]%prime[j]==0)vec[prime[j]].PB(i);
                    while(A[i]%prime[j]==0){
                        A[i]/=prime[j];
                    }
                }
                if(A[i]!=1)vec[A[i]].PB(i);
        }
        int maxx=-1;
        for(int i=0;i<1000;i++){
            if(vec[i].size()){
                    for(int j=0;j<vec[i].size();j++){
                            for(int k=j;k<vec[i].size();k++){
                                if(vec[i][k]-vec[i][j]+1<=2*(k-j+1)){
                                    maxx=max(min((int)A.size()-1,2*(k-j+1)-1),maxx);
                                }
                            }
                    }
            }
        }
        return maxx;

    }
};
int main()
{
	ios::sync_with_stdio(false);

	return 0;
}

