void lr(int &r)
{
  int t;
  t=tree[r].r;
  tree[r].r=tree[t].l;
  tree[t].l=r;
  tree[t].size=tree[r].size;
  tree[r].size=tree[tree[r].l].size+tree[tree[r].r].size+1;
  r=t;     
}
void rr(int &r)
{
  int t;
  t=tree[r].l;
  tree[r].l=tree[t].r;
  tree[t].r=r;
  tree[t].size=tree[r].size;
  tree[r].size=tree[tree[r].l].size+tree[tree[r].r].size+1;
  r=t;
}
void ins(int &r,info v)
{
  if(r==0)
    {
      r=++cnt;
      tree[r].v=v;
      tree[r].size=1;
      tree[r].p=rand();
      return;
    }     
  tree[r].size++;
  if(v<tree[r].v)
    {
      ins(tree[r].l,v);
      if(tree[tree[r].l].p>tree[r].p)
        rr(r);
    }
  else
    {
      ins(tree[r].r,v);
      if(tree[tree[r].r].p>tree[r].p)
        lr(r);
    }
}
void del(int &r,info v)
{
  if(v==tree[r].v)
    {
      tree[r].p=-1;
      if(!tree[r].l||!tree[r].r){r=tree[r].r+tree[r].l;return;}
      if(tree[tree[r].l].p>tree[tree[r].r].p)
        rr(r);
      else
        lr(r);
    }
  tree[r].size--;
  if(v<tree[r].v)
    del(tree[r].l,v);
  else
    del(tree[r].r,v);
}
int findkth(int r,int k)
{
  if(r==0)return 0;
  if(k<=tree[tree[r].l].size)return findkth(tree[r].l,k);
  if(k==tree[tree[r].l].size+1)return r;
  return findkth(tree[r].r,k-tree[tree[r].l].size-1);
}
int getrank(int r,info v)
{
  if(r==0)return 0;
  if(v<tree[r].v)return getrank(tree[r].l,v);
  if(v==tree[r].v)return tree[tree[r].l].size+1;
  return tree[tree[r].l].size+1+getrank(tree[r].r,v);
}
