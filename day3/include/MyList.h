#ifndef MYLIST_H
#define MYLIST_H

#include <iostream>
using namespace std;
template <typename T> class MyList{
    T* arr;
    int capacity;
    int current;

public:
    MyList(){
        arr = new T[1];
        capacity = 1;
        current = 0;
    }

    void expand() {
        T* temp = new T[2 * capacity];
        for (int i = 0; i < capacity; i++) {
            temp[i] = arr[i];
        }
        delete[] arr;
        arr = temp;
        capacity *= 2;
    }

    void push(T data){
        if (current == capacity) expand();
        arr[current] = data;
        current++;
    }

    void push(T data, int index){
        if (index == capacity)
            push(data);
        else
            arr[index] = data;
    }

    T get(int index){
        if (index < current) return arr[index];
        throw out_of_range("Index out of range");
    }

    void pop() { current--; }
    int getSize() { return current; }
    int getcapacity() { return capacity; }
    void display(){
        for (int i = 0; i < current; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    ~MyList() { delete[] arr; }
};

#endif // MYLIST_H
