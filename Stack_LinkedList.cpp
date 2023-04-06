#include <iostream>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;


class Stack{
    private:
        int arr[20];
        int top;

    public:
        Stack() {
            top = -1;
        }

        bool Is_Empty(){
            return (top == -1);
        }

        bool Is_Full(){
            int Size = sizeof(arr) / sizeof(arr[0]);
            return (top == Size-1);
        }

        void push(int x){
            if(Is_Full()){
                cout << "Error: Stack overflow" << endl;
            }
            else{
                arr[++top] = x;
            }
        }

        int pop() {
            if(Is_Empty()){
                cout << "Error: Stack underflow" << endl;
                return -1;
            }
            else {
                int x = arr[top--];
                return x;
            }
        }

        void display(){
            if(Is_Empty()){
                cout << "Error: Stack underflow" << endl;
            }
            else {
                cout << "Stack elements: ";
                for (int i = 0; i <= top; i++) {
                    cout << arr[i] << " ";
                }
                cout << endl;
            }
        }
};

void Create_Stack(){
    Stack s;

    s.push(8);
    s.push(10);
    s.push(5);
    s.push(11);
    s.push(15);
    s.push(23);
    s.push(6);
    s.push(18);
    s.push(20);
    s.push(17);

    s.display();

    cout<<"Stack elements pop: ";
    for(int i=0;i<5;i++){
        cout<<s.pop()<<" ";
    }
    cout<<"\n";

    s.display();

    s.push(4);
    s.push(30);
    s.push(3);
    s.push(1);

    s.display();
}

int main()
{
    srand(time(NULL));
    auto start_time = high_resolution_clock::now();
    Create_Stack();
    auto end_time = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end_time - start_time);
    cout << "Execution time is " << duration.count() <<" microseconds"<<endl;
    return 0;
}
