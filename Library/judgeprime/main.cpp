#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int main()
{
    int x;
    const int limit = 100;
    cin >> x;
    srand(time(NULL));
    for (int i = 1; i <= limit; i++)
    {
        int mult, tmp;
        int mod;
        int j;
        mod = rand() % (x - 2) + 2;
        mult = 1;
        tmp = x % mod;
        j = mod - 1;
        while (j)
        {
            if (j % 2)
            {
                mult *= tmp;
                mult %= mod;
            }
            tmp *= tmp;
            tmp %= mod;
            j = j >> 1;
        }
        if (mult != 1)
        {
            cout << "Not Prime\n";
            system("Pause");
            return 0;
        }
    }
    cout << "Is Prime\n";
    system("Pause");
    return 0;
}
