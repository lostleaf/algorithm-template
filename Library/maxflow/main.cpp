#include <iostream>
#include <cstring>
#include <limits>
#define maxint numeric_limits<int>::max()
using namespace std;
struct edge
{
    int x;
    int next;
    int c;
};
int n, m;
int head, tail;
int source, target;
int maxflow;
int review;
int tot;
int list[1000];
int mat[1000];
int prev[1000];
int queue[1000];
edge map[10000];
void insertedge(int x, int y, int c)
{
    tot++;
    map[tot].x = y;
    map[tot].c = c;
    map[tot].next = list[x];
    list[x] = tot;
}
bool findpath()
{
    memset(queue, 0, sizeof(queue));
    head = 1;
    tail = 1;
    queue[head] = source;
    memset(mat, 0, sizeof(mat));
    mat[0] = maxint;
    mat[queue[head]] = 1;
    review = 0;
    while (head <= tail)
    {
        int i = list[queue[head]];
        while (i)
        {
            if ((map[i].c) && (!mat[map[i].x]))
            {
                mat[map[i].x] = mat[queue[head]] + 1;
                tail++;
                queue[tail] = map[i].x;
            }
            i = map[i].next;
        }
        head++;
        if (mat[target])
            return true;
    }
    return false;
}
void updataflow()
{
    int max = maxint;
    int i = target;
    while (i != source)
    {
        if (map[prev[i]].c < max)
            max = map[prev[i]].c;
        i = map[prev[i] ^ 1].x;
    }
    maxflow += max;
    i = target;
    while (i != source)
    {
        map[prev[i]].c -= max;
        map[prev[i] ^ 1].c += max;
        if (!map[prev[i]].c)
            review = map[prev[i] ^ 1].x;
        i = map[prev[i] ^ 1].x;
    }
}
void dicnic(int x)
{
    if (x == target)
    {
        updataflow();
        return ;
    }
    int i = list[x];
    while (i)
    {
        if ((mat[map[i].x] == mat[x] + 1) && (map[i].c))
        {
            prev[map[i].x] = i;
            dicnic(map[i].x);
            if (mat[x] > mat[review])
                return ;
            review = 0;
        }
        i = map[i].next;
    }
    mat[x] = 0;
}
int main()
{
    cin >> n >> m;
    cin >> source >> target;
    tot = 1;
    for (int i = 1; i <= m; i++)
    {
        int x, y, c;
        cin >> x >> y >> c;
        insertedge(x, y, c);
        insertedge(y, x, 0);
    }
    maxflow = 0;
    while (findpath())
        dicnic(source);
    cout << maxflow << endl;
    system("Pause");
    return 0;
}
