#include <iostream>
#include <cstring>
#include <limits>
#define maxint numeric_limits<int>::max()
using namespace std;
struct edge
{
    int x;
    int c;
    int next;
};
int n, m;
int s, t;
int k;
int dis[1000];
int list[1000];
bool visit[1000];
edge map[10000];
int l, r;
int tot;
int Count;
void insertedge(int x, int y, int c)
{
    tot++;
    map[tot].x = y;
    map[tot].c = c;
    map[tot].next = list[x];
    list[x] = tot;
}
void findpath(int x, int last)
{
    if (dis[x] > last)
        return ;
    if (x == t)
    {
        Count++;
        return ;
    }
    int i = list[x];
    while (i)
    {
        if (visit[map[i].x])
        {
            visit[map[i].x] = false;
            findpath(map[i].x, last - map[i].c);
            visit[map[i].x] = true;
            if (Count >= k)
                return ;
        }
        i = map[i].next;
    }
}
int main()
{
    cin >> k;
    cin >> n >> m;
    cin >> s >> t;
    tot = 0;
    for (int i = 1; i <= m; i++)
    {
        int x, y, c;
        cin >> x >> y >> c;
        insertedge(x, y, c);
        insertedge(y, x, c);
    }
    memset(visit, true, sizeof(visit));
    memset(dis, 0x7f, sizeof(dis));
    dis[t] = 0;
    for (int i = 1; i <= n - 1; i++)
    {
        int minp = 0;
        for (int j = 1; j <= n; j++)
            if ((visit[j]) && ((!minp) || (dis[j] < dis[minp])))
                minp = j;
        visit[minp] = false;
        int j = list[minp];
        while (j)
        {
            if (dis[minp] + map[j].c < dis[map[j].x])
                dis[map[j].x] = dis[minp] + map[j].c;
            j = map[j].next;
        }
    }
    Count = 0;
    memset(visit, true, sizeof(visit));
    findpath(s, maxint);
    if (Count < k)
    {
        cout << "No answer\n";
        system("Pause");
        return 0;
    }
    l = dis[t];
    r = maxint >> 1;
    while (l < r)
    {
        int mid = (l + r) >> 1;
        Count = 0;
        memset(visit, true, sizeof(visit));
        findpath(s, mid);
        cout << l << ' ' << r << ' ' << Count << endl;
        if (Count >= k)
            r = mid;
        else
            l = mid + 1;
    }
    cout << l << endl;
    system("Pause");
    return 0;
}
