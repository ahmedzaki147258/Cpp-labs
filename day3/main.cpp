#include <iostream>
#include "MyList.h"
#include "MyString.h"

using namespace std;

int main(){
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
    v.push(100, 1);

    cout << "\nMyList elements after update: ";
    v.display();

    v.pop();
    cout << "\nMyList size after pop: " << v.getSize() << endl;
    cout << "MyList elements after pop: ";
    v.display();

    try {
        cout << "MyList element: " << v.get(9) << endl;
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
    cout << "***************************** End String *****************************" << endl;

    return 0;
}
