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

using namespace std;
#define XINF INT_MAX
#define INF 0x3FFFFFFF
#define MP(X, Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X, N) for(int X=0;X<N;X++)
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef long long ll;

struct Point {
    double x, y;

    Point(double x = 0, double y = 0) : x(x), y(y) { };

};

typedef Point Vector;

Vector operator+(Vector A, Vector B) { return Vector(A.x + B.x, A.y + B.y); }

Vector operator-(Vector A, Vector B) { return Vector(A.x - B.x, A.y - B.y); }

Vector operator*(Vector A, double p) { return Vector(A.x * p, A.y * p); }

Vector operator/(Vector A, double p) { return Vector(A.x / p, A.y / p; }

const double eps = 1e-10;

int dcmp(double x) {
    if (fabs(x) < eps) return 0; else return x < 0 ? -1 : 1;

}

bool operator<(const Point &a, const Point &b) {
    return a.x < b.x || (a.x == b.x) && (a.y < b.y);
}

bool operator==(const Point &a, const Point &b) {
    return dcmp(a.x - b.x) == 0 && dcmp(a.y - b.y) == 0;
}

double Dot(Vector A, Vector B) { return A.x * B.x + A.y * B.y; }

double Length(Vector A) { return sqrt(Dot(A, A)); }

double Angle(Vector A, Vector B) { return acos(Dot(A, B)) / Length(A) / Length(B); }

Vector Normal(Vector A) {
    double L = Length(A);
    return Vector(-A.y / L, A.x / L);
}


int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    double x1, y1, x2, y2, x3, y3;
    while (T--) {
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

        solve();


    }


    return 0;
}

