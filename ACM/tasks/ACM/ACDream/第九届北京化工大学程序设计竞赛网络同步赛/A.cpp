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
set<int>s;
int a[110];
int main()
{
	ios::sync_with_stdio(false);
    int n,h;
    while(cin>>n>>h){
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        bool ok =0 ;
        s.clear();
        int m=1<<(n/2);
        for(int i=0;i<m;i++){
            int tmp =i;
            int sum=0;
            for(int j=0;j<n/2;j++){
                if(!tmp)break;
                if(tmp&1){
                    sum+=a[j];
                }
                if(sum>h)break;
                tmp>>=1;
            }
            if(sum<=h)s.insert(sum);
        }
        m=1<<(n-n/2);
        int f= n-n/2;
        for(int i=0;i<m;i++){
            int tmp = i ;
            int sum =0;
            for(int j =0;j<f;j++){
                if(!tmp)break;
                if(tmp&1){
                    sum+=a[j+n/2];
                }
                if(sum>h)break;
                tmp>>=1;
            }
            if(sum>h)continue;
            if(s.count(h-sum))ok=1;
            if(ok)break;
        }
        if(ok)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;

    }
	return 0;
}


