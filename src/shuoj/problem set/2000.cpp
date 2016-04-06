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
char a[20];
char b[20];
int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        int now = 9;
        int len = str.length();
        rep(i,10)a[i] = '0';
        dep(i,len-1,0){
            a[now] = str[i];
            now--;
        }
        ll ans = 1LL << 40;
        rep(i,10){
            rep2(j,i+1,9){
                rep2(k,j+1,9){
                    rep(l,10)b[l] = a[l];
                    b[i] = b[j] = b[k] = '8';
                    int num = (b[i] - '0') * 100 + (b[j] - '0') * 10 + b[k] - '0';
                    int init = (a[i] - '0') * 100 + (a[j] - '0') * 10 + a[k] - '0';
                    int x = 10;
                    ll temp = 0;
                    if(num >= init){
                        bool flag = 0;
                        if(num > init)flag = true;
                        if(b[i] > a[i])x = i;
                        else if(b[j] > a[j])x = j;
                        else if(b[k] > a[k])x = k;
                        else x = k;
                        rep(l,x){
                            if(b[l] == '8' && l !=i && l != j && l != k)b[l] = b[l] + 1,flag = 1;
                           // else b[l] = a[l];
                        }
                        rep2(l,x+1,9){
                            if(l == j || l == k)continue;
                            if(flag)b[l] = '0';
                            else if(b[l] == '8')b[l] = b[l] + 1,flag = 1;
                           // else b[l] = a[l];
                        }
                    }else{
                        if(b[i] < a[i])x = i - 1;
                        else if(b[j] < a[j]) x = j - 1;
                        else if(b[k] < a[k]) x = k - 1;
                        else x = k - 1;
                        while(x==i||x==j||x==k)x--;
                        int y = x + 1;
                        b[x]++;
                        while(b[x] - '0' ==10){
                            b[x] -= 10;
                            int p = x;
                            bool flag = 0;
                            x--;
                            while(x == i || x == j || x == k){
                                rep2(l,x+1,9){
                                    if(x == i || x == j || x == k)break;
                                    b[l] = '0';
                                }
                                y = x;
                                x--;
                            }
                            b[x]++;
                        }
                        rep2(l,y,9){
                            if(l == i || l == j || l == k)continue;
                            else b[l] = '0';
                        }
                    }
                    rep(l,10)temp = temp * 10 + b[l] - '0';
                    ans = min(ans,temp);
                }
            }
        }
        cout << ans << endl;
    }



    return 0;
}
