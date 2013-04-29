#include <iostream>
#define maxn 10000005
char s1[maxn],s2[maxn];
int pre[maxn],n,m;
void init()
{
  gets(s1+1);
  gets(s2+1);
  n=strlen(s1+1);
  m=strlen(s2+1);     
}
void calc()
{  
  int i,j;
  for(i=2;i<=m;pre[i++]=j+1)
    for(j=pre[i-1];j>0&&s2[j]!=s2[i-1];j=pre[j]);
  for(i=0,j=0;j<=m&&i<=n;i++,j++)
    for(;j>0&&s1[i]!=s2[j];j=pre[j]);
  if(j>m)
    printf("%d",i-m);
  else
    printf("Cannot find!");
}
int main()
{
  init();
  calc();
  return 0;    
}
