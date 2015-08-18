//
// Created by xyiyy on 2015/8/17.
//

#ifndef ICPC_SBT_HPP
#define ICPC_SBT_HPP

struct SBT{
    int left,right,size,key;
    void init() {
        left=right=key=0;
        size=1;
    }
}sbt[MAXN];
int root,tot;
void left_rot(int &x){
    int k=sbt[x].right;
    sbt[x].right=sbt[k].left;
    sbt[k].left=x;
    sbt[k].size=sbt[x].size;
    sbt[x].size=sbt[sbt[x].left].size+sbt[sbt[x].right].size+1;
    x=k;
}
void right_rot(int &x){
    int k=sbt[x].left;
    sbt[x].left=sbt[k].right;
    sbt[k].right=x;
    sbt[k].size=sbt[x].size;
    sbt[x].size=sbt[sbt[x].left].size+sbt[sbt[x].right].size+1;
    x=k;
}
void maintain(int &r,bool flag) {
    if(flag) {
        if(sbt[sbt[sbt[r].right].right].size>sbt[sbt[r].left].size)
            left_rot(r);
        else if(sbt[sbt[sbt[r].right].left].size>sbt[sbt[r].left].size) {
            right_rot(sbt[r].right);
            left_rot(r);
        }
        else
            return ;
    }
    else {
        if(sbt[sbt[sbt[r].left].left].size>sbt[sbt[r].right].size)
            right_rot(r);
        else if(sbt[sbt[sbt[r].left].right].size>sbt[sbt[r].right].size) {
            left_rot(sbt[r].left);
            right_rot(r);
        }
        else
            return;
    }
    maintain(sbt[r].left,false);
    maintain(sbt[r].right,true);
    maintain(r,false);
    maintain(r,true);
}

void insert(int &r,int k) {
    if(r==0){
        r=++tot;
        sbt[r].init();
        sbt[r].key=k;
    }
    else {
        sbt[r].size++;
        if(k<sbt[r].key)
            insert(sbt[r].left,k);
        else
            insert(sbt[r].right,k);
        maintain(r,k>=sbt[r].key);
    }
}
void del(int &r,int delay,int m){
    if(!r)return;
    if(sbt[r].key+delay<m){
        r=sbt[r].right;
        del(r,delay,m);
    }
    else {
        del(sbt[r].left,delay,m);
        sbt[r].size=sbt[sbt[r].right].size+sbt[sbt[r].left].size+1;
    }
}
int query(int &r,int k){
    int t=sbt[sbt[r].right].size+1;
    if(t==k)return sbt[r].key;
    if(t<k)return query(sbt[r].left,k-t);
    else   return query(sbt[r].right,k);
}


#endif //ICPC_SBT_HPP
