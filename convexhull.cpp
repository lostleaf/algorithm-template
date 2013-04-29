#include <iostream>
#include <cmath>
#define maxn 200100
using namespace std;
typedef long long ll;
typedef struct point
{int x,y;};  
bool operator !=(point a,point b)
{return b.x!=b.x||a.y!=b.y;}
point hull[maxn],dat[maxn];
int n,st[maxn],top,m;
int cmp(point a,point b)
{return a.x!=b.x?a.x<b.x:a.y<b.y;}
void init()
{
  scanf("%d",&n); m=1; 
  for(int i=1;i<=n;i++)
    scanf("%d%d",&dat[i].x,&dat[i].y);
  sort(dat+1,dat+1+n,cmp);   
  for(int i=1;i<=n;i++)
    if(dat[i]!=dat[m])
      dat[++m]=dat[i];
  n=m;m=0;
}
ll cross(point a,point b,point c)
{return ll(b.x-a.x)*(c.y-a.y)-ll(c.x-a.x)*(b.y-a.y);}
void calc()
{
  st[1]=1;st[2]=2;top=2;
  for(int i=3;i<=n;st[++top]=i++)
    for(;top>1&&cross(dat[st[top-1]],dat[st[top]],dat[i])>=0;top--);
  for(int i=1;i<=top;i++)
    hull[++m]=dat[st[i]];
  st[1]=n;st[2]=n-1;top=2;
  for(int i=n-2;i>0;st[++top]=i--)
    for(;top>1&&cross(dat[st[top-1]],dat[st[top]],dat[i])>=0;top--);
  for(int i=2;i<=top;i++)
    hull[++m]=dat[st[i]];
  ll ans=0;
  for(int i=1;i<m;i++)
    ans+=hull[i].x*hull[i+1].y-hull[i+1].x*hull[i].y;
  printf("%.1lf\n",double(abs(ans))/2);
}
int main()
{
  init();
  calc();                         
  return 0;
}
