#include<iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    if (N > 40)
        return 0;
    long long a[N];
    a[0] = a[1] = 1;
    for (int i = 2; i < N; i++) {
        a[i] = a[i - 1] + a[i - 2];
    }
    for (int i = 0; i < N; i++) {
        cout << a[i];
        if (i < N - 1)cout << ' ';
    }
    return 0;
}
		
