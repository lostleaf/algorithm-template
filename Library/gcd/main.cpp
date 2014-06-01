#include <iostream>
using namespace std;
int gcd(int x, int y)
{
    if (!y)
        return x;
    return gcd(y, x % y);
}
int main()
{
    int x, y;
    int d;
    cin >> x >> y;
    d = gcd(x, y);
    cout << d << endl;
    system("Pause");
    return 0;
}
