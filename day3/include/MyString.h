#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>
using namespace std;

int myStringLength(char str[]) {
    int length = 0;
    while (str[length] != '\0') length++;
    return length;
}
void myStringCopy(char destination[], char source[]){
    int i = 0;
    while(source[i] != '\0'){
        destination[i] = source[i];
        i++;
    }
    destination[i] = '\0';
}

class MyString{
    char *str;

public:
    MyString(){
        str = new char[1];
        str[0] = '\0';
    }

    MyString(char *val){
        int length = myStringLength(val);
        str = new char[length + 1];
        myStringCopy(str, val);
    }

    MyString(MyString &source){
        int length = myStringLength(source.str);
        str = new char[length + 1];
        myStringCopy(str, source.str);
    }

    MyString operator=(MyString &source) {
        delete[] str;
        int length = myStringLength(source.str);
        str = new char[length + 1];
        myStringCopy(str, source.str);
        return *this;
    }

    void print(){ cout << str << endl; }

    ~MyString() { delete[] str; }
};

#endif // MYSTRING_H
