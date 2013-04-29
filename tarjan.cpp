void tar(int u)
{
  dfn[u]=low[u]=++tid;
  inst[u]=1;st[++top]=u;
  for(edge *p=vex[u];p;p=p->next)
    if(!dfn[p->to])
      tar(p->to),low[u]=min(low[u],low[p->to]);             
    else
      if(inst[p->to])
        low[u]=min(low[u],dfn[p->to]);
  if(low[u]==dfn[u])
      for(++tot;st[top+1]!=u;num[tot]++,top--)
        belong[st[top]]=tot,inst[st[top]]=0;
}
