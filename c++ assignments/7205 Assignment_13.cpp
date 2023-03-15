#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    Node* next;
    char val;
};
void push(char n,Node* &top){
    Node* newnode;
    newnode = new Node;
    newnode->val = n;
    newnode->next = NULL;
    if(top == NULL){
        top = newnode;
    }
    else{
        newnode->next = top;
        top = newnode;
    }
}
    
void pop(Node* &top){
    if(top == NULL){
        cout<<"stack is completely empty\n";
    }
    else{
        Node* temp;
        temp = top;
        top = top->next;
        delete temp;
    }
}
void is_palindrome(string s,Node* &top){

    string choice;
    choice = s;
    for(int i = 0;i<s.size();i++){
        if(s[i] != ' '){
        push(s[i], top);
        }
    }
    string palindrome;
    int h = 0;
    while(top !=NULL){
        palindrome = palindrome + top->val;
        h++;
        pop(top);
    }
    choice.erase(remove(choice.begin(), choice.end(), ' '), choice.end());
    if(palindrome == choice){
        cout<<"\nString is palindrome \n";
        cout<<"Original string after removing spaces = "<<choice<<"\n";
        cout<<"Palindromic string after removing spaces = "<<palindrome<<"\n";
    }
    else{
        cout<<"\nString is not palindrome \n";
        cout<<"Original string after removing spaces = "<<choice<<"\n";
        cout<<"Palindromic string after removing paces = "<<palindrome<<"\n";
    }
}


int main(){
    Node* top;
    top = 0;
    string result;
    bool flag = true;
    while(flag){
    cout<<"--------MENU for check palindromic string after removing all the spaces from string----------\n";
    cout<<"1.Enter the string\n";
    cout<<"2.check the Palindromic string\n";
    cout<<"3.EXIT\n";
    cout<<"Enter the correct choice number\n";
    int ch;
    cin>>ch;
    switch(ch){
    case 1:
    {
        getline(cin >> ws, result);
        break;
    }
        
        case 2:{
            is_palindrome(result , top);
            break;
        }
        
        case 3:{
            flag = false;
            break;
        }
        default:{
            cout<<"Enter the correct choise\n";
            break;
        }
    }
    }
        return 0;
}

