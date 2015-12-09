#include<iostream>

using namespace std;

int main() {
    long long sum = 0;
    long long n = 1;
    int N;
    cin >> N;
    if (N > 20)return 0;
    for (int i = 1; i <= N; i++) {
        n = 1;
        for (int j = 1; j <= i; j++) {
            n *= j;
        }
        sum += n;
    }
    cout << sum;
    return 0;
}
