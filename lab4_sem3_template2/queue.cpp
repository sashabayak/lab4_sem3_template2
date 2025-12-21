#include <iostream>
#include "queue.h"

template <typename T>
QueueNode<T>::QueueNode(const T& value) : data(value), next(nullptr) {}

template <typename T>
void Queue<T>::clear()
{
    while (head)
    {
        QueueNode<T>* temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;
}

template <typename T>
Queue<T>::Queue() : head(nullptr), tail(nullptr) {}

template <typename T>
Queue<T>::~Queue() { clear(); }

template <typename T>
void Queue<T>::enqueue(const T& value)
{
    QueueNode<T>* node = new QueueNode<T>(value);
    if (!tail)
    {
        head = tail = node;
    }
    else
    {
        tail->next = node;
        tail = node;
    }
}

template <typename T>
template<typename Compare>
void Queue<T>::sort(Compare comp)
{
    if (!head || !head->next)
    {
        return;
    }

    bool swapped;
    do {
        swapped = false;
        QueueNode<T>* current = head;
        while (current->next)
        {
            if (comp(current->next->data, current->data))
            {
                swap(current->data, current->next->data);
                swapped = true;
            }
            current = current->next;
        }
    } while (swapped);
}

template <typename T>
bool Queue<T>::dequeue(T& value)
{
    if (!head)
    {
        return false;
    }
    QueueNode<T>* temp = head;
    value = head->data;
    head = head->next;
    if (!head)
    {
        tail = nullptr;
    }
    delete temp;
    return true;
}

template <typename T>
QueueNode<T>* Queue<T>::find(const T& value) const
{
    QueueNode<T>* current = head;
    int idx = 1;
    while (current)
    {
        if (current->data == value)
        {
            if (idx == 1)
            {
                current->data.printHeader();
            }
            cout << current->data << endl;
            idx++;
        }
        current = current->next;
    }
    if (idx == 1)
    {
        cout << "No maching objects.";
    }
    return nullptr;
}

template <typename T>
void Queue<T>::print() const
{
    if (!head)
    {
        cout << "Queue is empty.\n";
        return;
    }
    QueueNode<T>* current = head;
    int idx = 1;
    while (current)
    {
        cout << current->data << endl;
        current = current->next;
    }
}