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



int main()
{
    ios::sync_with_stdio(false);
    #ifdef LOCAL
       // freopen("in.txt","r",stdin);
    #endif // LOCAL
    int num ;
    //cout << 365%7<<endl;
    string str1;
    string str;
    while(cin>>num>>str1>>str){
        if(str=="week"){
            if(num==5||num==6)cout << 53<<endl;
            else cout << 52<<endl;

        }else{
            if(num<=29)cout << 12<<endl;
            else if(num==30)cout << 11<<endl;
            else cout << 7<<endl;
        }
    }
    return 0;
}
