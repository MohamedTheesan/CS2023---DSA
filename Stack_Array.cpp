#include <iostream>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;

class Node {
    public:
        int data;
        Node* next;
};

class Stack {
    private:
        Node* top;

    public:
        Stack() {
            top = nullptr;
        }

        void push(int x) {
            Node* new_node = new Node();
            new_node->data = x;
            new_node->next = top;
            top = new_node;
        }

        int pop() {
            if (top == nullptr) {
                cout << "Error: Stack underflow" << endl;
                return -1;
            }
            else {
                int x = top->data;
                Node* temp = top;
                top = top->next;
                delete temp;
                return x;
            }
        }

        void display() {
            if (top == nullptr) {
                cout << "Stack is empty" << endl;
            }
            else {
                cout << "Stack elements: ";
                display_helper(top);
                cout << endl;
            }
        }

        void display_helper(Node* node) {
            if (node != nullptr) {
                display_helper(node->next);
                cout << node->data << " ";
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

