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
string domain = "moc.liamb@";
map<string,int>ms;
const int MAXN = 20010;
vector<string>G[MAXN];'
int main()
{
    ios::sync_with_stdio(false);
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
    #endif // LOCAL
    int n;
    cin>>n;
    int domainlen = domain.length();
    int num = 0 ;
    rep(i,n){
        cin>>str;
        int len = str.length();
        int f = 0;
        string tmp = str;
        string s = "";
        rep(j,len){
            if(tmp[j]>='A' && tmp[j] <= 'Z'){
                tmp[j] -= 'A' - 'a';
            }
        }
        for(int j=0;j<domainlen;j++){
            if(tmp[len-1-j]!=domain[j]){
                f = 1;
            }
        }
        if(!f){
            rep(j,len){
                if(tmp[j]=='+'||tmp[j]=='@')break;
                else if(tmp[j]=='.')continue;
                else s+= tmp[j]
            }
            s+= domain;
        }else{
            rep(j,len){
                if(tmp[j]=='.')continue;
                else s+= tmp[j];
            }
        }
        if(!ms.count(s)){
            ms.insert(mp(s,num));
            num++;
        }else{

        }


    }

    return 0;
}
