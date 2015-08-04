//#####################
//Author:fraud
//Blog: http://www.cnblogs.com/fraud/
//#####################
//#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>
#include <random>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int n,p;
    while(cin>>n>>p){
        int f = n/(p-1)%2;
        if(f)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
