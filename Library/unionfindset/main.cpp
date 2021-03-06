#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int father[1000];
int c, x, y;
int n;
int fa1, fa2;
int find(int x)
{
    if (father[x] == x)
        return x;
    father[x] = find(father[x]);
    return father[x];
}
int main()
{
    srand(time(NULL));
    cin >> n;
    for (int i = 1; i <= n; i++)
        father[i] = i;
    while (cin >> c, c)
    {
        switch (c)
        {
            case 1:
                cin >> x >> y;
                fa1 = find(x);
                fa2 = find(y);
                if (rand() % 2)
                    father[fa1] = fa2;
                else
                    father[fa2] = fa1;
                break;
            case 2:
                cin >> x >> y;
                fa1 = find(x);
                fa2 = find(y);
                if (x == y)
                    cout << "In the same set\n";
                else
                    cout << "Not in the same set\n";
                break;
            default:
                cout << "Wrong Input\n";
        }
    }
    system("Pause");
    return 0;
}
