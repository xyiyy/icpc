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
int main()
{
    ios::sync_with_stdio(false);
    cin >> str;
    int len = str.length();
    int sum = 0;
    rep(i,len){
        sum += str[i] - '0';
    }
    if(sum % 3 == 0){
        int i;
        int p = sum / 3;
        int gao = 0;
        for(i = 0 ; i < len ;i ++ ){
          //  if(p){
         // cout << p << endl;
                if(p + (int)'0'>=(int)str[i]){
                    cout << str[i];
                    p -= str[i] - '0';
                    str[i] = '0';
                }else{
                    str[i] -= p;
                    cout << p;
                    p = 0;
                }
          //  }
          //cout << p << endl;
        }
        cout << " ";
        i = 0;
        while(str[i]=='0')i++;
        p = sum / 3;
        for(;i<len;i++){
           // if(p){
                if(p + (int)'0'>=(int)str[i]){
                    cout << str[i];
                    p -= str[i] - '0';
                    str[i] = '0';
                }else{
                    cout << p;
                    str[i] -= p;
                    p = 0;
                }
          //  }
        }
        cout << " ";
        i = 0;
        while(str[i]=='0')i++;
        p = sum / 3;
        for(;i<len;i++){
           // if(p){
                if(p + (int)'0'>=(int)str[i]){
                    cout << str[i];
                    p -= str[i] - '0';
                    str[i] = '0';
                }else{
                    cout << p;
                    str[i] -= p;
                    p = 0;
                }
          //  }
        }
        cout << endl;


    }else cout << -1 <<endl;
    return 0;
}

