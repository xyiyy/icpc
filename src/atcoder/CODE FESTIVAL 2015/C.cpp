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
char a[30][30];
int main()
{
    ios::sync_with_stdio(false);
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
    #endif // LOCAL
    int n;
    while(cin>>n){
        //int a = 0;
        int ans = 0;
        int num = 0;
        int x  =0;int y = 0;
        rep(k,n){
            rep(i,3){
                cin>>a[i];
                //scanf("%s",a[i]);
                //cout <<a[i];
            }
            int st = 0;
            if(k&1){
                rep(i,3){
                    st<<=1;
                    if(a[i][0]=='#'){
                        st = (st|1);
                    }else num ++;
                }

            }else{
                rep(i,3){
                    st<<=1;
                    if(a[0][i]=='#'){
                        st = (st|1);
                    }else num++;
                }
            }
           // cout << st <<endl;
            if(st == 7)x++;
            else if(st==6||st==3)y++;
        }
       // cout <<x << " "<< y  << " "<<num <<endl;
        string str1,str2;
        if(num&1){
            str1 = "Sothe";
            str2 = "Snuke";
        }else {
            str2 = "Sothe";
            str1 = "Snuke";
        }
       // cout << str1 <<endl;
        if(x%2==0&&y%2==0){
            cout << str2 <<endl;
        }else cout <<str1 <<endl;

    }
    return 0;
}

