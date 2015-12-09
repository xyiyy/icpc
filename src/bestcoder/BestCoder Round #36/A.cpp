//#####################
//Author:fraud
//Blog: http://www.cnblogs.com/fraud/
//#####################
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
int vis[1010];
int num[1010];
int main()
{
    ios::sync_with_stdio(false);
    string s;
    while(cin>>s){
        int len=s.length();
        CLR(vis,0);
        CLR(num,0);
        int ans=1;
        int cs=0;
        int k=len/3;
        if(k*3!=len)ans=0;if(ans){
        char str=s[0];
        for(int i=0;i<k;i++){
            if(s[i]!=str)ans=0;
        }
        str=s[k];
        if(s[k]==s[k-1])ans=0;
        for(int i=k;i<len-k;i++){
            if(s[i]!=str)ans=0;
        }
        str=s[len-k];
        if(str==s[len-k-1])ans=0;
        if(str==s[0])ans=0;
        for(int i=len-k;i<len;i++){
            if(s[i]!=str)ans=0;
        }
        }
        if(ans)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        
        /*for(int i=0;i<len;i++){
            if(!vis[s[i]]){
                vis[s[i]]=1;
                num[s[i]]++;
                cs++;
            }
            else num[s[i]]++;
        }
        int t=num[s[0]];
        if(cs!=3){
            ans=0;
        }
        else{
            for(int i=0;i<310;i++){
                if(num[i]!=0&&num[i]!=t)ans=0;
            }
        }*/
        //if(ans)cout<<"YES"<<endl;
        //else cout<<"NO"<<endl;
    }
            
    return 0;
}

