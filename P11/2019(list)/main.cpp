#include <iostream>
#include <stdexcept>
typedef int eleType;
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
    int n, m;
    while (cin >> n >> m && (n || m))
    {
        LinkedList lst;
        for (int i = 0; i < n; ++i)
        {
            int a;
            cin >> a;
            lst.insert(i, a);
        }
        bool flag = false;
        for (int i = 0; i < n; ++i)
        {
            if (lst.get(i)->data >= m)
            {
                flag = true;
                lst.insert(i, m);
                break;
            }
        }

        if (!flag)
            lst.insert(n, m);

        lst.print();
    }
    return 0;
}
