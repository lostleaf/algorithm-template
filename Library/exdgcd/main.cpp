#include <iostream>
using namespace std;
int exd_gcd(int x, int y, int &x0, int &y0)
{
    int tmp;
    int gcd;
    if (y == 0)
    {
        x0 = 1;
        y0 = 0;
        return x;
    }
    gcd = exd_gcd(y, x % y, x0, y0);
    tmp = x0;
    x0 = y0;
    y0 = tmp - x / y * y0;
    return gcd;
}
int main()
{
    int x, y, c;
    int x0, y0;
    int d;
    cin >> x >> y >> c;
    d = exd_gcd(x, y, x0, y0);
    if (c % d != 0)
        cout << "No Solution!";
    else
        cout << x0 * c / d << ' ' << y0 * c / d << endl;
    system("Pause");
    return 0 ;
}
