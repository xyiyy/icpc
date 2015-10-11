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
int num[100010];

void extgcd(ll a,ll b,ll &d,ll & x,ll &y){
    if(!b){d = a;x = 1; y = 0;}
    else {
        extgcd(b,a%b,d,y,x);y-=x*(a/b);
    }
}

ll china(int n,int *a,int *m){
    ll M = 1,d,y,x = 0;
    rep(i,n)M*=m[i];
    rep(i,n){
        ll w = M/m[i];
        extgcd(m[i],w,d,d,y);
        x = (x + y * w * a[i]) % M;
    }
    return (x+M)%M;
}


int main()
{
    ios::sync_with_stdio(false);
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
    #endif // LOCAL
    int n,c;
    scanf("%d%d",&n,&c);
    rep(i,n-1)scanf("%d",&num[i+1]);
    //cin>>n>>c;
    int ff = 0;
    //rep(i,n)cin>>num[i];
    if(c*c*c*n<=50000000){
        rep2(i,0,c-1){
            rep2(a,0,c-1){
                rep2(b,0,c-1){
                    int x = i;
                    int f = 1;
                    rep(j,n-1){
                        x = x * a + b;
                        x %= c;
                        if(x%(j+1)!=num[j+1])f = 0;
                        if(!f)break;
                    }
                    if(f){
                        ff = 1;
                        printf("%d %d %d\n",i,a,b);
                        //cout << i << " " << a << " " << b << endl;
                    }
                }
            }
        }
    }else{

    }


    if(!ff)//cout << "Unsuccessful Hack Attempt"<<endl;
    printf("Unsuccessful Hack Attempt\n");
    return 0;
}

