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
string str;
int a[1010];
bool cmp(int x,int y){
    cout << x <<" "<<y << endl;
    cout.flush();
    cin>>str;
    return str == "YES";
}
int main()
{
    int n;
    cin>>n;
    rep(i,n)a[i+1] = i+1;
    stable_sort(a+1,a+n+1,cmp);
    rep(i,n){
        if(i)cout <<" ";
        cout <<a[i+1];
    }
    cout << endl;
    return 0;
}

