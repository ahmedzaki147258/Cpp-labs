#include <iostream>
#include "./include/MyList.h"
#include "./include/MyString.h"

using namespace std;
int main(){
    try {
        MyList<int> v;
        v.push(10);
        v.push(20);
        v.push(30);
        v.push(40);
        v.push(50);

        cout << "MyList size: " << v.getSize() << endl;
        cout << "MyList capacity: " << v.getcapacity() << endl;

        cout << "MyList elements: ";
        v.display();
        v.push(1, 100);

        cout << "\nMyList elements after insert: ";
        v.display();

        v.pop();
        v.pop(2);
        cout << "\nMyList size after pop: " << v.getSize() << endl;
        cout << "MyList elements after pop: ";
        v.display();
        cout << "MyList element: " << v.get(2) << endl;

        MyList<int> l;
        l=v;
        cout << "list l elements after =operator overloading: ";
        v.display();
    } catch (const exception &e) {
        cout << e.what() << endl;
    }
    cout << "***************************** End Vector *****************************" << endl << endl;

    MyString s1("A7med zaki");
    MyString s2(s1);
    MyString s3=s1;
    s1.print();
    s2.print();
    s3.print();
    int compate = s1==s2;
    cout << "compare: " << compate << endl;
    cout << "concat: ";
    (s1+" "+s2).print();
    cout << "***************************** End String *****************************" << endl;

    return 0;
}
