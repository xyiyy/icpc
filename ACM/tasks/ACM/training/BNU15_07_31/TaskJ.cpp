#include "../../xyiyy/lib.hpp"
#include "../../xyiyy/math/inv.hpp"
const ll mod = 100000007;
class TaskJ {
public:
		void solve(std::istream& in, std::ostream& out) {
			ll n;
			while(in>>n){
				ll ans = 0;
				ll m = n - 1;
				ll num = inv(2,mod);
				for(ll i=1;i*i<=m;i++){
					ll r = m/i;
					ll l = m/(i+1) + 1;
					if(l>r)continue;
					ans += (n * i %mod * (r - l + 1) % mod - (1LL+i) * i % mod * num % mod * (l + r) %mod * (r - l + 1) %mod *num % mod)%mod + mod;
					ans %= mod;
					if(i!=r)ans += (n * r % mod - i * r %mod * (1LL + r) %mod * num % mod) % mod + mod;
					ans %= mod;
				}
				out<<ans<<endl;
			}
		}
};