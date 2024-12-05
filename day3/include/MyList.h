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

    void push(int index, T data){
        if (index < 0 || index > current) {
            throw out_of_range("Index out of range");
        }
        if (current == capacity) expand();
        for (int i = current; i > index; i--) {
            arr[i] = arr[i-1];
        }
        arr[index] = data;
    }

    T get(int index){
        if (index < current) return arr[index];
        throw out_of_range("Index out of range");
    }

    void pop() { current--; }
    void pop(int index) {
        if (index < 0 || index >= current) {
            throw out_of_range("Index out of range");
        }
        for (int i = index; i < current-1; i++) {
            arr[i] = arr[i+1];
        }
        current--;
    }

    int getSize() { return current; }
    int getcapacity() { return capacity; }
    void display(){
        for (int i = 0; i < current; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void clear(){
        delete[] arr;
        arr = new T[1];
        capacity = 1;
        current = 0;
    }

    MyList<T>& operator=(MyList<T> &l) {
        delete[] arr;
        capacity = l.capacity;
        current = l.current;
        arr = new T[l.capacity];
        for (int i=0; i<current; i++) {
            arr[i] = l.arr[i];
        }
        return *this;
    }

    ~MyList() { delete[] arr; }
};

#endif // MYLIST_H
