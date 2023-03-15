#include <iostream>

#define MAX 10

using namespace std;

class Queue{
    public:
        int front;
        int rear;
        int arr[MAX];

        Queue(){
            front = -1;
            rear = -1;
        }

        void enqueue(int val){
            if (rear == MAX-1){
                cout << "Queue Full\n";
            } else {
                rear++;
                arr[rear] = val;
                if (front == -1){
                    front = 0;
                }
            }
        }

        int dequeue(){
            if (front == -1){
                cout << "\nQueue Empty\n";
                return 0;
            }
            else{
            int temp = arr[0];
            for (int i=0; i<rear; i++){
                arr[i] = arr[i+1];
            }
            rear--;
            if (rear == -1){
                front = -1;
            }
            return temp;
        }
        }

        void display(){
            for (int i=0; i < rear+1; i++){
                cout << arr[i] << " ";
            }
            cout << "\n";
        }

};

int main(){
    Queue q;
    while (1){
        int i;
        cout << "\n1. To Add Job.\n2. To Remove Job\n3. To Display Queue\n4.To Finish\n";
        cout << "Enter Your response: " ;
        cin >> i;
        if (i == 1){
            int data;
            cout << "Enter data(int): ";
            cin >> data;
            q.enqueue(data);
        } else if (i == 2 ){
            try{
                cout << "Removed " << q.dequeue() << "\n";
            } catch(...){}
        } else if (i == 3){
            cout << "Queue is: \n";
            q.display();
        } else{
            break;
        }
    }
    return 0;
}