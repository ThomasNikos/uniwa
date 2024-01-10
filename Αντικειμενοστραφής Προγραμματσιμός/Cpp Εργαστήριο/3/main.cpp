#include <iostream>
#include <cstring>

template <class Q>
class Queue
{
    Q *queue;
    int bottom;
    int top;
    int size;

public:
    Queue(int S);
    void Empty();
    void Full();
    void Push(const Q value);
    void Pop();
    int Size();
    void Print();
    void operator==(const Queue &Q1);
};

template <class Q>
Queue<Q>::Queue(int S) : size(S)
{
    queue = new Q[size];
    bottom = top = 0;
}

template <class Q>
void Queue<Q>::Empty()
{
    if (bottom == 0)
        throw 10;
    top++;
    bottom++;
    return;
}

template <class Q>
void Queue<Q>::Full()
{
    if (top >= size)
        throw 20;
    return;
}

template <class Q>
void Queue<Q>::Push(const Q value)
{
    Full();
    if (bottom == 0 && top == 0)
        bottom++;
    queue[top++] = value;
}

template <class Q>
int Queue<Q>::Size()
{
    return top;
}

template <class Q>
void Queue<Q>::Pop()
{
    Empty();
    Q *temp = new Q[size];
    memcpy(temp, queue, sizeof(temp));
    delete[] queue;

    queue = new Q[size - 1];
    bottom++;
    for (int i = 1; i < top; i++)
        queue[i] = temp[i];
    return;
}

template <class Q>
void Queue<Q>::Print()
{
    for (int i = 0; i < top; i++)
        std::cout << " ITEM : " << queue[i] << std::endl;
}

template <class Q>
void Queue<Q>::operator==(const Queue &Q1)
{
    int counter = 0;
    if (Q1.top > this->top)
        std::cout << "NOT EQUAL " << std::endl;
    else if (Q1.top < this->top)
        std::cout << "NOT EQUAL " << std::endl;
    else if (Q1.top == this->top)
    {
        for (int i = 0; i < this->top; i++)
            if (this->queue[i] != Q1.queue[i])
                counter++;
        if (counter > 0)
            std::cout << "NOT EQUAL" << std::endl;
        else
            std::cout << "EQUAL" << std::endl;
    }
}

int main(int argc, char *argv[])
{

    try
    {
        Queue<float> Q1(10);
        Queue<float> Q2(10);
        Q1.Push(2.5);
        Q1.Push(2.6);
        Q1.Pop();
        Q1.Print();
        Q2 == Q1;
        // Q1.Print();
        // std::cout << std::endl;
        //  Q1.Pop();
        //  Q1.Print();
    }
    catch (int S)
    {
        if (S == 20)
            std::cout << "FULL" << std::endl;
        else if (S == 10)
            std::cout << "EMPTY" << std::endl;
    }
    return 0;
}
