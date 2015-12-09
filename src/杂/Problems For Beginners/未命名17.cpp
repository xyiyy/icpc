#include<iostream>

using namespace std;

int main() {
    long long a[35];
    int N;
    cin >> N;
    if (N > 35)return 0;
    a[0] = 3;
    a[1] = 4;
    a[2] = 5;
    for (int i = 3; i < N; i++) {
        a[i] = a[i - 1] + a[i - 2] + a[i - 3];
    }
    cout << a[N - 1];
    return 0;
}
	
