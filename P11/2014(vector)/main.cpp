#include <iostream>
#include <iomanip>
#define eleType double
using namespace std;

struct SequentialList
{
    eleType *elements;
    int size;
    int capacity;
};

void initializeList(SequentialList *list, int capacity)
{
    list->elements = new eleType[capacity];
    list->capacity = capacity;
    list->size = 0;
}

void destroyList(SequentialList *list)
{
    delete[] list->elements;
}

int size(SequentialList *list)
{
    return list->size;
}

bool isEmpty(SequentialList *list)
{
    return list->size == 0;
}

void insert(SequentialList *list, int index, eleType element)
{
    if (index < 0 || index > list->size)
    {
        throw std::invalid_argument("Invalid index");
    }
    if (list->size == list->capacity)
    {
        int newCapacity = list->capacity * 2;
        eleType *newElements = new eleType[newCapacity];
        for (int i = 0; i < list->size; ++i)
        {
            newElements[i] = list->elements[i];
        }
        delete[] list->elements;
        list->elements = newElements;
        list->capacity = newCapacity;
    }
    for (int i = list->size; i > index; --i)
    {
        list->elements[i] = list->elements[i - 1];
    }
    list->elements[index] = element;
    list->size++;
}

void deleteElement(SequentialList *list, int index)
{
    if (index < 0 || index >= list->size)
    {
        throw std::invalid_argument("Invalid index");
    }

    for (int i = index; i < list->size - 1; ++i)
    {
        list->elements[i] = list->elements[i + 1];
    }
    list->size--;
}

int findElement(SequentialList *list, eleType element)
{
    for (int i = 0; i < list->size; ++i)
    {
        if (list->elements[i] == element)
        {
            return i;
        }
    }

    return -1;
}

eleType getElement(SequentialList *list, int index)
{
    if (index < 0 || index >= list->size)
    {
        throw std::invalid_argument("Invalid index");
    }

    return list->elements[index];
}

void updateElement(SequentialList *list, int index, eleType element)
{
    if (index < 0 || index >= list->size)
    {
        throw std::invalid_argument("Invalid index");
    }

    list->elements[index] = element;
}

int main()
{
    int n;
    while (cin >> n && n)
    {
        SequentialList s{};
        initializeList(&s, 1);
        eleType a;
        for (int i = 0; i < n; ++i)
        {
            cin >> a;
            insert(&s, i, a);
        }

        eleType eMax = getElement(&s, 0), eMin = getElement(&s, 0);
        eleType sum = 0;
        for (int i = 0; i < size(&s); ++i)
        {
            eleType ele = getElement(&s, i);
            if (eMax < ele)
            {
                eMax = ele;
            }
            if (eMin > ele)
            {
                eMin = ele;
            }
            sum += ele;
        }
        sum -= eMax;
        sum -= eMin;

        sum /= (n - 2);
        cout << fixed << setprecision(2) << sum << endl;

        destroyList(&s);
    }

    return 0;
}
