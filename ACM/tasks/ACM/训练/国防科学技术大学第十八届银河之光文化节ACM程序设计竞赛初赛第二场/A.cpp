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
string s="alpc";
int main()
{
	ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        int len = str.length();
        int a=0;
        int ans=0;
        for(int i=0;i<len;i++){
                a=0;
            for(int j=0;j<4&&i+j<len;j++){
                if(str[i+j]==s[j])a++;
            }
            if(a==4)ans++;
        }
        cout<<ans<<endl;
    }
	return 0;
}


