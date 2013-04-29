#include <iostream>
#define maxl 1000
typedef struct lm
{
  int v[maxl],l;
  lm(){memset(v,0,sizeof(v));l=0;}
  lm(char *s)
    {
      memset(v,0,sizeof(v));
      l=0;
      int len=strlen(s);
      for(int i=len-1;i>=0;i--)
        v[++l]=s[i]-'0';
    }        
  void move()
    {
      while(v[l]==0&&l>0)
        l--;
      l++;  
      for(int i=l;i>1;i--)
        v[i]=v[i-1]; 
      v[1]=0;  
    }
  void out()
    {
      int i;
      printf("%d",v[l]);
      for(i=l-1;i>=1;i--)
        printf("%d",v[i]);
      printf("\n");     
    }  
};
lm a,b,c;
bool operator >=(lm a,lm b)
{
  if(a.l!=b.l)
    return a.l>b.l;
  int i;
  for(i=a.l;i>=1;i--)
    if(a.v[i]!=b.v[i])
      return a.v[i]>b.v[i];
  return 1;            
}
lm operator -(lm a,lm b)
{
  int i;
  for(i=1;i<=a.l;i++)
    {
      a.v[i]-=b.v[i];
      if(a.v[i]<0)
        {
          a.v[i]+=10;
          a.v[i+1]--;                 
        }
    }
  while(a.v[a.l]==0&&a.l>0)
    a.l--;
  return a;                
}
lm operator /(lm a,lm b)
{
  lm t,t1;
  for(int i=a.l;i>=1;i--)
    {
      t.move();
      t1.move();
      t1.v[1]=a.v[i];
      while(t1>=b)
        {
          t1=t1-b;
          t.v[1]++;          
        }      
    }            
  return t;
}
lm operator %(lm a,lm b)
{
  lm t1;
  for(int i=a.l;i>=1;i--)
    {
      t1.move();
      t1.v[1]=a.v[i];
      while(t1>=b)
       t1=t1-b;
    }            
  return t1;              
}
