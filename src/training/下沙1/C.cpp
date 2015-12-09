
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
string str;
struct node{
    string s;
    int inx;
    friend bool operator <(const node &a,const node &b){
        return a.s>b.s;
    }
};
priority_queue<node>q;
int main()
{
	ios::sync_with_stdio(false);
    cin>>str;
    int k;
    cin>>k;
    int len = str.length();
    node x;
    for(int i=0;i<len;i++){
        x.s=str[i];
        x.inx=i;
        q.push(x);
    }
    if(len<10000&&len*(len+1)/2<k){
        cout<<"No such line."<<endl;
        return 0;
    }
    while(!q.empty()){
        x = q.top();
        q.pop();
        k--;
        if(!k)break;
        x.inx++;
        if(x.inx<len){
            x.s=x.s+str[x.inx];
            q.push(x);
        }
    }
    cout<<x.s<<endl;


	return 0;
}



