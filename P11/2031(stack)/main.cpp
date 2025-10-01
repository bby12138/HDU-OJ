#include <iostream>
#include <stdexcept>

using namespace std;

template<typename T>
class Stack
{
private:
    T *data;
    int size;
    int capacity;

    void resize();

public:
    Stack() : data(new T[10]), size(0), capacity(10) {}

    ~Stack();

    void push(T element);

    T pop();

    T top();

    int getSize();
};

template<typename T>
void Stack<T>::resize()
{
    if (size == capacity)
    {
        T newCapacity = capacity * 2;
        T *newData = new T[newCapacity];
        for (int i = 0; i < size; ++i)
            newData[i] = data[i];
        capacity = newCapacity;
        delete[] data;
        data = newData;
    }
}


template<typename T>
Stack<T>::~Stack()
{
    delete[]data;
}

template<typename T>
void Stack<T>::push(T element)
{
    if (size == capacity)
        resize();
    data[size++] = element;
}

template<typename T>
T Stack<T>::pop()
{
    if (size == 0)
        throw std::underflow_error("Stack is empty");
    return data[--size];
}

template<typename T>
T Stack<T>::top()
{
    if (size == 0)
        throw std::underflow_error("Stack is empty");
    return data[size - 1];
}

template<typename T>
int Stack<T>::getSize()
{
    return size;
}


int main()
{
    int n, r;
    while (cin >> n >> r)
    {
        if (n == 0)
            cout << 0 << endl;
        bool flag = false;
        if (n < 0)
        {
            n = -n;
            flag = true;
        }
        Stack<char> stk;
        while (n)
        {
            int remainder = n % r;
            char c = remainder < 10 ? remainder + '0' : remainder -10 + 'A';
            stk.push(c);
            n /= r;
        }
        if (flag)
            cout << '-';
        while (stk.getSize())
            cout << stk.pop();
        cout << endl;
    }
    return 0;
}
