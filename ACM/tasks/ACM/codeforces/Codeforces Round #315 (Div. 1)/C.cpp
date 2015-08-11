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
#define mp(X,Y) make_pair(X,Y)
#define pb(X) push_back(X)
#define rep(X,N) for(int X=0;X<N;X++)
#define rep2(X,L,R) for(int X=L;X<=R;X++)
#define dep(X,R,L) for(int X=R;X>=L;X--)
#define clr(A,X) memset(A,X,sizeof(A))
#define IT iterator
#define ALL(X) (X).begin(),(X).end()
#define PQ std::priority_queue
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;
int a[110];
int main(){
    ios::sync_with_stdio(0);
    string str;
    cin>>str;
    int len = str.length();
    rep(i,len){
        if(str[i] == 'V')a[i] = 1;
    }
    int n,m;
    string s1,s2;
    int p1,p2;
    cin>>n>>m;
    rep(i,m){
        cin>>p1>>s1>>p2>>s2;
        p1--;p2--;
        if(s1=="V"&&s2=="V"){
            G[p1][p2] = 1;
        }else if(s1 == "V"&&s2=="C"){
            G[p1][p2+len] = 1;
        }else if(s1=="C"&&s2=="V"){
            G[p1+len][p2] = 1;
        }else G[p1+len][p2+len] = 1;
    }
    rep(i,len*2)G[i][i] = 1;
    rep(k,len*2){
        rep(i,len*2){
            rep(j,len*2){
                G[i][j] |= G[i][k]&&G[k][j];
            }
        }
    }
    rep(i,len){
        if(G[i][i+len]==1||G[len+i][i]){
            cout<<"-1"<<endl;
            return 0;
        }
    }
    cin>>str;
    for(int i=n-1;i>=0;i--){
        clr(vis,0);
        rep(j,i){
            int tmp = j;
            if(a[str[j]-'a'])tmp+=len;
            rep(k,n){
                    if(G[tmp][k])vis[k][0] =1;
                    if(G[tmp][k+n])vis[k][1] = 1;
            }
        }
        int f = 0;
        rep(j,i){

        }
    }



    return 0;
}
