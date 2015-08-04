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
int a[10010];
int lx[1010];
int rx[1010];
string str[10100];
int main()
{
	ios::sync_with_stdio(false);
    int t;
    cin>>t;
    int cas=0;
    while(t--){
        int n;
        cin>>n;
        priority_queue<PII,VII,greater<PII> >q;
        for(int i=0;i<n;i++){
            cin>>a[i];
            q.push(MP(a[i],-i));
        }
        int now = n;
        while(q.size()>1){
            PII p1 = q.top();
            q.pop();
            PII p2 = q.top();
            q.pop();
            rx[now] = -p1.second;
            lx[now] = -p2.second;
            q.push(MP(p1.first+p2.first,-now));
            now++;
        }
        for(int i=0;i<now;i++)str[i]="";
        for(int i=now-1;i>=n;i--){
            str[lx[i]]=str[i]+"0";
            str[rx[i]]=str[i]+"1";
        }
        if(cas)cout<<endl;
        cout<<"Case "<<++cas<<endl;
        for(int i=0;i<n;i++){
            cout<<a[i]<<" "<<str[i]<<endl;
        }
    }
	return 0;
}


