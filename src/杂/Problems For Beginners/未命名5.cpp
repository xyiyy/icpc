#include<iostream>

using namespace std;

void Qsort(int *a, int size) {
    int pivot, temp;
    int left = 0, right = size - 1;
    if (size <= 1) return;
    pivot = a[right];
    do {
        while (left < right && a[left] >= pivot)left++;
        while (left < right && a[right] <= pivot)right--;
        if (left < right) {
            temp = a[left];
            a[left] = a[right];
            a[right] = temp;
        }
    } while (left < right);
    a[size - 1] = a[left];
    a[left] = pivot;
    Qsort(a, left);
    Qsort(a + left + 1, size - left - 1);
}


int main() {
    int a[10];
    for (int i = 0; i < 10; i++)
        cin >> a[i];
    Qsort(a, 10);
    for (int i = 0; i < 10; i++) {
        cout << a[i];
        if (i < 9)
            cout << ' ';
    }
    return 0;
}
