//
// Created by xyiyy on 2015/8/7.
//

#ifndef ICPC_SCANNER_HPP
#define ICPC_SCANNER_HPP

template<class T>
inline bool Scan(T &n) {
    T x = 0, f = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-' && c != EOF)c = getchar();
    if (c == EOF)return false;
    if (c == '-')c = getchar(), f = -1;
    while (c >= '0' && c <= '9')x *= 10, x += (c - '0'), c = getchar();
    n = x * f;
    return true;
}

template<class T>
inline void Out(T n) {
    if (n < 0) {
        putchar('-');
        n = -n;
    }
    int len = 0, data[20];
    while (n) {
        data[len++] = n % 10;
        n /= 10;
    }
    if (!len)data[len++] = 0;
    while (len--)putchar(data[len] + 48);
}

#endif //ICPC_SCANNER_HPP
