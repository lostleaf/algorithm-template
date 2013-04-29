#include <iostream>
#include <cmath>
#define maxn 110
const double eps=1e-7;
typedef struct point
{double x,y;};
typedef struct node
{double l1,r1,l2,r2;};
node T[maxn*maxn*maxn];
point tri[maxn][4];
double event[maxn*maxn*maxn];
int n,m;
int dblcmp(double a,double b)
{
  if(fabs(a-b)<eps)return 0;
  return a<b?-1:1;
}
double cross(point a,point b,point c)
{return (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);}
bool chk(point a,point b,point c,point d)
{
  return (dblcmp(cross(a,b,c)*cross(a,b,d),0)<0)&&
         (dblcmp(cross(c,d,a)*cross(c,d,b),0)<0);
}
int cmp(const void *a,const void *b)
{return dblcmp(*(double *)a,*(double *)b);}
point inter(point a,point b,point c,point d)
{
  point p;
  double a1,a2,b1,b2,c1,c2;//ax+by=c
  a1=b.y-a.y;a2=d.y-c.y;
  b1=a.x-b.x;b2=c.x-d.x;
  c1=a.x*b.y-b.x*a.y;c2=c.x*d.y-d.x*c.y;
  double D,D1,D2;
  D=a1*b2-b1*a2;
  D1=c1*b2-c2*b1;
  D2=a1*c2-a2*c1;
  p.x=D1/D;p.y=D2/D;
  return p;
}
void init()
{
  freopen("tri.in","r",stdin);
  freopen("tri.out","w",stdout);
  scanf("%d",&n);
  int i,j,k,l;
  point p;
  for(i=1;i<=n;i++)
    {
      for(j=0;j<3;j++)
        {
          scanf("%lf%lf",&tri[i][j].x,&tri[i][j].y);
          event[++m]=tri[i][j].y;
        }
      tri[i][3]=tri[i][0];
    }
  for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
      if(i!=j)
      for(k=0;k<3;k++)
        for(l=0;l<3;l++)
          if(chk(tri[i][k],tri[i][k+1],tri[j][l],tri[j][l+1]))
            {
              p=inter(tri[i][k],tri[i][k+1],tri[j][l],tri[j][l+1]);
              event[++m]=p.y;
            }
  qsort(event+1,m,sizeof(double),cmp);
  int mm;
  for(i=1,mm=1;i<=m;i++)
    if(dblcmp(event[i],event[mm])!=0)
      event[++mm]=event[i];
  m=mm;
}
int cmp1(const void *a,const void *b)
{
  node aa=*(node *)a,bb=*(node *)b;
  return dblcmp(aa.l1+aa.l2,bb.l1+bb.l2);
}
double work(double y1,double y2)
{
  int c1,c2,i,j,c,cnt=0;
  double t1,t2,A,B,P1[5],P2[5];
  for(i=1;i<=n;i++)
    {
      for(c1=c2=j=0;j<3;j++)
        {
          t1=tri[i][j].y<?tri[i][j+1].y;
          t2=tri[i][j].y>?tri[i][j+1].y;
          if(dblcmp(y1,t1)>=0&&dblcmp(y1,t2)<=0)
            {
              A=y1-tri[i][j].y;B=y1-tri[i][j+1].y;
              if(dblcmp(A,B)==0)
                {P1[c1++]=tri[i][j].x;P1[c1++]=tri[i][j+1].x;}
              else
                P1[c1++]=(A*tri[i][j+1].x-B*tri[i][j].x)/(A-B);
            }        
          if(dblcmp(y2,t1)>=0&&dblcmp(y2,t2)<=0)
            {
              A=y2-tri[i][j].y;B=y2-tri[i][j+1].y;
              if(dblcmp(A,B)==0)
                {P2[c2++]=tri[i][j].x;P2[c2++]=tri[i][j+1].x;}
              else
                P2[c2++]=(A*tri[i][j+1].x-B*tri[i][j].x)/(A-B);
            }
        }
      if(c1==0||c2==0)continue;
      ++cnt;
      for(T[cnt].l1=T[cnt].r1=P1[0],j=0;j<c1;j++)
        T[cnt].l1<?=P1[j],T[cnt].r1>?=P1[j];
      for(T[cnt].l2=T[cnt].r2=P2[0],j=0;j<c2;j++)
        T[cnt].l2<?=P2[j],T[cnt].r2>?=P2[j];
    }    
  memset(&T[cnt+1],0,sizeof(T[cnt+1]));    
  qsort(T+1,cnt,sizeof(T[0]),cmp1);
  for(i=2,c=1;i<=cnt;i++)
    if(dblcmp(T[i].l1+T[i].l2,T[c].r2+T[c].r1)<=0)
      T[c].r1>?=T[i].r1,T[c].r2>?=T[i].r2;
    else
      T[++c]=T[i];
  double ans=0;
  for(i=1;i<=c;i++)
    ans+=(T[i].r2+T[i].r1-T[i].l2-T[i].l1)*(y2-y1)/2;
  return ans;
}
void calc()
{
  double ans=0;
  for(int i=1;i<m;i++)
    ans+=work(event[i],event[i+1]);
  printf("%lf",ans);
}
int main()
{
  init();
  calc();
  return 0;    
}

