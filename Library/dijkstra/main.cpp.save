#include <iostream>
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
edge map[10000];
int dis[1000];
int list[1000];
bool visit[1000];
int total;
int source;
int minp;
void insertedge(int x, int y, int c)
{
    total++;
    map[total].x = y;
    map[total].c = c;
    map[total].next = list[x];
    list[x] = total;
}
int main()
{
    cin >> n >> m;
    cin >> source;
    total = 0;
    for (int i = 1; i <= m; i++)
    {
        int x, y, c;
        cin >> x >> y >> c;
        insertedge(x, y, c);
        insertedge(y, x, c);
    }
    for (int i = 1; i <= n; i++)
    {
        dis[i] = maxint;
        visit[i] = true;
    }
    dis[source] = 0;
    for (int i = 1; i <= n; i++)
    {
        minp = 0;
        for (int j = 1; j <= n; j++)
        {
            if ((visit[j]) && ((minp == 0) || (dis[minp] > dis[j])))
                minp = j;
        }
        visit[minp] = false;
        int j = list[minp];
        while (j)
        {
            if (dis[minp] + map[j].c < dis[map[j].x])
                dis[map[j].x] = dis[minp] + map[j].c;
            j = map[j].next;
        }
    }
    for (int i = 1; i <= n; i++)
        cout << dis[i] << ' ';
    system("Pause");
    return 0;
}
