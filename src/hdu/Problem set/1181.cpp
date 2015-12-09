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
int a[110][110];
int main()
{
    ios::sync_with_stdio(false);
    string str;
    while(cin>>str){
        int len = str.length();
        if(str=="0"){
            cout<<"No."<<endl;
            continue;
        }
        CLR(a,0);
        a[str[0]-'a'][str[len-1]-'a'] = 1;
        while(cin>>str){
            if(str=="0")break;
            len = str.length();
            a[str[0]-'a'][str[len-1]-'a'] = 1;
        }
        for(int k=0;k<26;k++){
            for(int i=0;i<26;i++){
                for(int j=0;j<26;j++){
                    a[i][j]=max(a[i][j],a[i][k]*a[k][j]);
                }
            }
        }
        if(a['b'-'a']['m'-'a'])cout<<"Yes."<<endl;
        else cout<<"No."<<endl;
    }
    return 0;
}
