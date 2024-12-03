#include <iostream>

using namespace std;

void swapByValue(int a, int b);
void swapByAddress(int *a, int *b);
void swapByReference(int &a, int &b);

class Complex{
    float real;
    float imaginary;

public:
    Complex(){}
    Complex(float num){
        real=num;
        imaginary=num;
    }
    Complex(float real, float imaginary){
        this->real=real;
        this->imaginary=imaginary;
    }

    void setReal(float r){
        real=r;
    }
    float getReal(){
        return real;
    }
    void setImaginary(float i){
        imaginary=i;
    }
    float getImaginary(){
        return imaginary;
    }
    void setComplex(float real, float imaginary){
        this->real=real;
        this->imaginary=imaginary;
    }

    Complex addComplex(Complex c){
        real+=c.real;
        imaginary+=c.imaginary;
        return *this;
    }
    Complex subComplex(Complex c){
        real-=c.real;
        imaginary-=c.imaginary;
        return *this;
    }

    void display(){
        if (real == 0 && imaginary == 0) {
            cout << 0 << endl;
        } else if (real == 0) {
            cout << imaginary << "i" << endl;
        } else if (imaginary == 0) {
            cout << real << endl;
        } else {
            cout << real;
            if (imaginary > 0) {
                cout << "+";
            }
            cout << imaginary << "i" << endl;
        }
    }

    ~Complex(){
        cout << "End of object" << endl;
    }
};

int main()
{
    Complex c1,c2,c3,c4,c5(2),c6(4,7),c7;

    c1.setReal(5.5);
    c1.setImaginary(-2.7);
    cout << "num1: ";
    c1.display();

    c2.setReal(-6.1);
    c2.setImaginary(-2.3);
    cout << "num2: ";
    c2.display();

    Complex result = c1.addComplex(c2);
    cout << "sum : ";
    result.display();
    cout << endl << endl;

    c3.setReal(5.5);
    c3.setImaginary(-2.7);
    cout << "num3: ";
    c3.display();

    c4.setReal(-6.1);
    c4.setImaginary(-2.3);
    cout << "num4: ";
    c4.display();

    result = c3.subComplex(c4);
    cout << "sub : ";
    result.display();


    cout << "constructor1 : ";
    c5.display();

    cout << "constructor2 : ";
    c6.display();

    c7.setComplex(1,3);
    cout << "setComplex : ";
    c7.display();
    cout << endl << "*************************************End Question1*************************************" << endl;

    int n;
    cout << "Enter length of array: ";
    cin >> n;
    int *ptr = new int[n];
    for(int i=0;i<n;i++){
        cout << "Enter element #" << i+1 << ": ";
        cin >> ptr[i];
    }

    cout << endl << "Display array:" << endl;
    for(int i=0;i<n;i++){
        cout << "element #" << i+1 << ": " << ptr[i] << endl;
    }
    delete[] ptr;
    cout << endl << "*************************************End Question2*************************************" << endl;

    int num1 = 5, num2 = 6;
    cout << "result of swap by value" << endl;
    swapByValue(num1, num2);
    cout << "num1: " << num1 << endl;
    cout << "num2: " << num2 << endl << endl;

    cout << "result of swap by address" << endl;
    swapByAddress(&num1, &num2);
    cout << "num1: " << num1 << endl;
    cout << "num2: " << num2 << endl << endl;

    num1 = 5; num2 = 6;
    cout << "result of swap by reference" << endl;
    swapByReference(num1, num2);
    cout << "num1: " << num1 << endl;
    cout << "num2: " << num2 << endl;
    cout << "*************************************End Question3*************************************" << endl;
    return 0;
}

void swapByValue(int a, int b){
    int temp=b;
    b=a;
    a=temp;
}
void swapByAddress(int *a, int *b){
    int temp=*b;
    *b=*a;
    *a=temp;

}
void swapByReference(int &a, int &b){
    int temp=b;
    b=a;
    a=temp;
}
