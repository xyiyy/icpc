//
// Created by xyiyy on 2015/8/8.
//

#ifndef JHELPER_EXAMPLE_PROJECT_UNIONFINDSET_HPP
#define JHELPER_EXAMPLE_PROJECT_UNIONFINDSET_HPP

int pa[MAXN],ra[MAXN];
void init(int n){
    rep(i,n+1)pa[i] = i,ra[i] = 0;
}
int find(int x){
    if(pa[x]!=x)pa[x]=find(pa[x]);
    return pa[x];
}
int unite(int x,int y){
    x = find(x);y = find(y);
    if(x==y)return 0;
    if(ra[x]<ra[y])pa[x] = y;
    else{
        pa[y]=x;
        if(ra[x]==ra[y])ra[x]++;
    }
    return 1;
}
bool same(int x,int y){
    return find(x)==find(y);
}

#endif //JHELPER_EXAMPLE_PROJECT_UNIONFINDSET_HPP
