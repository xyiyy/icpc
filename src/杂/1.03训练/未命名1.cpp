#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;

struct point {
    double x, y;
};
point a[105][2];

double fan(double x, double y) {
    return x > y ? x : y;
}

double fin(double c, double d) {
    return c < d ? c : d;
}

double cnt(point a, point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int is(point a, point b, point c, point d) {
    if (a.x == b.x && c.x == d.x) {
        return 0;
    }
    if (a.x == b.x && c.x != d.x) {
        double m1 = a.x;
        double m2 = (a.x - c.x) * (d.y - c.y) / (d.x - c.x) + c.y;
        if (m1 <= fan(a.x, b.x) && m1 >= fin(a.x, b.x) && m2 >= fin(a.y, b.y) && m2 <= fan(a.y, b.y) &&
            m1 <= fan(c.x, d.x) && m1 >= fin(c.x, d.x) && m2 >= fin(c.y, d.y) && m2 <= fan(c.y, d.y))
            return 1;
    }
    if (c.x == d.x && a.x != b.x) {
        double m1 = c.x;
        double m2 = a.y + (b.y - a.y) * (c.x - a.x) / (b.x - a.x);
        if (m1 <= fan(a.x, b.x) && m1 >= fin(a.x, b.x) && m2 >= fin(a.y, b.y) && m2 <= fan(a.y, b.y) &&
            m1 <= fan(c.x, d.x) && m1 >= fin(c.x, d.x) && m2 >= fin(c.y, d.y) && m2 <= fan(c.y, d.y))
            return 1;
    }
    double k1 = (b.y - a.y) / (b.x - a.x);
    double k2 = (d.y - c.y) / (d.x - c.x);
    double m1, m2, x, y;
    if (k1 == k2) return 0;
    else {
        m1 = a.y - k1 * a.x;
        m2 = c.y - k2 * c.x;
        x = (m1 - m2) / (k2 - k1);
        y = k1 * x + m1;
        if (x <= fan(a.x, b.x) && x >= fin(a.x, b.x) && y >= fin(a.y, b.y) && y <= fan(a.y, b.y) &&
            x <= fan(c.x, d.x) && x >= fin(c.x, d.x) && y >= fin(c.y, d.y) && y <= fan(c.y, d.y))
            return 1;
    }
    return 0;
}

int main() {
    int cas = 1;
    int n, i, j;
    while (scanf("%d", &n), n) {
        int cnt = 0;
        for (i = 0; i < n; i++)
            scanf("%lf%lf%lf%lf", &a[i][0].x, &a[i][0].y, &a[i][1].x, &a[i][1].y);
        for (i = 0; i < n; i++) {
            for (j = i + 1; j < n; j++) {
                if (is(a[i][0], a[i][1], a[j][0], a[j][1]))
                    cnt++;
            }
        }
        printf("%d\n", cnt);
    }

    return 0;
}
	
