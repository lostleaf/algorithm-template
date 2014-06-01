#include <iostream>
#include <algorithm>
using namespace std;
struct edge
{
    int x, y, c;
};
int n, m;
int tot, calc;
int father[1000];
edge map[10000];
int find(int x)
{
    if (father[x] == x)
        return x;
    int fa = find(father[x]);
    father[x] = fa;
    return fa;
}
int compare(const edge x, const edge y)
{
    if (x.c < y.x)
        return 0;
    else
        return 1;
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
        cin >> map[i].x >> map[i].y >> map[i].c;
    sort(map, map + m, compare);
    for (int i = 1; i <= n; i++)
        father[i] = i;
    tot = 0;
    calc = 0;
    for (int i = 1; i <= m; i++)
    {
        int fa1 = find(map[i].x);
        int fa2 = find(map[i].y);
        if (fa1 != fa2)
        {
            father[fa1] = fa2;
            tot++;
            calc += map[i].c;
        }
        if (tot == n - 1)
        {
            break;
        }
    }
    if (tot != n - 1)
    {
        cout << "Wrong!\n";
        system("Pause");
        return 0;
    }
    cout << calc;
    system("Pause");
    return 0 ;
}
