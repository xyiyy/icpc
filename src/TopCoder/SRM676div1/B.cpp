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
int n,m;
char a[110][110];
int d1x[4] = {-1,0,0,1};
int d1y[4] = {0,-1,1,0};
int d2x[8] = {-2,-1,-1,0,0,1,1,2};
int d2y[8] = {0,-1,1,-2,2,-1,1,0};
bool in(int x,int y){
    if(x<0||x>=n||y<0||y>=m||a[x][y]=='#')return 0;
    return 1;
}


class  BoardEscape{
public :
    string findWinner(vector <string> s, int z){
        n = s.size();
        m = s[0].length();
        rep(i,n)
        rep(j,m)a[i][j] = s[i][j];
        int num =0;
        int gao1 = 0;
        int gao2 = 0;
        int gao12 = 0;
        int gao =0;
        //int gao3 = 0;
        int gao01 = 0;
        rep(i,n){
            rep(j,m){
                if(a[i][j]!='T')continue;
                int ok1 = 0;
                int dx = i;
                int dy = j;
                int p1 = 0;
                int p2 = 0;
                int ok2 = 0;
                rep(k,4){
                    int tx = dx + d1x[k];
                    int ty = dy + d1y[k];
                    if(in(tx,ty)){
                        ok1++;
                        if(a[tx][ty]=='E')p1++;
                        else{
                            rep(kk,4){
                                int px = tx + d1x[kk];
                                int py = ty + d1y[kk];
                                if(in(px,py)){
                                    if(a[px][py]!='E')p2++;
                                }
                            }
                            if(p2==0)ok2 ++;
                        }
                    }
                }
               // cout << p1 << ok2 << endl;
                if(ok1)num++;
                if(p1==ok1&&ok1)gao1 ++;
                else if(!p1&&ok2)gao++;
                else if(p1&&!ok2)gao01++;
                //else if(p1==ok1)gao1++;
                else if(p1&&ok2)gao12++;
                else if(!p1&&!ok2)gao2++;
                //if(p1==ok1)gao1++;
                //else

            }
        }
        string ans;
        if(z==1){
            if(num&1)ans = "Alice";
            else ans = "Bob";
        }else{
            cout << "1    "<< gao1 << endl;
            cout << "2    "<< gao2 << endl;
            cout << "12    "<< gao12 << endl;
            cout << "3    "<< gao << endl;

            ll sum = z;
            sum = sum * gao;
            sum %=2;
            sum += gao1;
            sum %=2;
            if(sum&1)ans = "Alice";
            else ans = "Bob";
        }
        return ans;

    }
};

int main()
{
    ios::sync_with_stdio(false);
    #ifdef LOCAL
        //freopen("in.txt","r",stdin);
    #endif // LOCAL
    vector<string >s;
    string str;
    cin>>str;
    s.pb(str);
    int k;
    cin>>k;//cou
    BoardEscape *t = new BoardEscape();
    cout << t->findWinner(s,k) << endl;;
    //cout << 1000000000<<endl;

    return 0;
}

