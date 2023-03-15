#include<iostream>
using namespace std;
class Node{
  public:
  int seat_number;
  string name;
  Node* next;
  Node* prev;
    };
void initialise(Node* &head){
    Node* newnode;
    Node* temp;
    int ch;
    ch = 11;
    while(ch<=80){
    newnode = new Node;
    newnode->name = "!____!";
    newnode->seat_number = ch;
    if(head == 0){
        head = newnode;
        temp = newnode;
    }
    else{
        temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->prev = temp;
        temp = temp->next;
    }
    ch++;
    }
    temp = head;
    while(temp->next != NULL){
            temp = temp->next;
        }
        head->prev = temp;
        temp->next = head;
        cout<<"Booking started \n";
}
void purchase_ticket(Node* &head){
    if(head == 0){
        cout<<"Booking not started\n";
    }
    else{
    Node* temp;
    temp = head;
    string name;
    int seat_number;
    int ch;
    ch = 1;
    while(ch){
    cout<<"enter the name\n";
    cin>>name;
    cout<<"enter the seat number between 11 to 80 only\n";
    cin>>seat_number;
    if (seat_number>80 || seat_number<11 )
        {cout<<"Out of range\n";}  
        else{
    while(temp->seat_number != seat_number){
        temp = temp->next;
    }
    temp->seat_number = seat_number;
    temp->name = name;
    cout<<"Enter 1 to purchase the ticket  0 for donot buy\n";
    cin>>ch;
    }
    }
    }
}
void display(Node* head){
    if(head == 0){
        cout<<"Booking not started stay tuned\n";
    }
    else{
        cout<<"current booking status\n";
    Node* temp = head;
    for(int r=0;r<10;r++){
        for(int c = 0;c < 7;c++){
            cout<<temp->seat_number<<"->!"<<temp->name<<"!  ";
            temp = temp->next;
        }
        cout<<"\n";
    }
}
}

void cancelled(int val,Node* &head){
    if(head==NULL){
        cout<<"Booking not started\n";
    }
    else{
    Node *temp;
    Node* dumm;
    temp = head;
    int value = 88;
    while(value != val){
        value = temp->seat_number;
        temp = temp->next;
    }
    temp = temp->prev;
    temp->name = "!____!";
    temp->seat_number = val;
    
    }
}


int main(){
    Node* head;
    head = 0;
    bool flag=true;
    while(flag){
    cout<<"---------MENU FOR operation in doubly linked list---------\n";
    cout<<"1.Start the ticketing \n" ;
    cout<<"2.Purchase ticket \n" ;
    cout<<"3.Display booked tickets\n";
    cout<<"4.cancelled the ticket\n";
    cout<<"5.end\n";
    cout<<"Enter the correct choice number\n";
    int ch;
    cin>>ch;
    switch(ch){
        case 1:{
            initialise(head);
            break;
        }
        case 2:{
            purchase_ticket(head);
            break;
        }
        case 3:{
            display(head);
            break;
        }
        case 4:{
            int seat_number;
            cout<<"Enter the seat number to delete\n";
            cin>>seat_number;
            cancelled(seat_number,head);
            break;
        }
        case 5:{
            cout<<"End\n";
            flag= false;
            break;
        }
        default:{
            cout<<"wrong input entered\n";
        }
    }
    }
    return 0;
}



