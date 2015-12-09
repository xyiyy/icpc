#include "../../xyiyy/lib.hpp"
typedef unsigned long long ull;
ull dp[30][10];
int d[30];
class TaskE {
public:
	void solve(std::istream &in, std::ostream &out) {
		rep(i,30)
			rep(j,10)dp[i][j] = 0;
		run();
		ull n;
		while (in >> n) {
			ull ans = 1;
			ull l = 1;
			ull r = -1;
			while (l <= r) {
				int f = 0;
				if((l&1)&&(r&1))f++;
				ull mid = (r>>1) + (l>>1) + f;
				if (gao(mid) <= n) {
					ans = mid;
					l = mid + 1;
				} else {
					r = mid - 1;
				}
			}
			out << ans << endl;
		}
	}
	ull gao(ull n) {
		ull ans = 0;
		int len = 0;
		while (n) {
			d[++len] = n % 10;
			n /= 10;
		}
		d[len + 1] = 0;
		dep(i, len, 1) {
			rep(j, d[i]) {
				if (d[i + 1] != 1 || j != 3) {
					ans += dp[i][j];
				}
			}
			if (d[i] == 4 || (d[i + 1] == 1 && d[i] == 3))break;
		}
		return ans;
	}
	void run() {
		dp[0][0] = 1;
		for (int i = 1; i <= 20; i++) {
			for (int j = 0; j <= 9; j++) {
				for (int k = 0; k <= 9; k++) {
					if (j != 4 && !(j == 1 && k == 3)) {
						dp[i][j] += dp[i - 1][k];
					}
				}
			}
		}
	}
};