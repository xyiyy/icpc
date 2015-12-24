#include "../../../xyiyylib/lib.hpp"


const int maxn = 100010;
int a[maxn],b[maxn],c[maxn];
//pair<int,PII> p[maxn];
//PII tmp[maxn];
pair<double,int> p[maxn];
double tmp[maxn];
vector<double>vs;
class Plane_Division {
public:
	void solve(std::istream& in, std::ostream& out) {
		// a*x + b * y + c = 0;
		// y = -a / b * x - c / b;
		int t;
		in >> t;
		while(t--){
			int tot = 0;
			int n;
			in >> n;
			int num = 0;
            rep(i,n){
				in >> a[i] >> b[i] >> c[i];
				if(b[i]){
					p[tot] = mp(-1.0*a[i]/b[i],i);
					tot ++;
				}else {
					tmp[num] =- 1.0*c[i] / a[i];
					num ++ ;
				}
			}
			sort(p,p+tot);
			sort(tmp,tmp+ num);
			int ans = num;
			rep2(i,1,num-1){
				if(tmp[i] - tmp[i-1]<1e-12)ans--;
			}
			p[tot] = mp(1e15,100009);
			int i = 0;
			while(i<tot){
				int j = i;
				num = 0;
				while(p[j].first - p[i].first < 1e-9){
					j++;
				}
				num = j - i;
				vs.resize(num);
				rep2(k,i,j-1){
					int id = p[k].second;
					vs[k - i] = (-1.0 * c[id] / b[id]);
				}
				sort(ALL(vs));
				rep2(k,1,j - i-1){
					if(vs[k] - vs[k-1] < 1e-12)num--;
				}
				i = j;
				ans = max(num,ans);
			}
			out << ans << endl;
		}

	}
};
