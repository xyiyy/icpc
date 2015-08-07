#include "../../../../library/lib.hpp"
#include "../../../../library/Scanner.hpp"
ll a[100010];
ll l [100010];
ll r [100010];
class hdu5358 {
public:
		void solve(std::istream& in, std::ostream& out) {
			int n;
			in>>n;
			a[0] = 0;
			rep2(i,1,n)in>>a[i];
			rep2(i,1,n)a[i]+=a[i-1];
			ll ans = 0;
			rep(i,n+1)l[i] = r[i] = 0;
			rep2(i,1,n){
				int j = 0;
				while(1){
					ll L = ( 1LL << j );
					ll R = (L<<1);
					if(!j) L = 0;
					L += a[i-1];
					R += a[i-1];
					j++;
					if(a[i] >= R)continue;
					while((a[l[j-1]]  < L || l[j-1] < i) && l[j-1] <= n)l[j-1]++;
					while((a[r[j-1]]  < R || r[j-1] < i) && r[j-1] <= n)r[j-1]++;
					if(l[j-1]>n)break;
					ans += (ll)j * (i + l[j-1] + i + r[j-1] - 1) * (r[j-1] - l[j-1])/2;
				}
			}
			out<<ans<<endl;
		}
};