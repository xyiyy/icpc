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
int a[10];
int m[5][5];
int temp[10][10];
int ans[10][10];
bool check(){
    int ret = 0;
    rep(i,3)ret += temp[i][0];
    rep(i,3){
        int sum = 0 ;
        rep(j,3){
            sum += temp[i][j];
        }
        if(sum != ret){
            return false;
        }
        sum = 0 ;
        rep(j,3){
            sum += temp[j][i];
        }
        if(sum!=ret)return false;
    }
    int sum = 0;
    rep(i,3)sum += temp[i][i];
    if(sum != ret)return false;
    sum = 0 ;
    rep(i,3)sum += temp[i][2-i];
    if(sum != ret )return false;
    return true;
}
int main()
{
    ios::sync_with_stdio(false);
    for(int i =0 ; i < 9;i++)a[i] = i + 1;
    rep(i,3){
        rep(j,3){
            cin >> m[i][j];
        }
    }
    int num = 0;
    do{
        rep(i,3){
            rep(j,3){
                temp[i][j] = m[i][j];
            }
        }
        bool ok = true;
        for(int i = 0 ; i < 9;i++){
            int r = i / 3;
            int c = i % 3;
            if(temp[r][c] == 0){
                temp[r][c ] = a[i];
            }else{
                if(temp[r][c]!=a[i]){
                    ok = false;
                }
            }
        }
        if(ok == false)continue;
        if(check()){
            num++;
            rep(i,3){
                rep(j,3){
                    ans[i][j] = temp[i][j];
                }
            }
        }
    }while(next_permutation(a,a+9));
    if(num == 1){
        rep(i,3){
            rep(j,3){
                if(j)cout << " ";
                cout << ans[i][j];
            }
            cout << endl;
        }
    }else{
        cout << "Too Many"<<endl;
    }
    return 0;
}

