#include<iostream>

using namespace std;

int main() {
    int m, n = 1, s = 0;
    cin >> m;
    while (s <= m) {
        s += n * n * n;
        n++;
    }
    cout << n - 2;
    return 0;
}
	
