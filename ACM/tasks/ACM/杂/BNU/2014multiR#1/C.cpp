#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<string>

const  double INF=0x3fffffff;

const  double eps=1e-10;
const double PI=acos(-1.0);

using namespace std;


struct Point{
    double x;
    double y;
    Point(double x=0,double y=0):x(x),y(y){}
    
};

int dcmp(double x)  {return (x>eps)-(x<-eps); }
int sgn(double x)  {return (x>eps)-(x<-eps); }
typedef  Point  Vector;

Vector  operator +(Vector A,Vector B) { return Vector(A.x+B.x,A.y+B.y);}

Vector  operator -(Vector A,Vector B) { return Vector(A.x-B.x,A.y-B.y); }

Vector  operator *(Vector A,double p) { return Vector(A.x*p,A.y*p);  }

Vector  operator /(Vector A,double p) {return Vector(A.x/p,A.y/p);}



ostream &operator<<(ostream & out,Point & P) { out<<P.x<<' '<<P.y; return out;}
//
bool  operator< (const Point &A,const Point &B) { return dcmp(A.x-B.x)<0||(dcmp(A.x-B.x)==0&&dcmp(A.y-B.y)<0); }



bool  operator== ( const Point &A,const Point &B) { return dcmp(A.x-B.x)==0&&dcmp(A.y-B.y)==0;}


double  Dot(Vector A,Vector B) {return A.x*B.x+A.y*B.y;}

double  Cross(Vector A,Vector B)  {return A.x*B.y-B.x*A.y; }

double  Length(Vector A)  { return sqrt(Dot(A, A));}


double  Angle(Vector A,Vector B) {return acos(Dot(A,B)/Length(A)/Length(B));}

double  Area2(Point A,Point B,Point C ) {return Cross(B-A, C-A);}

Vector Rotate(Vector A,double rad) { return Vector(A.x*cos(rad)-A.y*sin(rad),A.x*sin(rad)+A.y*cos(rad));}
Vector Normal(Vector A) {double L=Length(A);return Vector(-A.y/L,A.x/L);}

Point GetLineIntersection(Point P,Vector v,Point Q,Vector w)
{
    Vector u=P-Q;
    double t=Cross(w, u)/Cross(v,w);
    return P+v*t;
    
}

double DistanceToLine(Point P,Point A,Point B)
{
    Vector v1=P-A; Vector v2=B-A;
    return fabs(Cross(v1,v2))/Length(v2);
    
}

double DistanceToSegment(Point P,Point A,Point B)
{
    if(A==B)  return Length(P-A);
    
    Vector v1=B-A;
    Vector v2=P-A;
    Vector v3=P-B;
    
    if(dcmp(Dot(v1,v2))==-1)    return  Length(v2);
    else if(Dot(v1,v3)>0)    return Length(v3);
    
    else return DistanceToLine(P, A, B);
    
}

Point GetLineProjection(Point P,Point A,Point B)
{
    Vector v=B-A;
    Vector v1=P-A;
    double t=Dot(v,v1)/Dot(v,v);
    
    return  A+v*t;
}

bool  SegmentProperIntersection(Point a1,Point a2,Point b1,Point b2)
{
    double c1=Cross(b1-a1, a2-a1);
    double c2=Cross(b2-a1, a2-a1);
    double c3=Cross(a1-b1, b2-b1);
    double c4=Cross(a2-b1, b2-b1);
    
    return dcmp(c1)*dcmp(c2)<0&&dcmp(c3)*dcmp(c4)<0 ;
    
}

bool  OnSegment(Point P,Point A,Point B)
{
    return dcmp(Cross(P-A, P-B))==0&&dcmp(Dot(P-A,P-B))<=0;
}

bool  SegmentCommon(Point a1,Point a2,Point b1,Point b2)
{
    double c1=Cross(b1-a1, a2-a1);
    double c2=Cross(b2-a1, a2-a1);
    double c3=Cross(a1-b1, b2-b1);
    double c4=Cross(a2-b1, b2-b1);
    
    if(c1==0&&c2==0&&c3==0&&c4==0)
    {
        if(OnSegment(a1, b1, b2))  return 1;
        if(OnSegment(a2, b1, b2))  return 1;
        
        return 0;
    }
    
    return dcmp(c1)*dcmp(c2)<=0&&dcmp(c3)*dcmp(c4)<=0 ;
    
}

double PolygonArea(Point *p,int n)
{
    double area=0;
    
    for(int i=1;i<n-1;i++)
    {
        area+=Cross(p[i]-p[0], p[i+1]-p[0]);
        
    }
    return area/2;
    
}

Point  read_point()
{
    Point P;
    
    scanf("%lf%lf",&P.x,&P.y);
    
    return  P;
}

// ---------------与圆有关的--------

struct Circle
{
    Point c;
    double r;
    
    Circle(Point c=Point(0,0),double r=0):c(c),r(r) {}
    
    Point point(double a)
    {
        return Point(c.x+r*cos(a),c.y+r*sin(a));
    }
    
    
};

struct  Line
{
    Point p;
    Vector v;
    Line(Point p=Point(0,0),Vector v=Vector(0,1)):p(p),v(v) {}
    
    Point point(double t)
    {
        return Point(p+v*t);
    }
    
};

int getLineCircleIntersection(Line L,Circle C,double &t1,double &t2,vector<Point> &sol)
{
    double a=L.v.x;
    double b=L.p.x-C.c.x;
    double c=L.v.y;
    double d=L.p.y-C.c.y;
    
    double e=a*a+c*c;
    double f=2*(a*b+c*d);
    double g=b*b+d*d-C.r*C.r;
    
    double delta=f*f-4*e*g;
    
    if(dcmp(delta)<0) return 0;
    
    if(dcmp(delta)==0)
    {
        t1=t2=-f/(2*e);
        sol.push_back(L.point(t1));
        return 1;
    }
    
    else
    {
        t1=(-f-sqrt(delta))/(2*e);
        t2=(-f+sqrt(delta))/(2*e);
        
        sol.push_back(L.point(t1));
        sol.push_back(L.point(t2));
        
        return 2;
    }
    
}

// 向量极角公式

double angle(Vector v)  {return atan2(v.y,v.x);}

int getCircleCircleIntersection(Circle C1,Circle C2,vector<Point> &sol)
{
    double d=Length(C1.c-C2.c);
    
    if(dcmp(d)==0)
    {
        if(dcmp(C1.r-C2.r)==0)  return -1;  // 重合
        else return 0;    //  内含  0 个公共点
    }
    
    if(dcmp(C1.r+C2.r-d)<0)  return 0;  // 外离
    if(dcmp(fabs(C1.r-C2.r)-d)>0)  return 0;  // 内含
    
    double a=angle(C2.c-C1.c);
    double da=acos((C1.r*C1.r+d*d-C2.r*C2.r)/(2*C1.r*d));
    
    Point p1=C1.point(a-da);
    Point p2=C1.point(a+da);
    
    sol.push_back(p1);
    
    if(p1==p2)  return 1; // 相切
    else
    {
        sol.push_back(p2);
        return 2;
    }
}


//  求点到圆的切线

int getTangents(Point p,Circle C,Vector *v)
{
    Vector u=C.c-p;
    
    double dist=Length(u);
    
    if(dcmp(dist-C.r)<0)  return 0;
    
    else if(dcmp(dist-C.r)==0)
    {
        v[0]=Rotate(u,PI/2);
        return 1;
    }
    
    else
    {
        
        double ang=asin(C.r/dist);
        v[0]=Rotate(u,-ang);
        v[1]=Rotate(u,+ang);
        return 2;
    }
    
}

//  求两圆公切线


int getTangents(Circle A,Circle B,Point *a,Point *b)
{
    int cnt=0;
    
    if(A.r<B.r)
    {
        swap(A,B); swap(a, b);  //  有时需标记
    }
    
    double d=Length(A.c-B.c);
    
    double rdiff=A.r-B.r;
    double rsum=A.r+B.r;
    
    if(dcmp(d-rdiff)<0)  return 0;   // 内含
    
    double base=angle(B.c-A.c);
    
    if(dcmp(d)==0&&dcmp(rdiff)==0)   return -1 ;  // 重合 无穷多条切线
    
    if(dcmp(d-rdiff)==0)             // 内切   外公切线
    {
        a[cnt]=A.point(base);
        b[cnt]=B.point(base);
        cnt++;
        return 1;
    }
    
    // 有外公切线的情形
    
    double ang=acos(rdiff/d);
    a[cnt]=A.point(base+ang);
    b[cnt]=B.point(base+ang);
    cnt++;
    a[cnt]=A.point(base-ang);
    b[cnt]=B.point(base-ang);
    cnt++;
    
    if(dcmp(d-rsum)==0)     // 外切 有内公切线
    {
        a[cnt]=A.point(base);
        b[cnt]=B.point(base+PI);
        cnt++;
    }
    
    else  if(dcmp(d-rsum)>0)   // 外离   又有两条外公切线
    {
        double  ang_in=acos(rsum/d);
        a[cnt]=A.point(base+ang_in);
        b[cnt]=B.point(base+ang_in+PI);
        cnt++;
        a[cnt]=A.point(base-ang_in);
        b[cnt]=B.point(base-ang_in+PI);
        cnt++;
    }
    
    return cnt;
}


//  几何算法模板

int  isPointInPolygon(Point p,Point * poly,int n)
{
    int wn=0;
    for(int i=0;i<n;i++)
    {
        if(OnSegment(p, poly[i], poly[(i+1)%n]))  return -1;
        int k=dcmp(Cross(poly[(i+1)%n]-poly[i], p-poly[i]));
        int d1=dcmp(poly[i].y-p.y);
        int d2=dcmp(poly[(i+1)%n].y-p.y);
        
        if(k>0&&d1<=0&&d2>0) wn++;
        if(k<0&&d2<=0&&d1>0) wn--;
        
    }
    
    if(wn!=0)  return 1;
    else   return 0;
    
}

bool  SegmentLineIntersection(Point a1,Point a2,Point b1,Point b2)  //a1,a2 是直线  规范相交
{
    double c1=Cross(b1-a1, a2-a1);
    double c2=Cross(b2-a1, a2-a1);
    return dcmp(c1)*dcmp(c2)<=0;
}


Point ori(0,0);
Point o_X(1,0);

int n;
double L,R;

struct Segment{
    Point A;
    Point B;
    Segment(Point A=ori,Point B=ori):A(A),B(B) {}
    
};

bool seg_cmp(Segment A,Segment B)
{
    return  A.A<B.A;
    
}

Point a[2005],b[2005],a1[2005],a2[2005],b1[2005],b2[2005];

Circle C1[2005],C2[2005];
Segment s[2005];


vector<Point> inter[2005];
double  minDist(double x)
{
    Point p=Point(x,0);
    bool first=1;
    
    double ans=0;
    for(int i=0;i<n;i++)
    {
      
      if(first)
      {
          ans=DistanceToSegment(p, a[i], b[i]);
          first=0;
      }
      else
      {
          ans=min(ans,DistanceToSegment(p, a[i], b[i]));
          
      }
    }
    
    return ans;
}

vector<Segment> Union;



Line ox=Line(ori,Vector(1,0));

bool toobig(double x)
{
    // init
    //!
    for(int i=0;i<n;i++)
    {
        s[i]=Segment(ori,ori);
    }
    Union.clear();
    
    for(int i=0;i<n;i++)
    {
        inter[i].clear();
    }
    
    
    for(int i=0;i<n;i++)
    {
        C1[i].r=x;
        C2[i].r=x;
    }
    
    double t1,t2;
    for(int i=0;i<n;i++)
    {
        getLineCircleIntersection(ox,C1[i], t1, t2,inter[i]);
        getLineCircleIntersection(ox,C2[i], t1, t2,inter[i]);
        
        Vector norm=Normal(b[i]-a[i]);
       
        a1[i]=a[i]+norm*x;
        a2[i]=a[i]-norm*x;
        
        b1[i]=b[i]+norm*x;
        b2[i]=b[i]-norm*x;
    
        if(SegmentLineIntersection(ori, o_X, a1[i], b1[i]))
        {
           if(dcmp(Cross(o_X,b1[i]-a1[i]))!=0)
              {
                  Point ip=GetLineIntersection(ori, o_X, a1[i], b1[i]-a1[i]);
                  inter[i].push_back(ip);
              }
        }
        
        
        if(SegmentLineIntersection(ori, o_X, a2[i], b2[i]))
        {
            if(dcmp(Cross(o_X,b2[i]-a2[i]))!=0)
            {
                 Point ip=GetLineIntersection(ori, o_X, a2[i], b2[i]-a2[i]);
                 inter[i].push_back(ip);
            }
        }
        
        
        sort(inter[i].begin(),inter[i].end());
    
        int sz=inter[i].size();
        
        if(sz>1)
        {
            Point i_l=inter[i][0];
            Point i_r=inter[i][sz-1];
            
            s[i].A=i_l;
            s[i].B=i_r;
            
        }
        
     
        
    }
    
    s[n]=Segment(Point(-INF,0),Point(L,0));
    s[n+1]=Segment(Point(R,0),Point(INF,0));
    
    sort(s,s+n+2,seg_cmp);
    
    Union.push_back(s[0]);
    for(int i=1;i<n+2;i++)
    {
        if(s[i].A==ori&&s[i].B==ori)  continue;
        
        Segment seg=Union[Union.size()-1];
        Union.erase(Union.end()-1);
        
        if(seg.B<s[i].A||seg.B==s[i].A)
        {
            Union.push_back(seg);
            Union.push_back(s[i]);
            
        }
        
        else
        {
            Segment newseg=Segment(seg.A,max(seg.B,s[i].B));
            Union.push_back(newseg);
        }
        
    }
    
    
    if(Union.size()==1)  return 1;
    
    else  return 0;
    
}

int main()
{
  
    int T;
    cin>>T;
    while(T--)
    {
        L=0;
        cin>>n>>R;
        for(int i=0;i<n;i++)
        {
            a[i]=read_point();
            b[i]=read_point();
            C1[i].c=a[i];
            C2[i].c=b[i];
        }
        
        
        
        double l=0,r=INF;
        
        double mid;
        
        
        for(int i=0;i<50;i++)
        {
            mid=l+(r-l)/2;
            
            if(toobig(mid))
            {
                r=mid;
                
            }
            
            else l=mid;
            
            
        }
        
        printf("%.3f\n",mid);
        
    }
}

