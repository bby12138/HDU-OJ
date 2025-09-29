#include <iostream>
#include <stdexcept>
typedef long long eleType;
using namespace std;

struct ListNode
{
    eleType data;
    ListNode *next;

    ListNode(eleType x) : data(x), next(NULL) {}
};

class LinkedList
{
private:
    ListNode *head;
    int size;

public:
    LinkedList() : size(0), head(NULL) {}

    ~LinkedList();

    void insert(int i, eleType value);

    void remove(int i);

    ListNode *find(eleType value);

    ListNode *get(int i);

    void update(int i, eleType value);

    void print();

    int Size()
    {
        return size;
    }
};

LinkedList::~LinkedList()
{
    ListNode *curr = head;
    while (curr != NULL)
    {
        ListNode *temp = curr;
        curr = temp->next;
        delete temp;
    }
}

void LinkedList::insert(int i, eleType value)
{
    if (i < 0 || i > size)
        throw std::out_of_range("Invalid position");
    ListNode *newNode = new ListNode(value);
    if (i == 0)
    {
        newNode->next = head;
        head = newNode;
    } else
    {
        ListNode *curr = head;
        for (int j = 0; j < i - 1; ++j)
            curr = curr->next;

        newNode->next = curr->next;
        curr->next = newNode;
    }
    ++size;
}

void LinkedList::remove(int i)
{
    if (i < 0 || i >= size)
        throw std::out_of_range("Invalid position");

    if (i == 0)
    {
        ListNode *temp = head;
        head = temp->next;
        delete temp;
    } else
    {
        ListNode *curr = head;
        for (int j = 0; j < i - 1; ++j)
            curr = curr->next;
        ListNode *temp = curr->next;
        curr->next = temp->next;
        delete temp;
    }
    --size;
}

ListNode *LinkedList::find(eleType value)
{
    ListNode *curr = head;
    while (curr && curr->data != value)
        curr = curr->next;

    return curr;
}

ListNode *LinkedList::get(int i)
{
    if (i < 0 || i >= size)
        throw std::out_of_range("Invalid position");

    ListNode *curr = head;
    for (int j = 0; j < i; ++j)
        curr = curr->next;

    return curr;
}

void LinkedList::update(int i, eleType value)
{
    get(i)->data = value;
}

void LinkedList::print()
{
    ListNode *curr = head;
    while (curr != NULL)
    {
        cout << curr->data << ' ';
        curr = curr->next;
    }
    cout << endl;
}


int main()
{
    LinkedList f;
    f.insert(0, 1);
    f.insert(1, 1);
    f.insert(2, 1);
    for (int i = 3; i <= 42; ++i)
    {
        int a = f.get(i - 1)->data;
        int b = f.get(i - 2)->data;
        f.insert(i, a + b);
    }

    // f.print();
    f.update(1, 0);
    int n;
    while (cin >> n)
    {
        while (n--)
        {
            int x;
            cin >> x;
            cout << f.get(x)->data << endl;
        }
    }

    return 0;
}
