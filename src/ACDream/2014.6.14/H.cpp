#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string.h>
#include <math.h>
#include <iomanip>

using namespace std;

const double eps = 1e-8;

int sgn(double x) {
    if (fabs(x) < eps)return 0;
    if (x < 0)return -1;
    else return 1;
}

struct Point {
    double x, y;

    Point(double _x = 0.0, double _y = 0.0) {
        x = _x;
        y = _y;
    }

    Point operator-(const Point &b) const {
        return Point(x - b.x, y - b.y);
    }

    double operator^(const Point &b) const {
        return x * b.y - y * b.x;
    }

    double operator*(const Point &b) const {
        return x * b.x + y * b.y;
    }

    void input() {
        cin >> x >> y;
    }
};

Point p[1010], q[1010];

struct Line {
    Point s, e;

    Line() { }

    Line(Point _s, Point _e) {
        s = _s;
        e = _e;
    }
};

Line pp[1010], qq[1010];

double dist(Point a, Point b) {
    return sqrt((a - b) * (a - b));
}

Point NearestPointToLineSeg(Point P, Line L) {
    Point result;
    double t = ((P - L.s) * (L.e - L.s)) / ((L.e - L.s) * (L.e - L.s));
    if (t >= 0 && t <= 1) {
        result.x = L.s.x + (L.e.x - L.s.x) * t;
        result.y = L.s.y + (L.e.y - L.s.y) * t;
    }
    else {
        if (dist(P, L.s) < dist(P, L.e))
            result = L.s;
        else result = L.e;
    }
    return result;
}

//点p0到线段p1p2的距离
double pointtoseg(Point p0, Point p1, Point p2) {
    return dist(p0, NearestPointToLineSeg(p0, Line(p1, p2)));
}

int main() {
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n;
    for (int i = 0; i < n; i++) {
        p[i].input();
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        q[i].input();
    }
    /* for(int i=0;i<n-1;i++)
     {
         pp[i].s=p[i];
         pp[i].e=p[i+1];
     }
     pp[n-1].s=p[n-1];pp[n-1].e=p[0];
     for(int i=0;i<m;i++)
     {
         qq[i].s=q[i];
         qq[i].e=q[i+1];
     }
     qq[m-1].s=q[n-1];qq[n-1].e=q[0];*/
    double minn = 999999.9999;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (j < m - 1)
                minn = minn < pointtoseg(p[i], q[j], q[j + 1]) ? minn : pointtoseg(p[i], q[j], q[j + 1]);
            else minn = minn < pointtoseg(p[i], q[j], q[0]) ? minn : pointtoseg(p[i], q[j], q[0]);
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (j < n - 1) {
                minn = minn < pointtoseg(q[i], p[j], p[j + 1]) ? minn : pointtoseg(q[i], p[j], p[j + 1]);
            }
            else minn = minn < pointtoseg(q[i], p[j], p[0]) ? minn : pointtoseg(q[i], p[j], p[0]);
        }
    }
    cout << fixed << setprecision(4) << minn << endl;


    return 0;
}
