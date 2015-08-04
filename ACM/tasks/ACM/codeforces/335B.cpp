#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
using namespace std;
string s;
char str[1010];
char str2[1010];
int main()
{
    cin>>s;
    int len=s.length();
    len=min(len,2600);
    int last=len;
    int tot=0;
    for(int i=0;i<=last;i++){
        if(i==last&&s[i-1]!=s[last])str[tot++]=s[i-1];
        for(int j=last-1;j>i;j--){
            if(s[i]==s[j]){
                str[tot]=s[i];
                str2[tot++]=s[j];
                last=j;
                break;
            }
        }
        if(tot==50)break;
    }
    len=strlen(str2);
    for(int i=0;i<tot;i++)cout<<str[i];
    for(int i=len-1;i>=0;i--)cout<<str2[i];
    cout<<endl;
    return 0;
}
