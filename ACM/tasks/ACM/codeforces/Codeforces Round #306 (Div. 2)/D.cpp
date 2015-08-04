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
vector<int>G[10010];
int tot=0;
void add_edge(int u,int v){
    G[u].PB(v);
    tot++;
}
int main()
{
	ios::sync_with_stdio(false);
	int k;
	cin>>k;
	if(k==1){
        cout<<"YES"<<endl;
        cout<<"2 1"<<endl;
        cout<<"1 2"<<endl;
        return 0;
	}
	if(k%2==0){
        cout<<"NO"<<endl;
        return 0;
	}
	for(int i=1;i<=k-1;i++){
        for(int j=i+1;j<=k;j++){
            add_edge(i,j);
        }
	}
	int j=k;
	for(int i=3;i<=k;i+=2,j+=k+1){
        for(int s=j+1;s<j+k;s++){
            for(int t=s+1;t<=j+k+1;t++){
                add_edge(s,t);
            }
        }
        add_edge(i-1,j+k);
        add_edge(i,j+k+1);
	}
	j = (k-1)/2*(k+1)+k;
	for(int i=j+1;i<=j+k-1;i++){
        for(int s=i+1;s<=j+k;s++){
            add_edge(i,s);
        }
	}
	int temp = j;
	j+=k;
	for(int i=temp+3;i<=temp+k;i+=2,j+=k+1){
        for(int s=j+1;s<j+k;s++){
            for(int t=s+1;t<=j+k+1;t++){
                add_edge(s,t);
            }
        }
        add_edge(i-1,j+k);
        add_edge(i,j+k+1);
	}
	add_edge(1,temp+1);
	printf("YES\n");
	printf("%d %d\n",((k-1)/2*(k+1)+k)*2,tot);
	for(int i=1;i<=((k-1)/2*(k+1)+k)*2;i++){
        for(int j=0;j<G[i].size();j++){
            printf("%d %d\n",i,G[i][j]);
        }
	}
	return 0;
}



