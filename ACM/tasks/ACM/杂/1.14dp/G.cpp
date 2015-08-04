#include<stdio.h>
#define MAX(a,b) a>b?a:b
int main()
{
    int n,i,j,a[100][100];
    scanf("%d",&n);
    for(i=0;i<n;i++)
        for(j=0;j<=i;j++)
            scanf("%d",&a[i][j]);
    for(i=n-2;i>=0;i--)
        for(j=i;j>=0;j--)
            a[i][j]+=MAX(a[i+1][j],a[i+1][j+1]);
    printf("%d\n",a[0][0]);
    return 0;
}
