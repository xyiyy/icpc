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
#define mmp(x,y,z) make_pair(make_pair(x,y),z)
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
typedef pair<PII,int> PIII;

PIII dp[53][53][53][5][5];
int main()
{
    ios::sync_with_stdio(false);
    for(int i = 0 ; i < 51;i ++){
        for(int j = 0 ; j< 51; j ++){
            for(int k = 0 ; k < 51 ;k ++){
                for(int ii = 0 ; ii < 4; ii ++){
                    for(int jj = 0 ; jj < 4; jj ++){
                        dp[i][j][k][ii][jj] = mmp(INF,INF,INF);
                    }
                }
            }
        }
    }
    rep(i,4){
        rep(j,4){
            dp[0][0][0][i][j] = (mmp(0,INF,INF));
        }
    }

    rep(i,51){
        rep(j,51){
            rep(k,51){
                for(int ii = 0;ii < 4;ii++){
                    for(int jj =0 ;jj < 4 ;jj++){
                        int now = dp[i][j][k][ii][jj].first.first;
                        int l1 = dp[i][j][k][ii][jj].first.second;
                        int l2 = dp[i][j][k][ii][jj].second;
                        int minn1 = min(l1,ii);
                        int minn2 = min(l2,jj);
                        int iii = min(ii+1,3);
                        int jjj = min(jj+1,3);
                        if(minn1 >= 0){
                            if(minn2 >= 0){
                                dp[i][j][k][iii][jjj] = min(dp[i][j][k][iii][jjj],mmp(now+1,l1,l2));
                            }
                            if(minn2 >= 1){
                                dp[i+1][j][k][iii][0] = min(dp[i+1][j][k][iii][0],mmp(now+1,l1,1));
                            }
                            if(minn2 >= 2){
                                dp[i][j+1][k][iii][0] = min(dp[i][j+1][k][iii][0],mmp(now+1,l1,2));
                            }
                            if(minn2 >= 3){
                                dp[i][j][k+1][iii][0] =  min(dp[i][j][k+1][iii][0],mmp(now+1,l1,3));
                            }
                        }
                        if(minn1 >= 1){
                            if(minn2 >= 0){
                                dp[i+1][j][k][0][jjj] = min(dp[i+1][j][k][0][jjj],mmp(now+1,1,l2));
                            }
                            if(minn2 >= 1){
                                dp[i+2][j][k][0][0] = min(dp[i+2][j][k][0][0],mmp(now+1,1,1));
                            }
                            if(minn2 >= 2){
                                dp[i+1][j+1][k][0][0] = min(dp[i+1][j+1][k][0][0],mmp(now+1,1,2));
                            }
                            if(minn2 >= 3){
                                dp[i+1][j][k+1][0][0] =  min(dp[i+1][j][k+1][0][0],mmp(now+1,1,3));
                            }
                        }
                        if(minn1 >= 2){
                            if(minn2 >= 0){
                                dp[i][j+1][k][0][jjj] = min(dp[i][j+1][k][0][jjj],mmp(now+1,2,l2));
                            }
                            if(minn2 >= 1){
                                dp[i+1][j+1][k][0][0] = min(dp[i+1][j+1][k][0][0],mmp(now+1,2,1));
                            }
                            if(minn2 >= 2){
                                dp[i][j+2][k][0][0] = min(dp[i][j+2][k][0][0],mmp(now+1,2,2));
                            }
                            if(minn2 >= 3){
                                dp[i][j+1][k+1][0][0] =  min(dp[i][j+1][k+1][0][0],mmp(now+1,2,3));
                            }
                        }
                        if(minn1 >= 3){
                            if(minn2 >= 0){
                                dp[i][j][k+1][0][jjj] = min(dp[i][j][k+1][0][jjj],mmp(now+1,3,l2));
                            }
                            if(minn2 >= 1){
                                dp[i+1][j][k+1][0][0] = min(dp[i+1][j][k+1][0][0],mmp(now+1,3,1));
                            }
                            if(minn2 >= 2){
                                dp[i][j+1][k+1][0][0] = min(dp[i][j+1][k+1][0][0],mmp(now+1,3,2));
                            }
                            if(minn2 >= 3){
                                dp[i][j][k+2][0][0] =  min(dp[i][j][k+2][0][0],mmp(now+1,3,3));
                            }
                        }



                    }
                }
            }
        }
    }
    int q;
    scanf("%d",&q);
    while(q--){
        int n,m,k;
        scanf("%d%d%d",&n,&m,&k);
        int ans = INF;
        rep(i,4){
            rep(j,4){
                ans = min(dp[n][m][k][i][j].first.first,ans);
            }
        }
        printf("%d\n",ans);
    }


    return 0;
}

