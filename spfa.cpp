#include <iostream>
#include <deque>
#define maxn 25100
using namespace std;
const int inf=1000000000;
deque<int> Q;
int n,m,start,dis[maxn],inq[maxn];
typedef struct edge 
{
  int to,v;
  edge *next;
};
edge *vex[maxn];
void ins(int a,int b,int v)
{
  edge *p=new edge;
  p->to=b;
  p->v=v;
  p->next=vex[a];
  vex[a]=p;
}
void spfa(int s)
{
  for(int i=1;i<=n;i++)dis[i]=inf;
  dis[s]=0;inq[s]=1;
  for(Q.push_back(s);!Q.empty();inq[Q.front()]=0,Q.pop_front())
    for(edge *p=vex[Q.front()];p;p=p->next)
      if(dis[Q.front()]+p->v<dis[p->to])
        {
          dis[p->to]=dis[Q.front()]+p->v;
          if(!inq[p->to])
            Q.push_back(p->to);
          inq[p->to]=1;
        }
}
