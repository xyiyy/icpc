#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <vector>
using namespace std;
#define w(i) T[i].w
#define ls(i) T[i].ls
#define rs(i) T[i].rs
#define MAXN 100010
int p[MAXN],a[MAXN],b[MAXN],root[MAXN];
struct node{
    int ls,rs,w;
    node(){ls=rs=w=0;}
}T[MAXN*20];
int tot=0;
void Insert(int &i,int l,int r,int x){
    T[++tot]=T[i];
    i=tot;
    w(i)++;
    if(l==r)return;
    int mid=(l+r)>>1;
    if(x<=mid)Insert(ls(i),l,mid,x);
    else Insert(rs(i),mid+1,r,x);
}
int query(int lx,int rx,int l,int r,int k){
    if(l==r)return l;
    int ret=w(ls(rx))-w(ls(lx));
    int mid=(l+r)>>1;
    if(ret>=k)return query(ls(lx),ls(rx),l,mid,k);
    else return query(rs(lx),rs(rx),mid+1,r,k-ret);
}
bool cmp(int i,int j){
    return a[i]<a[j];
}
int main()
{
    ios::sync_with_stdio(false);
    tot=0;
    int n,m;
    int t;
    int cas=1;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++){
            scanf("%d",a+i);
            p[i]=i;
        }
        tot=0;
        root[0]=0;
        sort(p+1,p+n+1,cmp);
        for(int i=1;i<=n;i++)b[p[i]]=i;
        for(int i=1;i<=n;i++){
            root[i]=root[i-1];
            Insert(root[i],1,n,b[i]);
        }
        printf("Case #%d:\n",cas++);
        while(m--){
            int l,r,x,y;
            scanf("%d%d%d%d",&l,&r,&x,&y);
            int lx=1,rx=r-l+1;
            int fx=-1;
            int ans=0;
            int flag =0;
            int tmpx;
            while(lx<=rx){
                int mid = (lx+rx)>>1;
                tmpx=a[p[query(root[l-1],root[r],1,n,mid)]];
                if(tmpx<=y){
                    fx=mid;
                    lx=mid+1;
                }else rx=mid-1;
            }
            if(fx==-1)flag=1;
            else ans+=fx;
            lx=1,rx=r-l+1;
            fx=-1;
            while(lx<=rx){
                int mid = (lx+rx)>>1;
                tmpx=a[p[query(root[l-1],root[r],1,n,mid)]];
                if(tmpx>=x){
                    fx=mid;
                    rx=mid-1;
                }else lx=mid+1;
            }
            if(fx==-1)flag=1;
            else ans=ans-fx+1;
            if(flag)ans=0;
            printf("%d\n",ans);
        }
    }
    return 0;
}
