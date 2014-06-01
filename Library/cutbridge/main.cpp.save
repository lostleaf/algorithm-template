#include <iostream>
#include <cstring>
#define min(x, y) (((x) < (y)) ? (x) : (y))
using namespace std;
struct edge
{
    int x;
    int next;
    bool bridge;
};
edge map[10000];
int list[1000];
int dfn[1000], low[1000];
bool cut[1000];
int tot;
int Time;
int root;
int n, m;
void insertedge(int x, int y)
{
    tot++;
    map[tot].x = y;
    map[tot].bridge = false;
    map[tot].next = list[x];
    list[x] = tot;
}
void dfs(int x, int father)
{
    int sum;
    Time++;
    dfn[x] = Time;
    low[x] = Time;
    int i = list[x];
    sum = 0;
    while (i)
    {
        if (map[i].x == father)
        {
            i = map[i].next;
            continue;
        }
        if (!dfn[map[i].x])
        {
            sum++;
            dfs(map[i].x, x);
            low[x] = min(low[x], low[map[i].x]);
            if (((x == root) && (sum > 1)) || ((x != root) && (dfn[x] <= low[map[i].x])))
                cut[x] = true;
            if (dfn[x] < low[map[i].x])
                map[i].bridge = true;
        }
        else if (dfn[map[i].x] < low[x])
            low[x] = dfn[map[i].x];
        i = map[i].next;
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
        insertedge(y, x);
    }
    Time = 0;
    memset(cut, false, sizeof(cut));
    for (int i = 1; i <= n; i++)
        if (!dfn[i])
        {
            root = i;
            dfs(i, 0);
        }
    cout << "Cut:\n";
    for (int i = 1; i <= n; i++)
        if (cut[i])
            cout << i << ' ';
    cout << endl;
    cout << "Bridge:\n";
    for (int i = 1; i <= n; i++)
    {
        int j = list[i];
        while (j)
        {
            if (map[j].bridge)
                cout << i << ' ' << map[j].x << endl;
            j = map[j].next;
        }
    }
    system("Pause");
    return 0;
}
