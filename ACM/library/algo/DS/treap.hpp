//
// Created by xyiyy on 2015/8/5.
//

#ifndef JHELPER_EXAMPLE_PROJECT_TREAP_HPP
#define JHELPER_EXAMPLE_PROJECT_TREAP_HPP
int key[MAXN],size[MAXN],lson[MAXN],rson[MAXN];
int sum[MAXN],p[MAXN],del[MAXN];
int tot=0,tot1=0;
void init(){
    key[0] = size[0] = lson[0] = rson[0] = 0;
    tot = tot1 = 0;
}
int newnode(int k){
    int r ;
    if(tot1){
        r = del[tot1--];
    }else r = ++tot;
    key[r] = k;
    sum[r] = k;
    p[r] = rand();
    size[r] = 1;
    lson[r] = rson[r] = 0;
    return r;
}

int change(int t,int l,int r){
    size[t] = size[l] + size[r] + 1;
    sum[t] = sum[l] + sum[r] + key[t];
    lson[t] = l;
    rson[t] = r;
    return t;
}

void splitsize(int t,int s,int *ret){
    if(s<=0){
        ret[0] = 0;
        ret[1] = t;
    }else if(s<=size[lson[t]]){
        splitsize(lson[t],s,ret);
        ret[1] = change(t,ret[1],rson[t]);
    }else{
        splitsize(rson[t],s-size[lson[t]]-1,ret);
        ret[0] = change(t,lson[t],ret[0]);
    }
}
void splitkey(int t,int k,int *ret){
    if(!t){
        ret[0] = ret[1] = 0;
    }else if(kA<key[t]){
        splitkey(lson[t],k,ret);
        ret[1] = change(t,ret[1],rson[t]);
    }else{
        splitkey(rson[t],k,ret);
        ret[0] = change(t,lson[t],ret[0]);
    }
}
int merge(int t1,int t2){
    if(!t1)return t2;
    if(!t2)return t1;
    if(p[t1]<p[t2])return change(t1,lson[t1],merge(rson[t1],t2));
    return change(t2,merge(t1,lson[t2]),rson[t2]);
}

#endif //JHELPER_EXAMPLE_PROJECT_TREAP_HPP
