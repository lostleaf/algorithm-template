#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int n;
int list[1000];
void sort(int l, int r)
{
    int i, j;
    int tmp, mid;
    i = l;
    j = r;
    mid = list[l + rand() % (r - l + 1)];
    do
    {
        while (list[i] < mid)
            i++;
        while (list[j] > mid)
            j--;
        if (i <= j)
        {
            tmp = list[i];
            list[i] = list[j];
            list[j] = tmp;
            i++;
            j--;
        }
    }
    while (i <= j);
    if (i < r)
        sort(i, r);
    if (j > l)
        sort(l, j);
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> list[i];
    srand(time(NULL));
    sort(1, n);
    for (int i = 1; i <= n; i++)
        cout << list[i] << ' ';
    cout << endl;
    system("Pause");
    return 0;
}
