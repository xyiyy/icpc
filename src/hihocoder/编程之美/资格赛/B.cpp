#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
char s[1010];
const ll MOD = 100007;
ll dp[1010];
ll dp2[1010];
int main(){
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    int cas=1;
    while(t--){
        cin>>s+1;
        memset(dp,0,sizeof(dp));
        memset(dp2,0,sizeof(dp2));
        int len=strlen(s+1);
        ll ans=0;
        for(int i=1;i<=len;i++){
            ll tmp=0,temp;
            ans++;
            dp[len+1]=0;
            for(int j=len;j>i;j--){
                temp=dp2[j];
                if(s[i]==s[j]){
                    dp2[j]+=tmp+1;
                    ans+=(tmp+1)*(j-i);
                    //dp2[j]%=MOD;
                    while(dp2[j]>=MOD)dp2[j]-=MOD;
                }
                tmp+=temp;
                while(tmp>=MOD)tmp-=MOD;


            }
            ans%=MOD;
            //cout<<ans<<endl;
        }
        cout<<"Case #"<<cas++<<": "<<ans<<endl;
    }
    return 0;
}
