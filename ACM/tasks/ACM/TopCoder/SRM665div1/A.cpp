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
typedef vector<PII> VII;
typedef vector<int> VI;
string ans;
string str;
bool ok;
bool dfs(int now,int f,int gao){
    if(now==-1&&f==0){
        if(str[0]=='0')return 0;
        ans = min(str,ans);
        ok = 1;
        return 1;
    }
    if(now==0){
        if(str[0]=='?'){
            if(f){
                str[now] ='1';
            }else str[now]='4';
            dfs(now-1,0,0);
        }
        else{
            if(f)str[now]--;
            if(f&&(str[now]=='1'||str[now]=='5'||str[now]=='8'||str[now]=='9'))dfs(now-1,0,0);
            else if(!f){
                if(str[now]=='8'||str[now]=='4'||str[now]=='7')dfs(now-1,0,0);
            }
        }
        return 0;
    }
    if(gao){
        int p = (str[now]=='?');
        int ff = 0;
        int num ;
        if(!p)num = str[now] - '0';
        if(f&&!p)num--;
        if(!p){
            if(num==1||num==4)dfs(now-1,1,1);
            if(num==4||num==7)dfs(now-1,0,0);
            else if(num==8)dfs(now-1,0,1);
        }else{
            str[now] = '1'+f;
            dfs(now-1,1,1);
            str[now] = '4' + f;
            dfs(now-1,1,1);
            dfs(now-1,0,0);
            str[now] = '7' + f;
            dfs(now-1,0,0);
            str[now] = '8' +f;
            dfs(now-1,0,1);
            str[now] = '?';
        }
    }//else{
    if(f||now == str.length()-1)return 0;
    int p = (str[now]=='?');
    int num;
    if(!p)num = str[now]-'0';
    if(!p){
        if(num==4||num==7)dfs(now-1,0,0);
    }else{
        str[now] = '4';
        dfs(now-1,0,0);
        str[now] = '?';
    }
    return 0;

}
class  LuckySum{
public:
    long long construct(string note){
        int len = note.length();
        ans = "999999999999999";
        if(note=="?"||note=="8")return 8;
        if(len==1)return -1;
        str = note;
        dfs(len-1,0,1);
        ll p =0 ;
        rep(i,len){
            p = p*10 + ans[i]-'0';
        }
        if(!ok)return -1;
        else
        return p;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    LuckySum *p = new LuckySum();
    string tmp;
    while(cin>>tmp){
        cout<<p->construct(tmp)<<endl;
    }

    return 0;
}
