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
#define MP(X,Y,Z) make_pair(X,make_pair(Y,Z));
#define PB(X) push_back(X)
#define REP(X,N) for(int X=0;X<N;X++)
#define REP2(X,L,R) for(int X=L;X<=R;X++)
#define DEP(X,R,L) for(int X=R;X>=L;X--)
#define CLR(A,X) memset(A,X,sizeof(A))
#define IT iterator
typedef long long ll;
typedef pair<int,pair<int,int> > PII;
typedef vector<PII> VII;
typedef vector<int> VI;

int a[100010],b[100010];
int p[100010];
int Id[100010];
int gao[1000010];
bool cmp(int x,int y){
    if(b[x]==b[y])return a[x]>a[y];
    return b[x]>b[y];
}
bool cmp1(int x,int y){
    if(b[x]==b[y])return a[x]>a[y];
    return b[x]<b[y];
}
bool cmp2(int x,int y){
    if(a[x]==a[y])return b[x]>b[y];
    return a[x]>a[y];
}
int main(){
    ios::sync_with_stdio(false);
    int n,fu,k;
    cin>>n>>fu>>k;
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
        p[i]=i;
    }
    sort(p,p+n,cmp1);
    for(int i=fu-k;i<n;i++){
        Id[i-fu+k]=p[i];
    }
    for(int i=0;i<n;i++){
        gao[p[i]]=i;
    }
    int cao=n-1;
    sort(Id,Id+n-(fu-k),cmp2);
    for(int i=0;i<k;i++){
        cout<<Id[i]+1<<" ";
        cao=min(cao,gao[Id[i]]);
    }
    for(int i=0;i<fu-k;i++){
        cout<<p[cao-1-i]+1<<" ";
    }
    cout<<endl;
    /*priority_queue<PII,vector<PII>,greater<PII> > q;
    for(int i=0;i<k;i++){
            PII cao =MP(a[p[i]],b[p[i]],p[i]);
            q.push(cao);
    }
    int maxx=k-1;
    for(int i=k;i<n-(fu-k);i++){
        PII cao =q.top();
        PII tmp=MP(a[p[i]],b[p[i]],p[i]);
        if(cao<tmp){
            q.pop();
            q.push(tmp);
            maxx=max(maxx,i);
        }
    }
    int t=maxx;
    while(t<n){
        if(b[p[t]]!=b[p[maxx]])break;
        t++;
    }
    while(!q.empty()){
        PII cao=q.top();
        q.pop();
        cout<<cao.second.second+1<<" ";
    }
    if(n-t>=fu-k){
        for(int i=0;i<fu-k;i++){
            cout<<p[t+i]+1<<" ";
        }
    }else{
        for(int i=0;i<fu-k&&i+t<n;i++){
            cout<<p[t+i]+1<<" ";
        }
       // cout<<t<<endl;
        for(int i=1;i<=fu-(n-t)-k;i++){
            cout<<p[maxx+i]+1<<" ";
        }
    }
   // for(int i=1;i<=fu-k;i++){
   //     cout<<p[maxx+i]+1<<" ";
   // }*/




    return 0;
}
