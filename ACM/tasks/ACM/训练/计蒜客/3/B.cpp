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
ll sum[310][310];
ll tot[310][310];
int a[310];
int main()
{
    ios::sync_with_stdio(false);
    int n,m;
    while(cin>>n>>m){
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        CLR(sum,0);
        for(int i=0;i<n;i++){
            for(int j=i;j>=0;j--){
                int len = i-j+1;
                int f = 1;
                int tmp = 0;
                for(int l=0;l<len;l++){
                    tmp+=a[j+l];
                    if(a[j+l]!=a[i-l]){
                        f=0;
                        break;
                    }
                }
                if(f)sum[j][i]=tmp;
            }
        }
       /* for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<sum[i][j]<<" ";
            }
            cout<<endl;
        }*/
        CLR(tot,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                tot[i][j]=sum[i][j];
                if(i)tot[i][j]+=tot[i-1][j];
                if(j)tot[i][j]+=tot[i][j-1];
                if(i>0&&j>0)tot[i][j]-=tot[i-1][j-1];
            }
        }
        for(int i=0;i<m;i++){
            int l,r;
            cin>>l>>r;
            l--;
            r--;
            ll ans=0;
            ans=tot[r][r];
            if(l)ans-=tot[l-1][r]+tot[r][l-1]-tot[l-1][l-1];
            cout<<ans<<endl;
        }


    }
    return 0;
}
