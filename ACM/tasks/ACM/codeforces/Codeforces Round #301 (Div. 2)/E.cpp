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
map<int,int>ms;
int c[500010];
int d[500010];
ll bit[500010],j;
map<int,int>m;
ll sum(int i){
    ll s=0;
    while(i>0){
        s+=bit[i];
        i-=i&-i;
    }
    return s;
}
void add(int i,ll x){
    while(i<=j){
        bit[i]+=x;
        i+=i&-i;
    }
}
int main()
{
	ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int a,b;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        if(!ms.count(a)&&!ms.count(b)){
            ms[a]=b;
            ms[b]=a;
        }
        else if(ms.count(a)&&!ms.count(b)){
            ms[b]=ms[a];
            ms[a]=b;
        }
        else if(!ms.count(a)&&ms.count(b)){
            ms[a]=ms[b];
            ms[b]=a;
        }else{
            swap(ms[a],ms[b]);
        }
    }
    ll ans=0;
    for(map<int,int>::iterator it=ms.begin();it!=ms.end();it++){
        c[j]=it->first;
        d[j++]=it->second;
    }
    sort(c,c+j);
    for(int i=0;i<j;i++){
        m[c[i]]=i+1;
    }
    for(int i=0;i<j;i++){
        if(ms[c[i]]>c[i]){
            int tx = m[ms[c[i]]]-m[c[i]];
            ans+=ms[c[i]]-c[i]-tx;
        }else if(ms[c[i]]<c[i]){
            int tx= m[c[i]]-m[ms[c[i]]];
            ans+=c[i]-ms[c[i]]-tx;
        }
    }
    for(int i=0;i<j;i++){
        ans+=i-sum(m[d[i]]);
        add(m[d[i]],1);
    }
    cout<<ans<<endl;

	return 0;
}



