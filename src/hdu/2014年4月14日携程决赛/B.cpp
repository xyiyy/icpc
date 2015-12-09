#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
const double eps=1e-6;
const double inf=1e10;
int dcmp(double x)
{
    if(fabs(x)<eps) return 0;
    else return x<0?-1:1;
}
struct point
{
    double x,y;
    point(double x=0,double y=0):x(x),y(y){}
};
point operator-(point a,point b){return point(a.x-b.x,a.y-b.y);}
point operator+(point a,point b){return point(a.x+b.x,a.y+b.y);}
point operator*(point a,double p){return point(a.x*p,a.y*p);}
bool operator<(const point& a,const point& b)
{
    return a.x<b.x||(a.x==b.x&&a.y<b.y);
}
bool operator==(const point& a,const point& b)
{
    return dcmp(a.x-b.x)==0&&dcmp(a.y-b.y)==0;
}
double cross(point a,point b){return a.x*b.y-a.y*b.x;}
double dot(point a,point b){return a.x*b.x+a.y*b.y;}
double length(point a){return sqrt(dot(a,a));}
point normal(point a)
{
    double l=length(a);
    return point(a.x/l,a.y/l);
}
double distoline(point p,point a,point b)
{
    point v1=b-a,v2=p-a;
    return fabs(cross(v1,v2))/length(v1);
}
vector<point> p;
double mina,minp;
vector<point> convex(vector<point>& p)
{
    sort(p.begin(),p.end());
    int n=p.size();
    vector<point> ch(n+1);
    int m=0;
    for(int i=0;i<n;i++)
    {
        while(m>1&&cross(ch[m-1]-ch[m-2],p[i]-ch[m-2])<=0) m--;
        ch[m++]=p[i];
    }
    int k=m;
    for(int i=n-2;i>=0;i--)
    {
        while(m>k&&cross(ch[m-1]-ch[m-2],p[i]-ch[m-2])<=0) m--;
        ch[m++]=p[i];
    }
    if(n>1) m--;
    ch.resize(m);
    return ch;
}
void rotating_calipers(vector<point>& points)
{
    vector<point> p=convex(points);
    int n=p.size();
    p.push_back(p[0]);
    mina=inf;minp=inf;
    int l=1,r=1,u=1;
    for(int i=0;i<n;i++)
    {
        point edge=normal(p[(i+1)%n]-p[i]);
        while(dot(edge,p[r%n]-p[i])<dot(edge,p[(r+1)%n]-p[i])) r++;
        while(u<r||cross(edge,p[u%n]-p[i])<cross(edge,p[(u+1)%n]-p[i])) u++;
        while(l<u||dot(edge,p[l%n]-p[i])>dot(edge,p[(l+1)%n]-p[i])) l++;
        double w=dot(edge,p[r%n]-p[i])-dot(edge,p[l%n]-p[i]);
        double h=distoline(p[u%n],p[i],p[(i+1)%n]);
        mina=min(mina,w*h);
        minp=min(minp,2*(w+h));
    }
}
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        if(!n) break;
        p.clear();
        for(int i=0;i<n;i++)
        {
            double x,y;
            scanf("%lf%lf",&x,&y);
            p.push_back(point(x,y));
        }
        rotating_calipers(p);
        printf("%.6f\n",minp);
    }
    return 0;
}
