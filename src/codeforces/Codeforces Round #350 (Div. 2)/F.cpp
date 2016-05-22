//#####################
//Author:fraud
//Blog: http://www.cnblogs.com/fraud/
//#####################
//#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>
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
typedef vector<PII> VII;
typedef vector<int> VI;
string str;
string s;
string ss;
string ans;
int a[110];
int b[10];
int len;
bool check(int x){
    rep(i,10)b[i] = 0;
    int num = x;
    while(x){
        b[x % 10] ++;
        x /= 10;
        num++;
    }
    if(num != len)return false;
    rep(i,10){
        if(b[i] > a[i])return false;
    }
    return true;
}
int main()
{
    ios::sync_with_stdio(false);
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
    #endif // LOCAL
    while(cin >> str >> s){
        //int len = str.length();
        clr(a,0);
        len = s.length();
        rep(i,len){
            a[s[i] - '0']--;
        }
        bool flag = false;
        if(s[0] == '0')flag = true;
        len = str.length();
        rep(i,len){
           a[str[i] - '0']++;
        }

        int n;
        int m = s.length();
        rep2(i,1,len){
            if(check(i)){
                if(i == 1){
                    n = i;
                    rep(j,10)a[j] -= b[j];
                    break;
                }
                if(flag){
                    bool ok = false;
                    rep2(j,1,9){
                        if(a[j] > b[j])ok = true;
                    }
                    if(ok){
                        rep(j,10)a[j] -= b[j];
                        n = i;
                        break;
                    }
                }else{
                    n = i;
                    rep(j,10)a[j] -= b[j];
                    break;
                }
            }
        }
        //cout << n << endl;
        if(flag){
            rep2(i,1,9){
                if(a[i]){
                    a[i]--;
                    cout << i;
                    break;
                }
            }
            bool used = false;
            rep(i,10){
                ss = "";
                while(a[i]){
                    a[i]--;
                    ss += '0' + i;
                }
                if(used){
                    cout <<ss;
                    continue;
                }
                if(ss < s)cout << ss;
                else{
                    used = true;
                    cout << s << ss ;
                }
            }
            if(!used)cout << s;
            cout << endl;
        }else{
            ss = "";
            rep2(i,1,9){
                if(a[i]){
                    a[i]--;
                    ss = i + '0';
                    rep(j,10){
                        while(a[j]){
                            ss += j + '0';
                            a[j]--;
                        }
                    }
                    break;
                }
            }
            bool used = false;
            if(ss.length()!= 0 && ss < s)cout << ss;
            else{
                cout << s;
                rep(i,ss.length())a[ss[i] - '0']++;
                used = true;
            }
            rep(i,10){
                ss = "";
                while(a[i]){
                    a[i]--;
                    ss += '0' + i;
                }
                if(used){
                    cout << ss;
                    continue;
                }
                if(ss < s)cout << ss;
                else{
                    cout << s << ss ;
                    used = true;
                }
            }
            if(!used)cout << s;
            cout << endl;
        }

    }
    return 0;
}

