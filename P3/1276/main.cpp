/*
HDU OJ 1276
 */
#include <iostream>
#include <queue>

using namespace std;

queue<int> function2(queue<int> &q)
{
    queue<int> qAns;
    int size = q.size();
    for (int i = 0; i < size; ++i)
    {
        if (i & 1)
            q.pop();
        else
        {
            qAns.push(q.front());
            q.pop();
        }
    }

    return qAns;
}

queue<int> function3(queue<int> &q)
{
    queue<int> qAns;
    int size = q.size();
    for (int i = 0; i < size; ++i)
    {
        if ((i + 1) % 3 == 0)
            q.pop();
        else
        {
            qAns.push(q.front());
            q.pop();
        }
    }

    return qAns;
}

void printQueue(queue<int> q)
{
    int size = q.size();
    for (int i = 0; i < size; ++i)
    {
        cout << q.front() << ' ';
        q.pop();
    }
    cout << endl;
}

int main()
{
    int n;
    while (cin >> n && n)
    {
        while (n--)
        {
            queue<int> q;
            int num;
            cin >> num;
            for (int i = 1; i <= num; ++i) q.push(i);
            queue<int> current = q;
            while (current.size() > 3)
            {
                current = function2(current);
                if (current.size() <= 3) break;
                current = function3(current);
            }
            printQueue(current);
        }
    }

    return 0;
}
