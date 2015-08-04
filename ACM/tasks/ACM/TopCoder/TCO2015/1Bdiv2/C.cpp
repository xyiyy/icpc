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
int A[1010],len;
int solve()
{
    int k=-1;
    for(int curlen=1;curlen<=len;curlen++){
        for(int v=2;v<=1000;v++){
            int half = (int)ceil(curlen/2.0);
            bool flag=0;
            for(int i=0;i+curlen<=len;i++){
                int count=0;
                for(int s=i;s<i+curlen;s++){
                    if(A[s]%v==0)count++;
                    if(count>=half){
                        flag=1;
                        int j=i+curlen-1;
                        if(j-i>k)k=j-i;
                        if(k==2){
                            int a=0;
                            a=a+1;
                        }
                        break;
                    }
                }
            }
            if(flag)break;
        }
    }
    return k;

    }
int main()
{
	ios::sync_with_stdio(false);
    int len;
    while(cin>>len){
        for(int i=0;i<len;i++)cin>>A[i];
        cout<<solve()<<endl;
    }
	return 0;
}



