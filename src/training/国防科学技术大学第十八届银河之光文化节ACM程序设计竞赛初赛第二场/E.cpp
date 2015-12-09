#include <stdio.h>
#include <iostream>
using namespace std;

unsigned long long ans,i;

int main()
{
    ios::sync_with_stdio(false);
   int t;
   cin>>t;
   while(t--){
        cin>>ans;
    //scanf("%I64d",&ans);

        for (i=ans-1;i>1;--i)
        {
            ans*=i;
            if (ans>10000000) ans=ans%10000000;
            while (ans%10==0) ans/=10;
        }

        printf("%d\n",ans%10);
   }
    return 0;
}
