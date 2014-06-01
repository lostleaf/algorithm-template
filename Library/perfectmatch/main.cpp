#include <iostream>
#include <cstring>
#include <limits>
#define maxint numeric_limits<int>::max();
using namespace std;
int map[1000][1000];
int lx[1000], ly[1000];
int slack[1000];
int link[1000];
bool visitx[1000], visity[1000];
int n;
int match;
bool findpath(int x)
{
    visitx[x] = true;
    for (int i = 1; i <= n; i++)
    {
        if (visity[i])
            continue;
        int delta = lx[x] + ly[i] - map[x][i];
        if (delta == 0)
        {
            visity[i] = true;
            if ((link[i] == 0) || (findpath(link[i])))
            {
                link[i] = x;
                return true;
            }
        }
        else if (slack[i] > delta)
            slack[i] = delta;
    }
    return false;
}
int main()
{
    cin >> n;
    memset(lx, 0, sizeof(lx));
    memset(ly, 0, sizeof(ly));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> map[i][j];
            if (map[i][j] > lx[i])
                lx[i] = map[i][j];
        }
    memset(link, 0, sizeof(link));
    for (int i = 1; i <= n; i++)
    {
        memset(slack, 0x7f, sizeof(slack));
        while (true)
        {
            memset(visitx, false, sizeof(visitx));
            memset(visity, false, sizeof(visity));
            if (findpath(i))
                break;
            int delta = maxint;
            for (int j = 1; j <= n; j++)
                if ((!visity[j]) && (slack[j] < delta))
                    delta = slack[j];
            for (int j = 1; j <= n; j++)
            {
                if (visitx[j])
                    lx[j] -= delta;
                if (visity[j])
                    ly[j] += delta;
                else
                    slack[j] -= delta;
            }
        }
    }
    match = 0;
    for (int i = 1; i <= n; i++)
        match += lx[i] + ly[i];
    cout << match << endl;
    system("Pause");
    return 0;
}
