#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

ll lcm(ll a, ll b)
{
    return a/__gcd(a,b)*b;
}

ll a[20];

int main()
{
//	freopen("1785.in","r",stdin);
//	freopen("1785.out","w",stdout);
    int n,l;
    while(cin>>l>>n)
    {
        for(int i=0;i<n;i++) cin>>a[i];
        ll ans=0;
        for(int i=0;i<(1<<n);i++)
        {
            int t=i, c=0;
            ll g=1;
            for(int j=0;j<n;j++)
            {
                if(t&1) g=lcm(g,a[j]);
                if(t&1) c++;
                t/=2;
            }
            if(c&1) ans -= l/g;
            else ans += l/g;
        }
        cout<<l-ans<<endl;
    }
    return 0;
}

