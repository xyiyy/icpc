#include "../../../../library/lib.hpp"
typedef pair<PII,int> PIII;
priority_queue<PIII,vector<PIII>,greater<PIII> >q;
int f[100010],l[100010],r[100010];
vector<int>v[100010];
class hdu5360 {
public:
		void solve(std::istream& in, std::ostream& out) {
			int n;
			in>>n;
			for(int i=1;i<=n;i++)in>>l[i];
			for(int i=1;i<=n;i++){
				in>>r[i];
				if(l[i])v[l[i]].pb(i);
				else q.push(mp(mp(r[i],l[i]),i));
			}
			int num = n;
			int ans = 0;
			int sz = 0;
			while(n){
				if(q.empty()){
					rep2(i,ans+1,n){
						rep(j,v[i].size()){
							f[sz++] = v[i][j];
						}
						v[i].clear();
					}
					break;
				}
				PIII p = q.top();
				q.pop();
				int y = p.first.first;
				int x = p.first.second;
				int z = p.second;
				f[sz++] = z;
				if(x<=ans&&y>=ans){
					ans++;
					rep(i,v[ans].size()){
						int j = v[ans][i];
						q.push(mp(mp(r[j],l[j]),j));
					}
					v[ans].clear();
				}
			}
			out<<ans<<endl;
			rep(i,sz){
				if(i)out<<" ";
				out<<f[i];
			}
			out<<endl;
		}
};