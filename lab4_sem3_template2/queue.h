#pragma once
#pragma once
#include <iostream>
#include "Student.h"
#include "SpecialtyTeacher.h"
#include "GroupTeacher.h"
#include <string>

using namespace std;

template <typename T>
class Queue;

template <typename T>
struct QueueNode {
    T data;
    QueueNode* next;
    friend class Queue<T>;
    QueueNode(const T& value);
};

template <typename T>
class Queue
{
private:
    QueueNode<T>* head;
    QueueNode<T>* tail;

    void clear();

public:
    Queue();
    ~Queue();

    void enqueue(const T& value);
    bool dequeue(T& value);

    template<typename Compare>
    void sort(Compare comp);

    QueueNode<T>* find(const T& value) const;
    void print() const;
};


