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
typedef vector<PII> vii;
typedef vector<int> vi;
int key[MAXN],size[MAXN],lson[MAXN],rson[MAXN];
int sum[MAXN],p[MAXN],del[MAXN];
int tot=0,tot1=0;
void init(){
    key[0] = size[0] = lson[0] = rson[0] = 0;
    tot = tot1 = 0;
}
int newnode(int k){
    int r ;
    if(tot1){
        r = del[tot1--];
    }else r = ++tot;
    key[r] = k;
    sum[r] = k;
    p[r] = rand();
    size[r] = 1;
    lson[r] = rson[r] = 0;
    return r;
}

int change(int t,int l,int r){
    size[t] = size[l] + size[r] + 1;
    sum[t] = sum[l] + sum[r] + key[t];
    lson[t] = l;
    rson[t] = r;
    return t;
}

void splitsize(int t,int s,int *ret){
    if(s<=0){
        ret[0] = 0;
        ret[1] = t;
    }else if(s<=size[lson[t]]){
        splitsize(lson[t],s,ret);
        ret[1] = change(t,ret[1],rson[t]);
    }else{
        splitsize(rson[t],s-size[lson[t]]-1,ret);
        ret[0] = change(t,lson[t],ret[0]);
    }
}
void splitkey(int t,int k,int *ret){
    if(!t){
        ret[0] = ret[1] = 0;
    }else if(kA<key[t]){
        splitkey(lson[t],k,ret);
        ret[1] = change(t,ret[1],rson[t]);
    }else{
        splitkey(rson[t],k,ret);
        ret[0] = change(t,lson[t],ret[0]);
    }
}
int merge(int t1,int t2){
    if(!t1)return t2;
    if(!t2)return t1;
    if(p[t1]<p[t2])return change(t1,lson[t1],merge(rson[t1],t2));
    return change(t2,merge(t1,lson[t2]),rson[t2]);
}

int main()
{
    ios::sync_with_stdio(false);




    return 0;
}

