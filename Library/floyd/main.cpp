#include <iostream>
#include <limits>
#define maxint numeric_limits<int>::max()
using namespace std;
int map[100][100];
int n, m;
int source;
int main()
{
    cin >> n >> m;
    cin >> source;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            map[i][j] = maxint;
        map[i][i] = 0;
    }
    for (int i = 1; i <= m; i++)
    {
        int x, y, c;
        cin >> x >> y >> c;
        map[x][y] = c;
        map[y][x] = c;
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if ((map[i][k] != maxint) && (map[k][j] != maxint) &&
                    (map[i][k] + map[k][j] < map[i][j]))
                    map[i][j] = map[i][k] + map[k][j];
    for (int i = 1; i <= n; i++)
        cout << map[source][i] << ' ';
    system("Pause");
    return 0;
}
