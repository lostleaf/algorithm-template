#include <iostream>
#define maxn 2010
const int mod=2005;
const int inf=1000000000;
using namespace std;
typedef struct edge
{
  int to,flow,cost;
  edge *next,*op;
};
edge *vex[maxn],*pedg[maxn];
int pre[maxn],N,S,T,Flow,Cost,dis[maxn],dl[maxn];
bool inq[maxn];
void ins(int a,int b,int flow,int cost)
{
  edge *p1=new edge,*p2=new edge;
  p1->to=b;
  p1->flow=flow;
  p1->next=vex[a];
  p1->cost=cost;
  p1->op=p2;
  vex[a]=p1;
  p2->to=a;
  p2->flow=0;
  p2->next=vex[b];
  p2->cost=-cost;
  p2->op=p1;
  vex[b]=p2;     
}
bool spfa()
{
  for(int i=1;i<=T;i++)
    dis[i]=inf;
  memset(inq,0,sizeof(0));  
  dis[S]=0;inq[S]=1;dl[1]=S;
  int p1,p2;
  for(p1=1,p2=2;p1!=p2;inq[dl[p1]]=0,p1=p1%mod+1)
    for(edge *p=vex[dl[p1]];p;p=p->next)
      if(p->flow&&dis[p->to]>dis[dl[p1]]+p->cost)
        {
          dis[p->to]=dis[dl[p1]]+p->cost;
          pre[p->to]=dl[p1];
          pedg[p->to]=p;
          if(!inq[p->to])
            {
              dl[p2]=p->to;
              p2=p2%mod+1;
            }
          inq[p->to]=1;  
        }  
  return dis[T]<inf;
}
void augment()
{
  int aug=inf;
  for(int i=T;i!=S;i=pre[i])
    aug<?=pedg[i]->flow;
  Flow+=aug;  
  for(int i=T;i!=S;i=pre[i])
    {
      pedg[i]->flow-=aug;
      pedg[i]->op->flow+=aug;
      Cost+=pedg[i]->cost*aug;    
    }       
}
void costflow()
{
  while(spfa())
    augment();
  printf("%d\n",Cost);  
}
int main()
{}
