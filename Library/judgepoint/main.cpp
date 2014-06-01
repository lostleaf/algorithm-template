#include <iostream>
#include <cmath>
using namespace std;
struct point
{
    double x, y;
};
point p1, p2;
point list[1000];
int n;
int tot;
const double limit = 1e-5;
bool fsame(double x, double y)
{
    if (fabs(x - y) < limit)
        return true;
    else
        return false;
}
double pmult(point p1, point p2, point p3)
{
    return (p2.x - p1.x) * (p3.y - p1.y) - (p3.x - p1.x) * (p2.y - p1.y);
}
bool check(point p1, point p2, point p3, point p4)
{
    return ((pmult(p1, p2, p3) * pmult(p1, p2, p4)) < 0) && ((pmult(p3, p4, p1) * pmult(p3, p4, p2)) < 0);
}
bool line(point p1, point p2, point p3)
{
    return ((!pmult(p1, p2, p3)) && ((p1.x - p2.x) * (p1.x - p3.x) < 0));
}
int main()
{
    cin >> n;
    cin >> p1.x >> p1.y;
    p2 = p1;
    for (int i = 1; i <= n; i++)
    {
        cin >> list[i].x >> list[i].y;
        if (list[i].x > p2.x)
            p2.x = list[i].x;
    }
    list[n + 1] = list[1];
    p2.x += 1;
    for (int i = 1; i <= n; i++)
        if (fsame(p1.x, list[i].x) && fsame(p1.y, list[i].y))
        {
            cout << "Vertex\n";
            system("Pause");
            return 0;
        }
    for (int i = 1; i <= n; i++)
        if (line(p1, list[i], list[i + 1]))
        {
            cout << "Side\n";
            system("Pause");
            return 0;
        }
    for (int i = 1; i <= n; i++)
        if (fsame(p1.x, list[i].x))
            p1.x += 1e-7;
    tot = 0;
    for (int i = 1; i <= n; i++)
        if (check(p1, p2, list[i], list[i + 1]))
            tot++;
    if (!(tot % 2))
        cout << "Outside\n";
    else
        cout << "Inside\n";
    system("Pause");
    return 0;
}
