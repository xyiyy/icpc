#include "../../xyiyy/lib.hpp"
string s1, s2;
stack<char> op;
stack<int> s;
int Map[110];
bool flag ;
map<char, int> x, y;

ll cal(ll x, ll y, char c) {
	if (c == '+')return x + y;
	if (c == '-')return x - y;
	if (c == '*')return x * y;
	else if(c=='^'){
		ll ret = 1;
		while (y) {
			if (y & 1)ret = ret * x;
			x *= x;
			y >>= 1;
		}
		return ret;
	}
}

ll gao(string str) {
	while (!s.empty())s.pop();
	while (!op.empty())op.pop();
	op.push('$');
	ll ret = 0;
	int i = 0;
	while ( str[i]!='$' || op.top()!='$') {
		ll num = 0;
		if(flag)return -INF;
		if(str[i]==' '){
			i++;
			continue;
		}
		if (str[i] >= '0' && str[i] <= '9') {
			while (str[i] >= '0' && str[i] <= '9') {
				num *= 10;
				num += str[i] - '0';
				i++;
			}
			s.push(num);
		} else if (str[i] >= 'a' && str[i] <= 'z') {
			s.push(Map[str[i] - 'a']);
			i++;
		} else {
			//cout<<"ok"<<endl;
			if (x[op.top()] < y[str[i]]) {
				op.push(str[i]);
				i++;
			} else if (x[op.top()] == y[str[i]]) {
				op.pop();
				i++;
			} else {
				if (s.empty()){flag = 1;return -INF;}
				ll tmp = s.top();
				s.pop();
				if (s.empty()){flag = 1;return -INF;}
				tmp = cal(s.top(), tmp, op.top());
				s.pop();
				s.push(tmp);
				op.pop();
			}
		}
		//cout<<i<<endl;
	}
	return s.top();
}

class TaskD {
public:
	void solve(std::istream &in, std::ostream &out) {
		int t;
		in >> t;
		x['+'] = x['-'] = 1;
		y['+'] = y['-'] = 0;
		x['*'] = 3;
		y['*'] = 2;
		x['^'] = 5, y['^'] = 4;
		x[')'] = 6, y[')'] = -1;
		x['('] = -1, y['('] = 6;
		x['$'] = y['$'] = -INF;
		while (t--) {
			in >> s1;
			s1 = s1 + "$";
			in >> s2;
			s2 = s2 + "$";
			flag = 0;
			rep(i, 50) {
				rep(j, 26)Map[j] = labs(rand()) % 10000;
				ll ans1 = gao(s1);
				ll ans2 = gao(s2);
				if (ans1 != ans2){
					flag = 1;
					break;
				}
			}
			if (flag)out << "NO" << endl;
			else out << "YES" << endl;
		}
	}
};
