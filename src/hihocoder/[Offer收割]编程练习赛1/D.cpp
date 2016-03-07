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
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<PII> vii;
typedef vector<int> vi;
priority_queue<int>pq;
int a[10][10];
int b[1010];
int c[1010];
int dp[100010];
bool ok[100010];
bool ok2[100010];
bool bbb[5];
vector<int>kong,di;
int main()
{
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--){
        int n,m,t,s;
        cin >> n >> m>> t>> s;
        rep(i,n){
            rep(j,m){
                cin >> a[i][j];
            }
        }
        rep(i,t){
            cin >> b[i];
        }
        di.clear();
        kong.clear();
        rep(i,t)cin >>c[i];
        rep(i,t){
            if(b[i]==0)di.pb(c[i]);
            else kong.pb(b[i]);
        }
        sort(di.begin(),di.end());
        sort(kong.begin(),kong.end());
        //if(kong.size())
        int tot = (1<<(n*m));
        int num = n * m;
        bool ans = false;
        rep(i,tot){
            ok[i] = false;
            ok2[i] = true;
            clr(bbb,0);
            int sz = kong.size();
            int gao = 0;
            int gao2 = 0;
            int sz2 = di.size();
            vector<int>kong2;
            kong2.clear();
            vector<PII>di2;
            di2.clear();
            for(int j=0;j<num;j++){
                if((1<<j)&i){
                    kong2.pb(a[j/m][j%m]);
                    //if(sz){
                        //gao += kong[sz-1]*a[j/m][j%m];
                        //sz--;
                    //}

                }else{
                    di2.pb(mp(a[j/m][j%m],j/m));
                    //gao2 += di[sz2 - 1]*a[j/m][j%m];
                    //sz2 --;
                //    bbb[j / m] = true;
                }
            }
            sort(kong2.begin(),kong2.end());
            sort(di2.begin(),di2.end());
            for(int j = kong2.size();j>0;j--){
                if(sz){
                    gao+= kong2[j-1] * kong[sz-1];
                    sz--;
                }
                //gao += kong2[i-1] * kong[]
            }
            int gao3 = 0;
            int last  = 0;
            int gaonum = 0;
            for(int ii = di2.size();ii>0;ii--){
                if(sz2){
                    gao2 += di2[ii-1].first * di[sz2- 1];
                    last = di2[ii-1].first;
                    sz2--;
                    gaonum++;
                    //bbb[di2[i-1].second] = true;
              /*      if(bbb[di2[ii-1].second] == true){
                        for(int j = 1; j <= ii - 1;j++){
                            if(ii - 1 - j <0)break;
                            if(di2[ii - 1 - j].first != di2[ii-1].first)break;
                            if(bbb[di2[ii-1-j].second]==false){
                                swap(di2[ii-1-j],di2[ii-1]);
                                break;
                            }
                        }
                    }
                    bbb[di2[ii-1].second] = true;*/
                }
            }
            sz2 = di.size();
            vector<int>temp;
            temp.clear();

            for(int ii = di2.size();ii > 0;ii--){
                //if(sz2){
                    if(di2[ii-1].first >last)bbb[di2[ii-1].second] = true,gaonum--;
                    else if(di2[ii-1].first == last)temp.pb(bbb[di2[ii-1].second]);
                //}
            }
            for(int j = 0; j < temp.size();j++){
                if(bbb[j]==false&&gaonum)bbb[j] = true,gaonum--;
            }
           // cout << gao << endl;
            if(gao >= s){
                ok[i] = true;
                ans = true;
            }
            for(int j = 0;j < n;j++){
                if(bbb[j] == false)ok2[i] = false;
            }
            dp[i] = gao2;

        }
        if(ans){
            ans = 0;
            int maxn = 0;
            rep(i,tot){
                if(ok[i])
                maxn = max(dp[i],maxn);
            }
            rep(i,tot){
                if(ok[i]&&dp[i]==maxn)ans = max(ans,ok2[i]);
            }
            cout << maxn << endl;
            if(ans)cout << "Yes" <<endl;
            else cout << "No" << endl;
        }else{
            cout << "Not Exist" << endl;
        }


    }




    return 0;
}


