//#####################
//Author:fraud
//Blog: http://www.cnblogs.com/fraud/
//#####################
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
#define MP(X, Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X, N) for(int X=0;X<N;X++)
#define REP2(X, L, R) for(int X=L;X<=R;X++)
#define DEP(X, R, L) for(int X=R;X>=L;X--)
#define CLR(A, X) memset(A,X,sizeof(A))
#define IT iterator
typedef long long ll;
typedef pair<int, int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;

double distance(double x0, double y0, double xn, double yn) {
    return sqrt((x0 - xn) * (x0 - xn) + (y0 - yn) * (y0 - yn));
}

double f1(double x, double x1, double y1, double x2, double y2) {
    return (y1 - y2) / (x1 - x2) * (x - x2) + y2;
}

double f2(double y, double x1, double y1, double x2, double y2) {
    return (x1 - x2) / (y1 - y2) * (y - y2) + x2;
}

const double eps = 1e-12;

int main() {
    double x1, y1;
    double x2, y2;
    while (cin >> x1 >> y1 >> x2 >> y2) {
        double x0, y0, xn, yn;
        if (fabs(y1 - y2) <= eps || fabs(x1 - x2) <= eps) {
            printf("100.00\n");
            continue;
        }
        x0 = 0;
        xn = 100;
        y0 = f1(x0, x1, y1, x2, y2);
        yn = f1(xn, x1, y1, x2, y2);
        if (yn > 100 && y0 >= 0 && y0 <= 100) {
            yn = 100;
            xn = f2(yn, x1, y1, x2, y2);
        }
        else if (yn > 100 && y0 < 0) {
            yn = 100;
            xn = f2(yn, x1, y1, x2, y2);
            y0 = 0;
            x0 = f2(y0, x1, y1, x2, y2);
        }
        else if (y0 < 0 && yn >= 0 && yn <= 100) {
            y0 = 0;
            x0 = f2(y0, x1, y1, x2, y2);
        }
        else if (y0 > 100 && yn >= 0 && yn <= 100) {
            y0 = 100;
            x0 = f2(y0, x1, y1, x2, y2);
        }
        else if (y0 > 100 && yn < 0) {
            y0 = 100;
            x0 = f2(y0, x1, y1, x2, y2);
            yn = 0;
            xn = f2(yn, x1, y1, x2, y2);
        }
        else if (y0 >= 0 && y0 <= 100 && yn < 0) {
            yn = 0;
            xn = f2(yn, x1, y1, x2, y2);
        }
        printf("%.2lf\n", distance(x0, y0, xn, yn));
    }
    return 0;
}  



