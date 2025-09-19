/*
HDU OJ 2055
we define f(A) = 1, f(a) = -1, f(B) = 2, f(b) = -2, ... f(Z) = 26, f(z) = -26;
Give you a letter x and a number y , you should output the result of y+f(x).
*/
#include <iostream>
#include <cctype>
using namespace std;

int calc(char x, int y)
{
    if (isupper(x))
    {
        y += 1 + x - 'A';
    }
    if (islower(x))
    {
        y -=1 + x - 'a';
    }
    return y;
}

int main()
{
    char x;
    int n, y;
    while (cin >> n && n)
    {
        while (n--)
        {
            cin >> x >> y;
            cout << calc(x, y) << endl;
        }
    }

    return 0;
}
