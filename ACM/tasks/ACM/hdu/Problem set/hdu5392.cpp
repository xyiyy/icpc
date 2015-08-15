#include "../../xyiyy/lib.hpp"
#include "../../xyiyy/newScanner.hpp"
#include "../../xyiyy/math/quick_power.hpp"
int a[3000010];
bool vis[3000010];
map<int, int> ms;
int prime[3010];
bool ok[3010];
int gao = 0;
void init(){
	rep2(i,2,3009)ok[i] = 1;
	rep2(i,2,3009){
		if(ok[i]){
			prime[gao++] = i;
			for(int j = i*i;j<3010;j+=i)ok[j] = 0;
		}
	}
}
class hdu5392 {
public:
	void solve() {
		int t;
		init();
		t = Scan();//Scan(t);//in>>t;
		ll mod = 3221225473;
		while (t--) {
			int n;
			ms.clear();
			n = Scan();//Scan(n);//in>>n;
			rep2(i, 1, n) {
				vis[i] = 0;
				a[i] = Scan();//Scan(a[i]);//in>>a[i];
			}
			rep2(i, 1, n) {
				if (!vis[i]) {
					int len = 1;
					int x = a[i];
					vis[i] = 1;
					while (!vis[x]) {
						vis[x] = 1;
						x = a[x];
						len++;
					}
					for (int k = 0; k<gao && prime[k] * prime[k] <= len; k++) {
						int j = prime[k];
						if (len % j == 0) {
							int num = 0;
							while (len % j == 0) {
								num++;
								len /= j;
							}
							if (!ms.count(j))ms[j] = num;
							else ms[j] = max(ms[j], num);
						}
					}
					if (len != 1) {
						if (!ms.count(len))ms[len] = 1;
					}
				}
			}
			ll ans = 1;
			for (auto x : ms) {
			    ans = ans * quick_power(x.first, x.second, mod) % mod;
			}
			Out(ans);
			putchar('\n');//out<<ans<<endl;
		}

	}
};