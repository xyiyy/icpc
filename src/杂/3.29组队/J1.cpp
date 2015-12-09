#include<iostream>

using namespace std;


int f(int x) {
    if (x == 0) return 0;
    return f(x / 10) + x % 10;
}

inline bool ff(int x) {
    if (x % f(x) == 0)
        return 1;
}


int main() {
    int num;
    freopen("fuck.out", "w", stdout);
    for (int i = 1; i < 1000000001; i++) {
        if (ff(i))num++;
        if (i % 250000 == 0) {
            cout << num << ',';
            num = 0;
        }
    }
    return 0;
}
		
