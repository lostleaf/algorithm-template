#include <cmath>
#include <iostream>
using namespace std;
#define maxl 110
const int mi[4]={1,10,100,1000};
typedef struct lm
{
  int v[maxl],l;  
  lm()
  {memset(v,0,sizeof(v));l=0;}      
  lm(char *s)
    {
      int i,len=strlen(s),cnt=0;
      memset(v,0,sizeof(v));
      l=1;
      for(i=len-1;i>=0;i--)
        {
          v[l]+=(s[i]-'0')*mi[cnt];
          cnt++;
          if(cnt==4)
            {
              l++;
              cnt=0;        
            }                   
        }
      if(v[l]==0) l--;  
    }
   lm(int a)
     {
       memset(v,0,sizeof(v));
       for(l=0;a;a/=10000)
         v[++l]=a%10000;
     }
   void out()
     {
       int i;
       printf("%d",v[l]);
       for(i=l-1;i>=1;i--)
         printf("%04d",v[i]);
       printf("\n");   
     }
};
lm operator +(lm a,lm b)
{
  int i,l=max(a.l,b.l);
  for(i=1;i<=l;i++)
    {
      a.v[i]+=b.v[i];
      a.v[i+1]+=a.v[i]/10000;
      a.v[i]%=10000;               
    }
  a.l=l;  
  if(a.v[l+1]>0)
    a.l++;  
  return a;               
}
bool operator >(lm a,lm b)
{
  if(a.l!=b.l)
    return a.l>b.l;
  int i;
  for(i=a.l;i>=1;i--)
    if(a.v[i]!=b.v[i])
      return a.v[i]>b.v[i];
  return 0;           
}
lm operator -(lm a,lm b)
{
  int i,f=0;
  if(b.l==0)
    return a;
  for(i=1;i<=a.l;i++)
    {
      a.v[i]-=b.v[i];
      if(a.v[i]<0)
        {
          a.v[i]+=10000;                 
          a.v[i+1]--;
        }
    }
  while(a.v[a.l]==0&&a.l>0) 
    a.l--;
  return a;               
}
lm operator *(lm a,lm b)
{
  lm t;
  int i,j;
  if(a.l==0||b.l==0)
    return t;
  for(j=1;j<=b.l;j++)
    for(i=1;i<=a.l;i++)
      {
        t.v[i+j-1]+=a.v[i]*b.v[j];
        t.v[i+j]+=t.v[i+j-1]/10000;
        t.v[i+j-1]%=10000;                 
      }
  t.l=a.l+b.l-1;    
  if(t.v[t.l+1]>0)
    t.l++;
  return t;                
}
lm operator /(lm a,int b)
{
  int i;
  long long t1=0;
  lm t;
  for(i=a.l;i>=1;i--)
    {
      t1=t1*10000+a.v[i];
      t.v[i]=t1/b;
      t1%=b;
    }
  t.l=a.l;
  while(t.v[t.l]==0&&t.l>0)
    t.l--;
  return t;                
}
int operator %(lm a,int b)
{
  int i;
  long long t1=0;
  for(i=a.l;i>=1;i--)
      t1=(t1*10000+a.v[i])%b;                 
  return int(t1);
}
