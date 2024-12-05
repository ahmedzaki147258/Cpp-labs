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
int myStringCompare(char str1[], char str2[]){
    if(myStringLength(str1) > myStringLength(str2)){
        return 1;
    } else if(myStringLength(str1) < myStringLength(str2)){
        return -1;
    } else {
        for(int i=0;i<myStringLength(str1);i++){
            if(str1[i] > str2[i]){
                return 1;
            } else if(str1[i] < str2[i]){
                return -1;
            }
        }
    }
    return 0;
}
void myStringConcat(char s1[], char s2[]){
    int i = myStringLength(s1), j = 0;
    while(s2[j] != '\0'){
        s1[i] = s2[j];
        i++; j++;
    }
    s1[i] = '\0';
}

class MyString{
    char *str;

public:
    MyString(){
        str = new char[1];
        str[0] = '\0';
    }
    MyString(char *s){
        int length = myStringLength(s);
        str = new char[length + 1];
        myStringCopy(str, s);
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
    int operator==(MyString &source) {
        return myStringCompare(str, source.str);
    }
    MyString operator+(const MyString& source){
        myStringConcat(str, source.str);
        return str;
    }

    void print(){ cout << str << endl; }
    ~MyString() { delete[] str; }
};

#endif // MYSTRING_H
