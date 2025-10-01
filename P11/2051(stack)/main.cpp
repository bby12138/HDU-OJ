#include <iostream>
#include <stdexcept>
using namespace std;

template<typename T>
class Stack
{
private:
    struct Node
    {
        T data;
        Node *next;
        Node(T x) : data(x), next(nullptr) {}
    };

    int size;
    Node *head;

public:
    Stack() : size(0), head(nullptr) {}

    ~Stack();

    void push(T element);

    T pop();

    T top() const;

    int getSize() const;
};

template<typename T>
Stack<T>::~Stack()
{
    while (head)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}

template<typename T>
void Stack<T>::push(T element)
{
    Node *newHead = new Node(element);
    newHead->next = head;
    head = newHead;
    ++size;
}

template<typename T>
T Stack<T>::pop()
{
    if (size == 0)
        throw std::underflow_error("Stack is empty");
    T result = head->data;
    Node *temp = head;
    head = head->next;
    delete temp;
    --size;
    return result;
}

template<typename T>
T Stack<T>::top() const
{
    if (size == 0)
        throw std::underflow_error("Stack is empty");
    return head->data;
}

template<typename T>
int Stack<T>::getSize() const
{
    return size;
}



int main()
{
    int n;
    while (cin >> n)
    {
        Stack<int> stk;
        if (n == 0)
        {
            cout << 0 << endl;
        }
        while (n)
        {
            stk.push(n%2);
            n /= 2;
        }
        while (stk.getSize())
        {
            cout << stk.pop();
        }
        cout << endl;
    }
    return 0;
}
