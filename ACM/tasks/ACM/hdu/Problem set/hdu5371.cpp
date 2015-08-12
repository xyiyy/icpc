#include "../../xyiyy/lib.hpp"
#define MAXN 400010
int str[MAXN],s[MAXN];//MAXN至少要开到原字符串的两倍
int p[MAXN];//p中的最大值-1就是最长回文子串的长度
int n;
vector<PII>vec;
set<int>st;
void Manacher(){
	str[0]=INF;
	str[1]=INF-1;
	for(int i=0;i<n;i++)str[2*i+2]=s[i],str[2*i+3]=INF-1;
	n=n*2+2;
	str[n]=INF-2;
	int mx=0,id;
	for(int i=1;i<n;i++){
		if(mx>i)p[i]=min(p[2*id-i],mx-i);
		else p[i]=1;
		for(;str[i+p[i]]==str[i-p[i]];p[i]++);
		if(p[i]+i>mx)mx=p[i]+i,id=i;
	}
}


class hdu5371 {
public:
		void solve(std::istream& in, std::ostream& out) {
			int t;
			in>>t;
			int cas = 1;
			while(t--){
				in>>n;
				rep(i,n)in>>s[i];
				int m = n;
				vec.clear();
				st.clear();
				Manacher();
				for(int i=3;i<n;i+=2){
					p[i]--;
					if(p[i]){
						vec.pb(mp(i-p[i],i));
						vec.pb(mp(i,i+n));
					}
				}
				int maxx = -1;
				int ans = 0;
				sort(vec.begin(),vec.end());
				rep(i,vec.size()){
					int id = vec[i].second;
					if(id<n)st.insert(id);
					else{
						id -= n;
						st.erase(id);
						set<int>::IT it = st.upper_bound(id+p[id]);
						if(it==st.begin())continue;
						it--;
						ans = max(ans,3*(*it-id)/2);
					}
				}
				out<<"Case #"<<cas++<<": "<<ans<<endl;
			}
		}
};