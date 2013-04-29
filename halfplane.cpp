#include <iostream>
#include <cmath>
#define maxn 10010
using namespace std;
const double inf=1e6;
const double eps=1e-8;
int dblcmp(double a,double b)
{
  if(fabs(a-b)<=eps)return 0;
  return a<b?-1:1;    
}
typedef struct point
{
  double x,y;
  bool operator == (point a)
    {return dblcmp(a.x,x)==0&&dblcmp(a.y,y)==0;}
};
typedef struct line
{
  double a,b,c;        
};
point area[maxn],next[maxn];
line plane[maxn];
int n,cnt;
void init()
{
  freopen("polygon.in","r",stdin);
  freopen("polygon.out","w",stdout);
  scanf("%d",&n);
  int i=1;
  for(i=1;i<=n;i++)
    scanf("%lf%lf%lf",&plane[i].a,&plane[i].b,&plane[i].c);
  area[1].x=-inf;area[1].y=-inf;
  area[2].x=-inf;area[2].y=inf;
  area[3].x=inf;area[3].y=inf;
  area[4].x=inf;area[4].y=-inf;
  cnt=4;
}
inline bool in(int a,point b)
{
  double t=b.x*plane[a].a+b.y*plane[a].b+plane[a].c;
  return dblcmp(t,0)<=0;
}
point inter(line a,line b)
{
  point ans;
  ans.x=(a.b*b.c-b.b*a.c)/(a.a*b.b-b.a*a.b);
  ans.y=(b.a*a.c-a.a*b.c)/(a.a*b.b-b.a*a.b);
  return ans;
}
void calc()
{
  int i,j,top;
  point P;
  line L;
  for(i=1;i<=n;i++)
    {
      area[cnt+1]=area[1];
      for(j=1,top=0;j<=cnt;j++)
        {
          L.a=area[j+1].y-area[j].y;
          L.b=area[j].x-area[j+1].x;
          L.c=area[j+1].x*area[j].y-area[j].x*area[j+1].y;
          if(in(i,area[j]))
            {
              if(top==0||!(area[j]==next[top]))
                next[++top]=area[j];
              if(in(i,area[j+1]))
                next[++top]=area[j+1];
              else
                next[++top]=inter(L,plane[i]);
            }
          else
            if(in(i,area[j+1]))
              {
                next[++top]=inter(L,plane[i]);
                next[++top]=area[j+1];
              }  
        }
      cnt=top;
      memcpy(area,next,sizeof(next));
      if(area[1]==area[cnt])cnt--;
    }
  area[cnt+1]=area[1];
  double ans;
  for(i=1;i<=cnt;i++)
    ans+=area[i].x*area[i+1].y-area[i].y*area[i+1].x;
  ans/=2;
  printf("%.0lf",fabs(ans));
}
int main()
{
  init();
  calc();
  return 0;    
}
