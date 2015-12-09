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
string s1,s2,str,gs;
set<string>s;
int main()
{
    ios::sync_with_stdio(false);
    int t;
    int cas = 1;
    cin>>t;
    while(t--){
        int c;
        s.clear();
        cin>>c;
        cin>>s1;
        cin>>s2;
        cin>>gs;
        str=s1+s2;
        int ans = 1;
        while(1){
            int tot = 0;
            for(int i=0;i<c;i++){
                str[tot++] = s2[i];
                str[tot++] = s1[i];
            }
            if(str==gs){
                cout<<cas++<<" "<<ans<<endl;
                break;
            }else if(s.count(str)){
                cout<<cas++<<" "<<-1<<endl;
                break;
            }
            s.insert(str);
            ans++;
            s1 = str.substr(0,c);
            s2 = str.substr(c,str.length());
            //cout<<s1<<" "<<s2<<endl;
        }
    }
    return 0;
}
