#include <iostream>
#include <string>
#include <cstring>
using namespace std;
void exdkmp(string s, string t, int ls, int lt, int *exd)
{
    int next[1000];
    int a, p;
    int l;
    memset(next, 0, sizeof(next));
    next[1] = lt;
    a = 0;
    p = 0;
    for (int i = 2; i <= lt; i++)
    {
        l = next[i - a + 1];
        if (i + l - 1 > p)
            l = p - i + 1;
        if (l < 0)
            l = 0;
        while ((l + i <= lt) && (t[l + 1] == t[i + l]))
            l++;
        next[i] = l;
        if (i + l - 1 > p)
        {
            a = i;
            p = i + l - 1;
        }
    }
    memset(exd, 0, sizeof(exd));
    a = 0;
    p = 0;
    for (int i = 1; i <= ls; i++)
    {
        l = next[i - a + 1];
        if (i + l - 1 > p)
            l = p - i + 1;
        if (l < 0)
            l = 0;
        while ((l + i <= ls) && (l + 1 <= lt) && (t[l + 1] == s[i + l]))
            l++;
        exd[i] = l;
        if (i + l - 1 > p)
        {
            a = i;
            p = i + l - 1;
        }
    }
}
int main()
{
    string s, t;
    int ls, lt;
    int extend[1000];
    cin >> s;
    cin >> t;
    ls = s.size();
    lt = t.size();
    exdkmp(s, t, ls, lt, extend);
    for (int i = 1; i <= ls; i++)
        cout << extend[i] << ' ';
    return 0;
}
