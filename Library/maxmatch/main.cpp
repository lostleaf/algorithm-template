#include <iostream>
#include <cstring>
using namespace std;
struct edge
{
    int x;
    int next;
};
int n, m;
int list[1000];
int link[1000];
bool visit[1000];
edge map[10000];
int tot;
int sum;
void insertedge(int x, int y)
{
    tot++;
    map[tot].x = y;
    map[tot].next = list[x];
    list[x] = tot;
}
bool findpath(int x)
{
    int i = list[x];
    while (i)
    {
        if (!visit[map[i].x])
        {
            i = map[i].next;
            continue;
        }
        visit[map[i].x] = false;
        if ((link[map[i].x] == 0) || (findpath(link[map[i].x])))
        {
            link[map[i].x] = x;
            return true;
        }
        i = map[i].next;
    }
    return false;
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
    sum = 0;
    memset(link, 0, sizeof(link));
    for (int i = 1; i <= n; i++)
    {
        cout << i << endl;
        memset(visit, true, sizeof(visit));
        if (findpath(i))
            sum++;
        cout << i << endl;
    }
    cout << sum << endl;
    system("Pause");
    return 0;
}
