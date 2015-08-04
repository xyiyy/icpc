//#####################
//Author:fraud
//Blog: http://www.cnblogs.com/fraud/
//#####################
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
int a[10][10];
int b[10][10];
int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>a[i][j];
            }
        }
        int tot = (1<<(2*n));
        int ans = INF;
        for(int i=0;i<tot;i++){
            CLR(b,0);
            int num =0;
            for(int j=0;j<2*n;j++){
                if((1<<j)&i){
                    if(j<n){
                        for(int k=0;k<n;k++){
                            b[j][k]++;
                        }
                    }else{
                        for(int k=0;k<n;k++){
                            b[k][j]++;
                        }
                    }
                    num++;
                }
            }
            int f = 0;
            for(int j =0;j<n;j++){
                for(int k=0;k<n;k++){
                    if(b[j][k]==2&&a[j][k]==1)f=1;
                    if(b[j][k]==0&&a[j][k]==1)f=1;
                }
            }
            if(!f)ans = min(num,ans);
        }
        cout<<ans<<endl;
    }
    return 0;
}
