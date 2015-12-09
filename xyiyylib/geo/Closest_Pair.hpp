//
// Created by xyiyy on 2015/8/8.
//

#ifndef ICPC_CLOSEST_PAIR_HPP
#define ICPC_CLOSEST_PAIR_HPP
const double dINF = 1e20;
const int MAXN = 100010;
const  double eps = 1e-8;
struct Point{
    double x,y;
};
double  dist(Point a,Point b){
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}
Point p[MAXN];
Point tmpt[MAXN];
bool cmpxy(Point a,Point b){
    if(a.x!=b.x)return a.x<b.x;
    else return a.y<b.y;
}
bool cmpy(Point a,Point b){
    return a.y<b.y;
}
void Closest_Pair_init(int n){
    sort(p,p+n,cmpxy);
}
double Closest_Pair(int left,int right){
    double d = dINF;
    if(left == right)return d;
    if(left + 1 == right){
        return  dist(p[left],p[right]);
    }
    int mid = (left + right)>>1;
    double d1 = Closest_Pair(left,mid);
    double d2 = Closest_Pair(mid + 1,right);
    d = min(d1,d2);
    int k = 0;
    rep2(i,left,right){
        if(fabs(p[mid].x-p[i].x)<=d)
            tmpt[k++] = p[i];
    }
    sort(tmpt,tmpt+k,cmpy);
    rep(i,k){
        for(int j = i+1;j < k && tmpt[j].y - tmpt[i].y<d; j++){
            d = min(d,dist(tmpt[i],tmpt[j]));
        }
    }
    return d;
}

#endif //ICPC_CLOSEST_PAIR_HPP
