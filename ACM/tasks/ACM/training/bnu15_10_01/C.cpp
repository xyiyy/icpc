#include <bits/stdc++.h>
#define rep(A,X) for(int A = 0;A<X;A++)
typedef unsigned long long ull;
using namespace std;
const int MAXN = 5000010;
char w[MAXN];
char p[MAXN];
int Next[MAXN];
int now[MAXN];
char ans[MAXN];
int len1,len2;
void getNext(){
    Next[1] = 0;
    int i,j=0;
    for(i=2;i<=len1;i++){
        while(j>0&&w[j+1]!=w[i])j=Next[j];
        if(w[j+1]==w[i])j++;
        Next[i] = j;
    }
}
int num =0;
void kmp(){
    int i,j=0;
    num = 0;
    for(i=1;i<=len2;i++){
        ans[num] = p[i];
        while(j>0&&w[j+1]!=ans[num])j=Next[j];
        if(w[j+1]==ans[num])j++;
        num++;
        now[num] = j;
        if(j==len1){
            num -= len1;
            j = now[num];
        }
    }
}

int main(){
    ios::sync_with_stdio(0);

#ifdef LOCAL
    freopen("in.txt","r",stdin);
#endif
    while(scanf("%s%s",w+1,p+1)!=EOF){
        p[0] = 0;
        len1 = strlen(w+1);
        len2 = strlen(p+1);
        p[0] = '$';
        getNext();
        kmp();
        rep(i,num)printf("%c",ans[i]);
        printf("\n");
    }
    return 0;
}
