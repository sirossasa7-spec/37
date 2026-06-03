#pragma once
#include <iostream>
#include <stdexcept>

template <typename T>
class MyStack
{
private:
    static const int MAX_SIZE = 100;
    T arr[MAX_SIZE];
    int topIndex;

public:
    MyStack();

    bool isEmpty() const;
    T top() const;
    void push(const T& value);
    void pop();
    void clear();
    void show() const;
};

template <typename T>
MyStack<T>::MyStack() : topIndex(-1) {}

template <typename T>
bool MyStack<T>::isEmpty() const
{
    return topIndex == -1;
}

template <typename T>
T MyStack<T>::top() const
{
    if (isEmpty())
        throw std::out_of_range("Stack is empty!");

    return arr[topIndex];
}

template <typename T>
void MyStack<T>::push(const T& value)
{
    if (topIndex >= MAX_SIZE - 1)
        throw std::overflow_error("Stack overflow!");

    arr[++topIndex] = value;
}

template <typename T>
void MyStack<T>::pop()
{
    if (isEmpty())
        throw std::out_of_range("Stack is empty!");

    --topIndex;
}

template <typename T>
void MyStack<T>::clear()
{
    topIndex = -1;
}

template <typename T>
void MyStack<T>::show() const
{
    if (isEmpty())
    {
        std::cout << "Stack is empty\n";
        return;
    }

    for (int i = topIndex; i >= 0; --i)
        std::cout << arr[i] << std::endl;
}