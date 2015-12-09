#include<cstdio>

#define MAXM 100010
int n, m;
long long s[3][MAXM];
long long t[2][MAXM];

long long find(long long x) {
    int i = m;
    for (; ;) {
        int a = 1, b = i;
        while (a <= b) {
            i = (a + b) / 2;
            if (x >= t[0][i] && x <= t[1][i])
                break;
            if (x < t[0][i])
                b = i - 1;
            if (x > t[1][i])
                a = i + 1;
        }
        if (s[0][i] == 1)
            return s[1][i];
        x = (x - t[0][i]) % s[1][i] + 1;
    }
}

int main() {
    long long x;
    scanf("%d", &m);
    t[0][0] = t[1][0] = 0;
    for (int i = 1; i <= m; i++) {
        scanf("%I64d%I64d", &s[0][i], &s[1][i]);
        if (s[0][i] == 1) {
            t[0][i] = t[1][i] = t[1][i - 1] + 1;
        }
        else {
            scanf("%I64d", &s[2][i]);
            t[0][i] = t[1][i - 1] + 1;
            t[1][i] = t[1][i - 1] + s[1][i] * s[2][i];
        }
    }
    scanf("%d", &n);
    scanf("%I64d", &x);
    printf("%I64d", find(x));
    for (int i = 1; i < n; i++) {
        scanf("%I64d", &x);
        printf(" %I64d", find(x));
    }
    printf("\n");
    return 0;
}
