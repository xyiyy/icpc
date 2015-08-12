#include "../../xyiyy/lib.hpp"
#define gao() out<<"NO"<<endl
vector<int>ans[11];
int used[50];
int a[50];
ll tot;
class hdu5355 {
public:
    int ave;
		void solve(std::istream& in, std::ostream& out) {
			int n,m;
			in >> n >> m;
			tot = (ll)(n+1) * n / 2;
            if(tot % m!=0){
                gao();
                return;
            }
            int tmp = tot / m;
            if(n<2*m-1){
                gao();
                return;
            }
            int num = n / m;
            if(tmp == n){
                out<<"YES"<<endl;
                out<<1<<" "<<n<<endl;
                rep(i,m-1){
                    out<<2<<" "<<i+1<<" "<<n-i-1<<endl;
                }
                return;
            }
            if(m==1){
                out<<"YES"<<endl;
                out<<n;
                rep2(i,1,n)out<<" "<<i;
                out<<endl;
                return ;
            }
            rep2(i,1,m)ans[i].clear();
            int c =  (n+1-m*2)%(m*2)+m*2 -1;
            int d = (n-c)/(2*m);
            for(int i=1,j =c + 1;i<=m;i++){
                rep(k,d)ans[i].pb(j++),ans[i].pb(n--);
            }
            tot = n;
            n = c;
            ave = (ll)(1 + n) * n / 2 / m;
            set<int>s;
            rep2(i,1,n)s.insert(i);
            rep2(i,1,m){
                rep(j,ave){
                    auto  it = s.upper_bound(ave - j);
                    ans[i].pb(*--it);
                    j+= *it;
                    s.erase(it);
                    j--;
                }
            }
            out<<"YES"<<endl;
            rep2(i,1,m){
                int sz = ans[i].size();
                out<<sz;
                rep(j,sz){
                    out<<" "<<ans[i][j];
                }
                out<<endl;
            }
		}
    bool dfs(int num,int now,int u,int m){
        if(now==0){
            int i = tot;
            while(used[i])i--;
            used[i] = m;
            if(dfs(num+1,i,i-1,m))return 1;
            used[i] = 0;
            return 0;
        }
        if(now == ave){
            if(num == tot)return 1;
            else return dfs(num,0,tot,m+1);
        }
        for(int i=u;i>0;i--){
            if(!used[i]&&now + i<=ave){
                used[i] = m;
                if(dfs(num+1,now + i,i-1,m))return 1;
                used[i] = 0;
            }
        }
        return false;
    }
    bool dfs(int m,int n,int tot,int num,int now){
        if(!m){
            return  1;
        }
        if(tot = ave){
            if(dfs(m-1,n,0,num,0))return 1;
        }
        if(tot==0){
            int i = n;
            while(used[i])i--;
            used[i] = m;
            if(dfs(m,n,tot+i,num+1,i))return  1;
            used[i] = 0;
            return 0;
        }
        for(int i=now;i>0;i--){
            if(!used[i] && tot + i <= ave){
                used[i] = m;
                if(dfs(m,n,tot+i,num+1,i-1))return 1;
                used[i] = 0;
            }
        }
        return false;
    }
    void run(int x){
        rep2(i,1,x)ans[i].clear();
        if(x==3){
            int a[9] = {1,2,3,3,1,2,2,3,1};
            x *=3;
            rep(i,x){
                ans[a[i]].pb(i+1);
            }
        }else if(x==5){
            int a[15] = {1,3,4,5,2,5,2,1,3,4,4,2,3,5,1};
            x *=3;
            rep(i,x){
                ans[a[i]].pb(i+1);
            }

        }else if(x==7){
            int a[21] = {1,4,6,7,3,5,2,5,2,4,7,1,3,6,3,6,2,7,5,1,4};
            x *=3;
            rep(i,x){
                ans[a[i]].pb(i+1);
            }
        }else if(x==9){
            int a[27] = {1,5,7,6,9,3,8,4,2,
                         3,6,8,2,7,4,9,1,5,
                         4,2,9,5,8,1,7,3,6};
            x *=3;
            rep(i,x){
                ans[a[i]].pb(i+1);
            }
        }
    }

};