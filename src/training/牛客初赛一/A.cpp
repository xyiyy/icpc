//#####################
//Author:fraud
//Blog: http://www.cnblogs.com/fraud/
//#####################
//#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>
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
typedef vector<PII> VII;
typedef vector<int> VI;

vector<int> gao(vector<int>A,int n,int Q,vector<int>l,vector<int>r,vector<int>k){
    int B[1001];
    vector<int>res;
    for(int i=0;i<l.size();i++){
        int j = 0;
        for(int st=l[i];st<=r[i];st++){
                j++;
            B[j] = A[st];
        }
        sort(B+1,B+j+1);
        res.push_back(B[j-(k[i]-(k[i]+1)/2)]);
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(false);
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
    #endif // LOCAL
    vector<int>A,l,r,k;
    for(int i=1;i<=5;i++)A.push_back(i);
    for(int i=0;i<3;i++)l.push_back(i);
    for(int i=1;i<=3;i++)r.push_back(i),k.push_back(i);
    k[2] = 2;
    gao(A,5,3,l,r,k);

    return 0;
}

