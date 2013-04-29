#include <iostream>
#include <map>
#define maxn 200010
using namespace std;
int sa[maxn],rank[maxn],height[maxn],n,dat[maxn],num[maxn];
int tx[maxn],ty[maxn];
void init()
{
  char *src=new char [maxn];
  gets(src+1);
  n=strlen(1+src);
  for(int i=1;i<=n;i++)
    dat[i]=src[i]-'a'+1;
  delete []src;
}
void calcsa()
{
  int i,l,p,*x=tx,*y=ty;
  for(i=1;i<=n;i++)
    x[i]=dat[i],num[dat[i]]++;
  for(i=1;i<=26;i++)
    num[i]+=num[i-1];
  for(i=n;i>0;i--)
    sa[num[x[i]]--]=i;
  swap(x,y);
  for(i=1;i<=n;i++)
    x[sa[i]]=x[sa[i-1]]+int(y[sa[i]]!=y[sa[i-1]]);
  for(l=1;l<n;l<<=1)
    {
      for(p=0,i=n;i+l>n;i--)
        y[++p]=i;
      for(i=1;i<=n;i++)
        if(sa[i]>l)
          y[++p]=sa[i]-l;
      for(memset(num,0,sizeof(num)),i=1;i<=n;i++)
        num[x[i]]++;
      for(i=1;i<=n;i++)
        num[i]+=num[i-1];
      for(i=n;i>=1;i--)
        sa[num[x[y[i]]]--]=y[i];
      swap(x,y);
      for(i=2,x[sa[1]]=1;i<=n;i++)
        {
          x[sa[i]]=x[sa[i-1]];
          if(y[sa[i]]!=y[sa[i-1]]||y[sa[i]+l]!=y[sa[i-1]+l])
            x[sa[i]]++;
        }
    }
  for(i=1;i<=n;i++)rank[sa[i]]=i;
}
void calcheight()
{
  int i,l,j;
  for(i=1,l=0;i<=n;i++)
    {
      if(l>0)l--;
      for(j=sa[rank[i]-1];dat[i+l]==dat[j+l];l++);
      height[rank[i]]=l;                
    }     
}
void calc()
{
  calcsa();
  calcheight();
}
int main()
{
  init();
  calc();
  return 0;    
}
