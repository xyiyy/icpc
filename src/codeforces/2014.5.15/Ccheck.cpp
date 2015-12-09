#include <iostream>

using namespace std;

bool fun(int n) {
    for (int i = 2; i < n; i++) {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

int main() {
///	freopen ("c.out","w",stdout);
    int a = 0;
    for (int i = 2; i < 100001; i++) {
        if (fun(i)) {
            a++;
        }
    }
    cout << a << endl;
    return 0;
}
