
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
string str;
char op[]={'+','-','*','/'};
bool isop(char c){
    rep(i,4){
        if(c == op[i])return true;
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        getline(cin,str,'\n');
        int len = str.length();
        if(!len){
            t++;
            continue;
        }
        ll N = 0;
        rep(i,len){
            if(isop(str[i])){
                cout << " " << str[i] << " ";
            }else if(str[i] == '(' || str[i] == ')'){
                cout << str[i];
            }else if(str[i] == 'd'){
                string x = "";
                int j;
                for(j = i + 1; j<len;j++){
                    if(!isdigit(str[j]))break;
                    x = x + str[j];
                }
                i = j - 1;
                if(N == 1 || N == 0){
                    cout << "[d" << x << "]";
                }else{
                    cout << "(";
                    rep(k,N){
                        if(k)cout << " + ";
                        cout << "[d" << x << "]";
                    }
                    cout << ")";
                }
                N = 0;
            }else if(isdigit(str[i])){
                string x = "";
                int j;
                for(j = i; j < len; j++){
                    if(!isdigit(str[j]))break;
                    x = x + str[j];
                }
                i = j - 1;
                if(j == len || str[j] != 'd'){
                    cout << x;
                }else{
                    int xlen = x.length();
                    rep(k,xlen){
                        N = N * 10 + x[k] - '0';
                    }
                }
            }
        }
        cout << " = [Result]" << endl;
    }
    return 0;
}
