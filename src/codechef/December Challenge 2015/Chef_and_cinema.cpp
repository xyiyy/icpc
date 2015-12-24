#include "../../../xyiyylib/lib.hpp"

class Chef_and_cinema {
public:
	void solve(std::istream& in, std::ostream& out) {
		int t;
		in>>t;
		while(t--){
			ll n,m,z,l,r,b;
			ll ans = 0;
			in>>n>>m>>z>>l>>r>>b;
			ans = n * m;
			ll s = l + r;
			ll line_m = m - (m % 2 == 0);
			ll tb = (line_m + 1) /2;
			ll tz = (line_m) / 2;
			ll ts = m - line_m;
			ll mb = INF;
			if(tb) mb = b / tb;
			ll mz = INF;
			if(tz) mz = z / tz;
			ll ms = INF;
			if(ts) ms = s / ts;
			ll sum = 0;
			if(mb <= ms && mb <= mz){
				if(mb < n){
					ans = min(z + s + b,ans);
				}else{
					ans = n * m;
				}
			}else if(ms <= mb && ms <= mz){
				if(ms < n){
					sum = ms * m;
					ll leftz = z - ms * tz;
					ll leftb = b - ms * tb;
					tz = m / 2;
					tb = m - tz;
					mb = leftb / tb;
					mz = leftz / tz;
					if(mb < mz){
						ans = min(s + z + b, ans);
					}else{
						if(ms + mz < n){
							sum += mz * m;
							leftz -= mz * tz;
							leftb -= mb * tb;
							mb = leftb / tb;
							ans = sum + leftz + ((mb > n - ms - mz) ? (n - ms - mz) * tb : (mb * tb));
						}else ;

					}
				}else{
					;
				}
			}else{
				if(mz < n){
					ll leftz = z - mz * tz;
					ll leftb = b - mz * tb;
					ll lefts = s - mz * ts;
					ll leftn = n - mz;
					ll leftm = m - (leftz * 2 + 1);
					leftb -= leftz + 1;
					sum = m * mz;
					if(lefts > leftm){
						sum += m;
						lefts -= leftm;
						leftn --;
						tb = 1;
						ts = m - 1;
						mb = leftb / tb;
						ms = lefts / ts;
						if(ms < mb){
							leftn -= ms;
							lefts = lefts - ms * ts;
							leftb = leftb - ms * tb;
							sum += ms * m;
							if(sum > ans){
								ans = n * m;
							}else{
								leftm = m ;
								leftm = leftm - lefts;
								if(leftm & 1){
									ll p = min((leftm + 1) / 2,leftb);

									//leftb -= (leftm + 1) /2;
									//sum += (leftm + 1) /2;
									sum += lefts;
									lefts = 0;
								}else{
									leftb -= (leftm + 2)/ 2;
									sum += (leftm + 2) / 2;
								}
								/*leftb -= (leftm + 1) / 2;
								sum += 1;
								sum += (leftm + 1)/2;
								sum += lefts;
								tb = (m + 1) /2;
								leftn --;
								mb = leftb / tb;
								ans = min(ans,sum + min(leftn,mb) * tb);*/
							}
						}else{
							ans = min (ans,s + z + b);
						}
					}else{
						leftm = leftm - lefts - 1;
						sum += leftz * 2 + 1;
						sum += lefts;
						leftb -= (leftm +  1) / 2;
						sum += (leftm + 1) / 2;
						tb = (m + 1) / 2;
						leftn --;
						mb = leftb / tb;
						ans = min(ans,sum + min(leftn,mb) * tb);
					}
				}else{
					;
				}
			}
			out << ans << endl;
		}

	}
};
