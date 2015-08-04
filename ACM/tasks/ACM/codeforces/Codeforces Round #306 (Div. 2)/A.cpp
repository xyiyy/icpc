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
bool vis[100010];
string s;
vector<int>a,b;
int main()
{
	ios::sync_with_stdio(false);
	cin>>s;
	int len=s.length();
	for(int i=0;i<len-1;i++){
        if(s[i]=='A'&&s[i+1]=='B'){
            a.PB(i);
        }
	}
	bool flag=0;
	for(int i=0;i<len-1;i++){
        if(s[i]=='B'&&s[i+1]=='A')
            b.PB(i);
	}
	for(int i=0;i<a.size()&&!flag;i++){
        for(int j=0;j<b.size()&&!flag;j++){
            if(abs(a[i]-b[j])!=1){
                flag=1;
            }
        }
	}
	if(flag)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}



