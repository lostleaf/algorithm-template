#include <iostream>
#define maxn 1010
#define white 0
#define grey 1
#define black 2
typedef struct edge
{
  int to;
  edge *next;
};
edge *vex[maxn];
int n,m,dfn[maxn],low[maxn],tid;
void ins(int a,int b)
{
  edge *p=new edge;
  p->to=b;
  p->next=vex[a];
  vex[a]=p;     
}
void init()
{
  freopen("bridge.in","r",stdin);
  freopen("bridge2.out","w",stdout);
  scanf("%d%d",&n,&m);
  int i,a,b;
  for(i=1;i<=m;i++)
    {
      scanf("%d%d",&a,&b);
      ins(a,b);ins(b,a);               
    }
}
void dfs(int u,int p)
{
  dfn[u]=low[u]=++tid;
  for(edge *i=vex[u];i;i=i->next)
    if(!dfn[i->to])
      {
        dfs(i->to,u);
        low[u]<?=low[i->to];
        if(dfn[u]<low[i->to])
          printf("%d %d\n",u,i->to);
      }
    else
      if(i->to!=p)
        low[u]<?=dfn[i->to];
}
void calc()
{
  int i;
  for(i=1;i<=n;i++)
    if(!dfn[i])
      dfs(i,0);
}
int main()
{
  init();
  calc();
  return 0;    
}
