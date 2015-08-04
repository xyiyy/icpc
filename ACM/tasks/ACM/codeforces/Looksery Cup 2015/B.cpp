//#pragma comment(linker, "/STACK:102400000,102400000")
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
char a[110][110];
int num[110];
int b[110];
int ans[110];
int tot;
bool gao(int n){
    bool flag=1;
    tot=0;
    int num=0;
    while(flag){
        flag=0;
        for(int i=0;i<n;i++){
            if(!b[i]){
                for(int j=0;j<n;j++){
                    b[j]-=a[i][j];
                }
                flag=1;
                ans[tot++]=i;
                break;
            }
        }
    }
    sort(ans,ans+tot);
    return 1;
}
int main()
{
	ios::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
            a[i][j]-='0';
        }
    }
    for(int i=0;i<n;i++)cin>>b[i];
    if(gao(n)){
        cout<<tot<<endl;
        for(int i=0;i<tot;i++){
            cout<<ans[i]+1<<" ";
        }
        cout<<endl;
    }else{
        cout<<-1<<endl;
    }
	return 0;
}


