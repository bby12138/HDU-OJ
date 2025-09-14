/*
HDU OJ 2033
人见人爱A+B
HDOJ上面已经有10来道A+B的题目了，相信这些题目曾经是大家的最爱，
希望今天的这个A+B能给大家带来好运，也希望这个题目能唤起大家对ACM曾经的热爱。
 */
#include <iostream>
using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        int h, m, s;
        int h1, m1, s1;
        while (n--)
        {
            cin >> h >> m >> s;
            cin >> h1 >> m1 >> s1;
            s += s1;

            m += m1 + s / 60;
            s %= 60;

            h += h1 + m / 60;
            m %= 60;


            cout << h << ' ' << m << ' ' << s << endl;
        }
    }
    return 0;
}
