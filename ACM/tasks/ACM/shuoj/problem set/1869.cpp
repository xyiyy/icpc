#include <iostream>
#include <cstring>
using namespace std;
char a[10010];
string b[10010];
int main(){
    int cas=1;
    while(cin.getline(a,100010,'\n')!=NULL){
            cout<<"Case "<<cas++<<":"<<endl;
        int tot = 0;
        int len = strlen(a);
        for(int i=0;i<len;){
            if(a[i]>='0'&&a[i]<='9'){
                b[tot]="";
                while(a[i]>='0'&&a[i]<='9'&&i<len){
                    b[tot]=b[tot]+a[i];
                    i++;
                }
                tot++;
            }else i++;
        }
        for(int i=0;i<tot;i++){
                if(i)cout<<" ";
            len = b[i].length();
            int j = 0;
            while(b[i][j]=='0'&&j<len-1)j++;
            for(;j<len;j++){
                cout<<b[i][j];
            }
        }
        cout<<endl;
    }
    return 0;
}
