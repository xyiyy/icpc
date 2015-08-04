#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int main(){
    freopen("D-small-attempt4.in","r",stdin);
    freopen("dsmall.out","w",stdout);
    int t;
    int cas=1;
    cin>>t;
    while(t--){
        int x,r,c;
        cin>>x>>r>>c;
        //for(int x=1;x<5;x++){
        //   for(int r=1;r<5;r++){
         //           for(int c=1;c<5;c++){
        int f=0;
        if(r*c/x*x!=r*c)f=1;
        else{
            if(x==1||x==2)f=0;
            else{
                if(r*c==3)f=1;
                else if(r*c==4)f=1;
                else if(r*c==8)f=1;
                else if(r*c==9)f=1;
                else if(r*c==12&&x==4)f=1;
                else if(r*c==16)f=1;
            }
        }
        cout<<"Case #"<<cas++<<": ";

        //if(x==4&&r*c==16)f=1;
        if(f)cout<<"RICHARD"<<endl;
        else cout<<"GABRIEL"<<endl;
    }
    return 0;
}
