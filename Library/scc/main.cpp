#include <iostream>
#include <cstring>
#define min(x, y) (((x) < (y)) ? (x) : (y))
using namespace std;
struct edge
{
    int x;
    int next;
};
edge map[10000];
int stack[1000];
int list[1000];
int dfn[1000], low[1000], belong[1000];
bool flag[1000];
int top;
int tot;
int Count;
int Time;
int n, m;
void insertedge(int x, int y)
{
    tot++;
    map[tot].x = y;
    map[tot].next = list[x];
    list[x] = tot;
}
void dfs(int x)
{
    cout << "Stack Push " << x << endl;
    top++;
    stack[top] = x;
    flag[x] = true;
    Time++;
    dfn[x] = Time;
    low[x] = Time;
    int i = list[x];
    while (i)
    {
        if (!dfn[map[i].x])
        {
            dfs(map[i].x);
            low[x] = min(low[x], low[map[i].x]);
        }
        else if (flag[map[i].x])
            low[x] = min(low[x], dfn[map[i].x]);
        i = map[i].next;
    }
    if (dfn[x] == low[x])
    {
        Count++;
        do
        {
            flag[stack[top]] = false;
            belong[stack[top]] = Count;
            top--;
        }
        while (stack[top + 1] != x);
    }
}
int main()
{
    cin >> n >> m;
    tot = 0;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        insertedge(x, y);
    }
    Time = 0;
    Count = 0;
    top = 0;
    memset(flag, false, sizeof(flag));
    for (int i = 1; i <= n; i++)
        if (!dfn[i])
        {
            cout << "Dfs " << i << endl;
            dfs(i);
        }
    for (int i = 1; i <= n; i++)
        cout << belong[i] << ' ';
    system("Pause");
    return 0;
}
