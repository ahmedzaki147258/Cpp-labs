#include <iostream>
#include <termios.h>
#include <unistd.h>
#include <limits>

#define SIZE 3
#define ESC 27
#define UP 65
#define DOWN 66
#define ENTER 10

using namespace std;

char getKey() {
    struct termios oldt, newt;
    char ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}

void setColor(int color) {
    switch (color) {
        case 1: std::cout << "\033[32m"; break;  // Green
        default: std::cout << "\033[37m"; break;  // White
    }
}

void simulateKeyPress(const string &key) {
    string command = "xdotool key " + key;
    system(command.c_str());
}

void timerOut(){
    clock_t start = clock();
    while (true) {
        clock_t now = clock();
        double elapsed_time = double(now - start) / CLOCKS_PER_SEC;
        if (elapsed_time >= 1.5) { // 1.5 second
            simulateKeyPress("A");
            break;
        }
    }
}

struct Employee {
    string name;
    int netSalary;
};

template <typename T>
class Stack {
private:
    T *items;
    int top;
    int size;
    int *ptr;
    static int count;

public:
    Stack(int size) {
        this->size = size;
        items = new T[size];
        top = -1;
        ptr=new int[3];
        ptr[0]=1;ptr[1]=2;ptr[2]=3;
        count++;
    }

   Stack(Stack &s) {
        size = s.size;
        top = s.top;
        items = new T[size];
        for (int i = 0; i <= top; i++) {
            items[i] = s.items[i];
        }

        ptr = new int[4];
        for (int i=0; i<4; i++) {
            ptr[i] = i+1;
        }
        count++;
    }

    void push(T item) {
        if (top == size-1) throw runtime_error("Exception: Stack is full.");
        else items[++top] = item;
    }

    T pop() {
        if (top == -1) throw runtime_error("Exception: Stack is empty.");
        else return items[top--];
    }

    void display() {
        if (top == -1) {
            cout << "Stack is empty." << endl;
            return;
        }

        cout << "Stack data:" << endl;
        for (int i = top; i >= 0; i--) {
            if constexpr (is_same_v<T, Employee>) {
                cout << "Employee #" << i+1 << " Name: " << items[i].name << " - Salary: " << items[i].netSalary << endl;
            } else {
                cout << "Number #" << i+1 << ": " << items[i] << "\t";
                cout << "array: ";
                for(int j=0;j<4;j++){
                    cout << this->ptr[j] << "  ";
                }
                cout << endl;
            }
        }
    }

    static int getCounter(){
        return count;
    }

    Stack& operator=(Stack &s) {
        delete[] items;
        delete[] ptr;
        size = s.size;
        top = s.top;
        items = new T[size];
        for (int i=0; i<=top; i++) {
            items[i] = s.items[i];
        }
        ptr = new int[4];
        for (int i=0; i<4; i++) {
            ptr[i] = i+1;
        }
        return *this;
    }

    ~Stack() {
        delete[] ptr;
        delete[] items;
        count--;
    }
};
template <typename T>
int Stack<T>::count = 0;

template <typename T>
void viewContentByReference(Stack<T> &x){
    x.display();
}

template <typename T>
void viewContentByValue(Stack<T> x){
    x.display();
}

void displayMenu(int selectedOption) {
    system("clear");
    for (int i = 1; i <= SIZE; i++) {
        if (i == selectedOption + 1) {
            setColor(1);
            cout << "-> ";
        } else {
            setColor(0);
            cout << "   ";
        }

        switch (i) {
            case 1: cout << "1. Push" << endl; break;
            case 2: cout << "2. Pop" << endl; break;
            case 3: cout << "3. Display" << endl; break;
        }
    }
    setColor(0);
}

int main(){
    /*try{
        Stack<int> s(5);
        s.push(10);
        s.push(20);
        s.pop();
        s.push(30);
        s.push(40);
        s.pop();
        s.push(50);
        s.push(60);
        s.display();

        Stack<int> f(s); // copy constructor
        //Stack<int> f(5);
        //f=s; // assignment operator

        cout << "\nf :";
        viewContentByReference(f);

        f.push(70);
        cout << "\nf after update: ";
        viewContentByReference(f);

        cout << "\ns after update: ";
        viewContentByReference(s);
    } catch (const exception &e) {
        cout << e.what() << endl;
    }
    cout << "***************************** End Stack *****************************" << endl;*/

    Stack<float> f1(1);
    cout << "Number of created object after f1: " << Stack<float>::getCounter() << " objects."<< endl;

    Stack<float> f2(1);
    cout << "Number of created object after f2: " << Stack<float>::getCounter() << " objects."<< endl;
    cout << "***************************** End Static Method *****************************" << endl;

    int n;
    bool flag=true;
    cout << "Enter number of Employees: ";
    while (flag) {
        cin >> n;
        if (cin.fail() || n <= 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear invalid input
            cout << "Invalid input. Enter a valid positive integer for number of Employees: ";
        } else {
            flag=false;
        }
    }
    flag=true;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear newline char
    Stack<Employee> employeeStack(n);

    int selectedOption = 0;
    while (true) {
        displayMenu(selectedOption);
        char ch = getKey();
        if (ch == UP) {
            selectedOption = (selectedOption - 1 + SIZE) % SIZE;
        } else if (ch == DOWN) {
            selectedOption = (selectedOption + 1) % SIZE;
        } else if (ch == ENTER) {
            system("clear");
            if (selectedOption == 0) { // push
                Employee e;
                cout << "Enter Employee Name: ";
                getline(cin, e.name); // allow spaces
                cout << "Enter Employee Salary: ";
                bool flag = true;
                while (flag) {
                    cin >> e.netSalary;
                    if (cin.fail() || e.netSalary <= 0) {
                        cin.clear(); // clear the error flag
                        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear invalid input
                        cout << "Invalid input. Enter Employee salary: ";
                    } else {
                        flag = false;
                    }
                }
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear newline char

                try {
                    employeeStack.push(e);
                    cout << "Employee added!" << endl;
                    timerOut();
                } catch (const exception &e) {
                    cout << e.what() << endl;
                }
            } else if (selectedOption == 1) { // pop
                try {
                    Employee e = employeeStack.pop();
                    cout << "Employee removed: " << e.name << ", Salary: " << e.netSalary << " successfully. " << endl;
                    timerOut();
                } catch (const exception &e) {
                    cout << e.what() << endl;
                }
            } else if (selectedOption == 2) { // display
                employeeStack.display();
            }

            getKey();
        }
    }

    return 0;
}
