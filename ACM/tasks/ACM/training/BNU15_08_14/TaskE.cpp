#include "../../xyiyy/lib.hpp"
typedef unsigned long long ull;
/*
struct bign;
bign operator + (const bign & ,const bign &);
bign operator - (const bign & ,const bign &);
bign operator * (const bign & ,const bign &);
bign operator / (const bign & ,const bign &);
bign operator % (const bign & ,const bign &);

struct bign {
	list<int> data;
	bign() {}
	template<typename T>
	bign(const T & t)
	{
		stringstream str;
		str<<t;
		*this = str.str();
	}
	bign(const string & s) {
		int t, i;
		for (i=int(s.size())-8; i>0; i-=8) {
			istringstream(s.substr(i, 8)) >> t;
			data.push_back(t);
		}
		istringstream(s.substr(0, i+8)) >> t;
		data.push_back(t);
	}

	int do_try(const bign&);//辅助函数
	void do_trim();//辅助函数，去掉前缀0
	string str() const ;//转化成string
	bign operator += (const bign & b) {return *this = *this + b;}
	bign operator -= (const bign & b) {return *this = *this - b;}
	bign operator *= (const bign & b) {return *this = *this * b;}
	bign operator /= (const bign & b) {return *this = *this / b;}
	bign operator %= (const bign & b) {return *this = *this % b;}

};

inline int do_comp(const bign& a, const bign& b) {
	if (a.data.size()<b.data.size()) return -1;
	if (a.data.size()>b.data.size()) return 1;
	list<int>::const_reverse_iterator i;
	list<int>::const_reverse_iterator j;
	for (i=a.data.rbegin(),j=b.data.rbegin(); j!=b.data.rend(); i++,j++) {
		if (*i<*j) return -1;
		if (*i>*j) return 1;
	}
	return 0;
}
bool operator < (const bign & a,const bign & b) {return do_comp(a,b) < 0;}
bool operator > (const bign & a,const bign & b) {return do_comp(a,b) > 0;}
bool operator ==(const bign & a,const bign & b) {return do_comp(a,b) ==0;}
bool operator !=(const bign & a,const bign & b) {return do_comp(a,b) !=0;}
bool operator <=(const bign & a,const bign & b) {return do_comp(a,b) <=0;}
bool operator >=(const bign & a,const bign & b) {return do_comp(a,b) >=0;}


void bign::do_trim() {
	while (data.size()>1&&data.back()==0) data.pop_back();
}

bign operator +(const bign& a, const bign& b) {
	list<int>::const_iterator i, j;
	bign c;
	int t = 0;
	for (i=a.data.begin(),j=b.data.begin(); i!=a.data.end()&&j!=b.data.end(); i++,j++) {
		c.data.push_back(t+*i+*j);
		t=c.data.back()/100000000;
		c.data.back()%=100000000;
	}
	while (i!=a.data.end()) {
		c.data.push_back(t+*i);
		t=c.data.back()/100000000;
		c.data.back()%=100000000;
		i++;
	}
	while (j!=b.data.end()) {
		c.data.push_back(t+*j);
		t=c.data.back()/100000000;
		c.data.back()%=100000000;
		j++;
	}
	if (t!=0) c.data.push_back(t);
	return c;
}

bign operator -(const bign& a, const bign& b) {
	list<int>::const_iterator i, j;
	bign c;
	int t = 0;
	for (i=a.data.begin(),j=b.data.begin(); j!=b.data.end(); i++,j++) {
		t = *i - t;
		if (t>=*j) c.data.push_back(t-*j), t=0;
		else c.data.push_back(t+100000000-*j), t=1;
	}
	while (i!=a.data.end()) {
		t=*i-t;
		if (t>=0) c.data.push_back(t), t=0;
		else c.data.push_back(t+100000000), t=1;
		i++;
	}
	c.do_trim();
	return c;
}

bign operator *(const bign& a, const bign& b) {
	list<int>::const_iterator i, j;
	list<int>::iterator k, kk;
	bign c;
	long long t = 0;

	for (int i=0; i<a.data.size()+b.data.size(); i++) c.data.push_back(0);
	for (i=a.data.begin(),k=c.data.begin(); i!=a.data.end(); i++,k++) {
		for (j=b.data.begin(),kk=k; j!=b.data.end(); j++,kk++) {
			t+=(long long)(*i)*(*j)+(*kk);
			*kk=int(t%100000000);
			t/=100000000;
		}
		*kk+=t;
		t=0;
	}
	c.do_trim();
	return c;
}

int bign::do_try(const bign& a) {
	int l = 1, r = 99999999, m, t;
	while (l+2<r) {
		m = (l + r) / 2;
		t = do_comp(*this, a*bign(m));
		if (t==0) return m;
		if (t<0) r = m - 1;
		else l = m;
	}
	while (do_comp(*this, a*bign(r))<0) r--;
	return r;
}

void divide(const bign& a, const bign& b, bign& d, bign& r) {
	list<int>::const_reverse_iterator i = a.data.rbegin();
	int t;
	d = bign(0);
	r = bign(0);
	do {
		while (r<b&&i!=a.data.rend()) {
			d.data.push_front(0);
			r.data.push_front(*i);
			r.do_trim();
			i++;
		}
		if (r>=b) {
			t = r.do_try(b);
			d.data.front() = t;
			r-=(b*bign(t));
		}
	} while (i!=a.data.rend());
	d.do_trim();
}

bign operator /(const bign& a, const bign& b) {
	bign d, r;
	divide(a, b, d, r);
	return d;
}

bign operator %(const bign& a, const bign& b) {
	bign d, r;
	divide(a, b, d, r);
	return r;
}

bign pow(bign a,int b) {
	bign c(1);
	while (b!=0) {
		if (b&1) c *= a;
		a = a * a;
		b >>= 1;
	}
	return c;
}
inline bign pow(int a,int b)
{
	return pow(bign(a),b);
}
string bign::str() const
{
	string ret;
	if(data.empty()) return ret;
	stringstream s;
	s<<data.back();
	list<int>::const_reverse_iterator i = data.rbegin();
	for(++i;i!=data.rend();++i) {
		s<<setfill('0')<<setw(8)<<*i;
	}
	s>>ret;
	return ret;
}

istream& operator >>(istream & in,bign & b)
{
	string str;
	in>>str;
	b = str;
	return in;
}
ostream& operator <<(ostream & out,const bign & b)
{
	return out<<b.str();
}*/
ull dp[30][10];
int d[30];
class TaskE {
public:
	void solve(std::istream &in, std::ostream &out) {
		//bign n;

		rep(i,30)
			rep(j,10)dp[i][j] = 0;
		run();
		ull n;
		while (in >> n) {
			ull ans = 1;
			ull l = 1;
			ull r = -1;
			//bign ans = 1;
			//bign l = 1;
			//bign r = "123456789123456789123456789";
			while (l <= r) {
				int f = 0;
				if((l&1)&&(r&1))f++;
				ull mid = (r>>1) + (l>>1) + f;
				//bign mid = (l+r)/2;
				if (gao(mid) <= n) {
					//out<<mid<<endl;
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
	/*bign gao(bign n) {
		bign ans = 0;
		int len = 0;
		string str = n.str();
		int lx = str.length();
		for(int i=0;i<lx;i++) {
			d[++len] = str[lx - 1 - i] - '0';
		}
		d[len + 1] = 0;
		dep(i, len, 1) {
			rep(j, d[i]) {
				if (d[i + 1] != 1 || j != 3) {
					ans = ans + dp[i][j];
				}
			}
			if (d[i] == 4 || (d[i + 1] == 1 && d[i] == 3))break;
		}
		return ans;
	}*/

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