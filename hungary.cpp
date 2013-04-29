#include <iostream>
#define maxn 110
typedef struct edge 
{
  int to;
  edge *next;        
};
edge *link[maxn];
int n,m,match[maxn];
bool used[maxn];
void ins(int a,int b)
{
  edge *p=new edge;
  p->to=b;
  p->next=link[a];
  link[a]=p;
}
int find(int a)
{
  for(edge *p=link[a];p;p=p->next)
      if(!used[p->to])
        {
          used[p->to]=1;
          if(!match[p->to]||find(match[p->to]))
            {
              match[p->to]=a;
              return 1;
            }
        }
  return 0;
}
void calc()
{
  int ans=0,i;
  for(i=1;i<=n;i++)
    {
      memset(used,0,sizeof(used));
      ans+=find(i);
    }
  printf("%d\n",ans);
}
int main()
{

}
