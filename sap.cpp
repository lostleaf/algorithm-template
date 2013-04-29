#include <iostream>
#define maxn 1010
#define maxm 100100
#define link lnk
const int inf=1000000000;
typedef struct nedge
{
  int to,next,flow;        
};
nedge edge[maxm];
int m,n,src,trs,top;
int num[maxn],d[maxn],link[maxn],now[maxn],his[maxn],pre[maxn],tot;
void ins(int a,int b,int v)
{
  edge[++top].to=b;
  edge[top].flow=v;
  edge[top].next=link[a];
  link[a]=top;
  edge[++top].to=a;
  edge[top].flow=0;
  edge[top].next=link[b];
  link[b]=top;     
}
void calc()
{
  int ans=0,aug=0x7fffffff,cur=src,p,p1,t;
  bool flag;
 while(d[src]<trs)
    {
      flag=0;
      his[cur]=aug;
      for(p=now[cur];p;p=edge[p].next)
        if(edge[p].flow>0&&d[cur]==d[edge[p].to]+1)
          {
            flag=1;now[cur]=p;
            aug<?=edge[p].flow;
            pre[edge[p].to]=cur;cur=edge[p].to;
            if(cur==trs)
              {
                ans+=aug;
                while(cur!=src)
                  {
                    cur=pre[cur];
                    edge[now[cur]].flow-=aug;
                    edge[now[cur]+(now[cur]&1?1:-1)].flow+=aug;
                  }
                aug=inf;            
              }                            
            break;
          }               
       if(flag) continue;
       for(t=trs,p=link[cur];p;p=edge[p].next)
         if(d[edge[p].to]<t&&edge[p].flow>0) 
           {t=d[edge[p].to];p1=p;}
       now[cur]=p1;
       num[d[cur]]--;
       if(num[d[cur]]==0) break;
       d[cur]=t+1;num[d[cur]]++;
       if(cur==src) continue;
       cur=pre[cur];aug=his[cur];   
    }     
  printf("%d\n",ans);
}  
int main()
{   
}
