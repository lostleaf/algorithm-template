#include <iostream>
#define maxn 205
int g[maxn][maxn],lx[maxn],ly[maxn],match[maxn],n;
bool usedx[maxn],usedy[maxn];
int find(int a)
{
   usedx[a]=1;
   int i;
   for(i=1;i<=n;i++)
     if(!usedy[i]&&g[a][i]==lx[a]+ly[i])
       {
         usedy[i]=1;
         if(!match[i]||find(match[i]))
           {
             match[i]=a;
             return 1;                           
           }                                 
       }   
   return 0;    
}
int perfectmatch()
{
  int i,j,k,delta;
  memset(match,0,sizeof(match));
  for(i=1;i<=n;i++)
    for(lx[i]=g[i][1],j=1;j<=n;j++)
      lx[i]>?=g[i][j];
  for(i=1;i<=n;i++)
    while(1)
      {
        memset(usedx,0,sizeof(usedx));
        memset(usedy,0,sizeof(usedy));
        if(find(i))break;
        delta=0x7fffffff;
        for(j=1;j<=n;j++)
          if(usedx[j])
            for(k=1;k<=n;k++)
              if(!usedy[k])
                delta<?=lx[j]+ly[k]-g[j][k];
        for(j=1;j<=n;j++)
          {
            if(usedx[j])lx[j]-=delta;
            if(usedy[j])ly[j]+=delta;
          }              
      }         
  int ans=0;
  for(i=1;i<=n;i++)
    ans+=g[match[i]][i];
  return ans;  
}
