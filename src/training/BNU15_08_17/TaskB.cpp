#include "../../xyiyy/lib.hpp"
char c[500010];
int l[500010],r[500010];
int num[2*500010];
int p[500010];
int ans[2*500010];
int sz;
int s[2*500010];
bool cmp(int x,int y){
	return l[x]<l[y];
}
void add(int i,int v){
	while(i){
		s[i] += v;
		i -= i & -i;
	}
}
int query(int x){
	int ret = 0;
	while(x<=sz){
		ret += s[x];
		x += x & -x;
	}
	return ret;
}

class TaskB {
public:
		void solve(std::istream& in, std::ostream& out) {
			int n;
			while(in>>n){
				rep(i,n){
					in>>c[i]>>l[i]>>r[i];
					num[i*2] = l[i];
					num[i*2+1] = r[i];
				}
				sort(num,num+n*2);
				int m = unique(num,num+n*2)-num;
				sz = m + 10;
				rep(i,sz)s[i] = 0;
				//out<<m<<endl;
				rep(i,n){
					l[i] = lower_bound(num,num+m,l[i]) - num + 1;
					r[i] = lower_bound(num,num+m,r[i]) - num + 1;
					ans[i] = 0;
				}
				gao(0,n-1);
				rep(i,n){
					if(c[i]=='?'){
						out<<ans[i]<<endl;
					}
				}
			}
		}
	void gao(int lx,int rx){
		if(lx>=rx)return ;
		int mid = (lx+rx)>>1;
		gao(lx,mid);
		gao(mid + 1,rx);
		int len = 0;
		rep2(i,lx,rx){
			p[len++] = i;
		}
		sort(p,p+len,cmp);
		rep(i,len){
			int j = i;
			while(j<len && l[p[j]] == l[p[i]])j++;
			j--;
			rep2(k,i,j){
				if(c[p[k]]=='+' && p[k] <= mid){
					add(r[p[k]],1);
				}
			}
			rep2(k,i,j){
				if(c[p[k]]=='?' && p[k] > mid){
					ans[p[k]] += query(r[p[k]]);
				}
			}
			i = j;
		}
		rep(i,len){
			if(c[p[i]]=='+'&&p[i]<=mid){
				add(r[p[i]],-1);
			}
		}
	}
};