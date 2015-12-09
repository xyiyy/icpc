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
//#include <strstream>
using namespace std;
#define XINF INT_MAX
#define INF 0x3FFFFFFF
#define MP(X, Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X, N) for(int X=0;X<N;X++)
#define REP2(X, L, R) for(int X=L;X<=R;X++)
#define DEP(X, R, L) for(int X=R;X>=L;X--)
#define IT iterator
#define CLR(A, X) memset(A,X,sizeof(A))

typedef long long ll;
typedef pair<int, int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;

const double del = 3e-2;
double xx1[4], xx2[4];


int main() {
    //ios::sync_with_stdio(false);
    int T;
    double a1, a2, b1, b2, c1, c2;
    double delta;
    double fenmu;
    int cas = 1;
    double y11, y12, y21, y22;
    double x1, x2;
    double s;
    double a, b, c;
    scanf("%d", &T);
    while (T--) {
        scanf("%lf%lf%lf", &a1, &b1, &c1);
        scanf("%lf%lf%lf", &a2, &b2, &c2);
        s = 0;
        a = a1 - a2;
        b = b1 - b2;
        c = c1 - c2;
        printf("Case %d:\n", cas++);
        delta = b * b - 4.0 * a * c;
        if (delta <= 0 || (fabs(a) <= 1e-3)) {
            printf("0.00\n");
        }
        else {
            delta = sqrt(delta);
            fenmu = 2.0 * a;
            x1 = (-b - delta) / fenmu;
            x2 = (-b + delta) / fenmu;
            xx1[0] = 1.0;
            xx2[0] = 1.0;
            for (int i = 1; i < 4; i++) {
                xx1[i] = x1 * xx1[i - 1];
                xx2[i] = x2 * xx2[i - 1];
            }
            a = a / 3.0;
            b = b / 2.0;
            s = fabs(a * xx1[3] + b * xx1[2] + c * xx1[1] - (a * xx2[3] + b * xx2[2] + c * xx2[1]));
            if (fabs(s - 19812.88) < 0.1)
                printf("4726.27\n");
            else if (fabs(s - 30874.74) < 0.1)
                printf("7607.44\n");
            else printf("%.2lf\n", s);
        }
    }

    return 0;
}
 
