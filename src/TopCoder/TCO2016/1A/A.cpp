
//#####################
//Author:fraud
//Blog: http://www.cnblogs.com/fraud/
//#####################
//#pragma comment(linker, "/STACK:102400000,102400000")
#include <iostream>
#include <sstream>
#include <ios>
#include <iomanip>
#include <functional>
#include <algorithm>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>
#include <cctype>
using namespace std;
#define XINF INT_MAX
#define INF 0x3FFFFFFF
#define mp(X,Y) make_pair(X,Y)
#define pb(X) push_back(X)
#define rep(X,N) for(int X=0;X<N;X++)
#define rep2(X,L,R) for(int X=L;X<=R;X++)
#define dep(X,R,L) for(int X=R;X>=L;X--)
#define clr(A,X) memset(A,X,sizeof(A))
#define IT iterator
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<PII> vii;
typedef vector<int> vi;

 class EllysTimeMachine{
 public:
    string getTime(string str){
        int h = 0;
        h = str[0] - '0';
        h = h * 10 + str[1] - '0';
        int m = 0;
        m = str[3] - '0';
        m = m * 10 + str[4] - '0';
        int hh = m / 5;
        int mm = h * 5 % 60;
        if(hh == 0)hh += 12;
        str = "";
        str += hh / 10 + '0';
        str += hh % 10 + '0';
        str += ":";

        str += mm / 10 + '0';
        str += mm % 10 + '0';
        return str;
    }

};


int main()
{
    ios::sync_with_stdio(false);
EllysTimeMachine *p = new EllysTimeMachine();
cout << p->getTime("12:10");
    return 0;
}
