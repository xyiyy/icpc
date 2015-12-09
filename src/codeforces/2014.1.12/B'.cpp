#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <string>
#include <set>
#include <cmath>
#include <queue>
#include <algorithm>

using namespace std;

typedef unsigned long long int ull;
typedef long long int ll;


int counters[5002];

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i)
    {
        int a;
        scanf("%d", &a);
        counters[a]++;
    }

    vector<int> v;
    v.reserve(10000);

    for (int i = 0; i <= 5000; ++i)
    {
        if (counters[i] > 0)
            v.push_back(i);
    }

    for (int i = v.back() - 1; i >= 0; --i)
    {
        if (counters[i] > 1)
            v.push_back(i);
    }

    printf("%d\n", v.size());

    for (int i = 0; i < v.size(); ++i)
        printf("%d ", v[i]);
    return 0;
}
