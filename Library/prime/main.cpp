#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
int main()
{
    int n;
    int tot;
    bool flag[100];
    cin >> n;
    memset(flag, true, sizeof(flag));
    flag[1] = false;
    tot = 0;
    for (int i = 1; i <= n; i++)
        if (flag[i])
        {
            tot++;
            for (int j = 2; j <= n / i; j++)
                flag[i * j] = false;
        }
    cout << "Total Primes : " << tot << endl;
    for (int i = 1; i <= n; i++)
        if (flag[i])
            cout << i << ' ';
    system("Pause");
    return 0;
}
