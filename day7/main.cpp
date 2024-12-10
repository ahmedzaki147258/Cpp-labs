#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

struct Data {
    void* value;
    void (*deleter)(void*);
};

class DynamicList {
private:
    Data* list;
    int size;
    int capacity;

    void resize() {
        capacity *= 2;
        Data* newList = new Data[capacity];
        for (int i = 0; i < size; i++) {
            newList[i] = list[i];
        }
        delete[] list;
        list = newList;
    }

public:
    DynamicList(){
        size = 0; capacity = 1;
        list = new Data[capacity];
    }

    ~DynamicList() {
        for (int i = 0; i < size; i++) {
            list[i].deleter(list[i].value);
        }
        delete[] list;
    }

    template <typename T>
    void add(const T& value) {
        if (size == capacity) resize();
        list[size].value = new T(value);
        list[size].deleter = [](void* ptr) { delete static_cast<T*>(ptr); };
        size++;
    }

    template <typename T>
    T pop() {
        if (size == 0) throw out_of_range("List is empty, cannot pop");
        size--;
        T result = *static_cast<T*>(list[size].value); // Dereference pointer to get the value
        list[size].deleter(list[size].value);          // Free memory
        return result;
    }

    int getSize() {
        return size;
    }
};

class UserDefined {
    int id;
    string name;
public:
    UserDefined(int id, string name){
        this->id = id;
        this->name = name;
    }
    
    friend ostream& operator<<(ostream& os, const UserDefined& obj) {
        os << "UserDefined{id: " << obj.id << ", name: " << obj.name << "}";
        return os;
    }
};

int main() {
    DynamicList list;
    list.add(23);                      // Integer
    list.add(2.718);                   // Double
    list.add(true);                    // Boolean
    list.add(string("A7med"));         // String
    list.add(string("zaki"));          // String  
    list.add(UserDefined(1, "Messi")); // userDefined

    try {
        UserDefined user = list.pop<UserDefined>();
        cout << "Popped user-defined object: " << user << endl;

        string str = list.pop<string>();
        cout << "Popped string: " << str << endl;

        string str2 = list.pop<string>();
        cout << "Popped another string: " << str2 << endl;

        bool boolean = list.pop<bool>();
        cout << "Popped boolean: " << (boolean ? "true" : "false") << endl;

        double dbl = list.pop<double>();
        cout << "Popped double: " << dbl << endl;

        int integer = list.pop<int>();
        cout << "Popped integer: " << integer << endl;
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
    return 0;
}
