#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
struct coodinate{
 double x;
 double y;
}c[101];
int cmd(coodinate a,coodinate b)            
{
 double c,d;
 c=a.x/sqrt(a.x*a.x+a.y*a.y);
 d=b.x/sqrt(b.x*b.x+b.y*b.y);
 return c>d;
}
int main ()
{
 int m,i;
 while(scanf("%d",&m)!=EOF&&m>=0)   
 {
  for(i=0;i<101;i++)
  {
   c[i].x=0;c[i].y=0; 
  }
  for(i=0;i<m;i++)
  {
   scanf("%lf%lf",&c[i].x,&c[i].y);

  }
  sort(c,c+m,cmd);
  for(i=0;i<m-1;i++)
  {
   printf("%.1lf %.1lf ",c[i].x,c[i].y);
  }
  printf("%.1lf %.1lf\n",c[m-1].x,c[m-1].y);
 }
 return 0;
}
