#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
string str;
int main(){
    ios::sync_with_stdio(false);
    //freopen("A-large.in","r",stdin);
    //freopen("a.out","w",stdout);
    int t;
    cin>>t;
    int cas=1;
    while(t--){
        int tot=0;
        int n;
        cin>>n;
        cin>>str;
        int ans=0;
        int len =str.length();
        //cout<<str<<endl;
        //cout<<len<<endl;
        //system("pause");
        for(int i=0;i<len;i++){
            if(tot<i)ans+=i-tot,tot=i;
            tot+=str[i]-'0';
        }
        cout<<"Case #"<<cas++<<": ";
        cout<<ans<<endl;
    }
    return 0;
}
