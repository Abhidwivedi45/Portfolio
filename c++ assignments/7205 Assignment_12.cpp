#include <bits/stdc++.h>
using namespace std;

class Stack {
    public:
    int top;
    int a[1000];
    Stack() { top = -1; }
    void push(char x);
    int pop();
    int toper();
    bool isEmpty();
    bool areBracketsBalanced(string expr);
};


void Stack::push(char x)
        {
    if (top >= (1000 - 1)) {
        cout << "Stack Overflow";

    }
    else {
        a[++top] = x;
    }
}
int Stack::pop()
{
    if (top < 0) {
        cout << "Stack Underflow";
        return 0;
    }
    else {
        top--;
    }
}
int Stack::toper()
{
    if (top < 0) {
        cout << "Stack is Empty";
        return 0;
    }
    else {
        int x = a[top];
        return x;
    }
}

bool Stack::isEmpty()
{
    return (top < 0);
}

bool Stack::areBracketsBalanced(string expr)
{
	char x;

	for (int i = 0; i < expr.length(); i++)
	{
		if (expr[i] == '(' || expr[i] == '['
			|| expr[i] == '{')
		{
			push(expr[i]);
			continue;
		}


		if (isEmpty())
			return false;

		switch (expr[i]) {
		case ')':

			x = toper();
			pop();
			if (x == '{' || x == '[')
				return false;
			break;

		case '}':
			x = toper();
			pop();
			if (x == '(' || x == '[')
				return false;
			break;

		case ']':
			x = toper();
			pop();
			if (x == '(' || x == '{')
				return false;
			break;
		}
	}
	return (isEmpty());
}



int main()
{
    Stack s1;
    string expr;
    bool flag = true;
    while(flag){
    cout<<"--------Menu---------\n";
    cout<<"1.Enter the string to check formness of Parenthesis.\n";
    cout<<"2.To check formness of Parenthesis.\n";
    cout<<"3.Exit\n";
    cout<<"Enter the correct choice number\n";
    int ch;
    cin>>ch;
    switch(ch){
        case 1:{
        cout<<"Enter the string to check if it is balance or not\n";
        cin>>expr;
        break;
        }
    case 2:{
	if (s1.areBracketsBalanced(expr)){
		cout << "Paranthesis are Balanced\n";
		break;
	}

	else
	{
		cout << "Paranthesis are Not Balanced\n";
		break;
	}
	break;
}
case 3:{
    flag = false;
    break;
}
default:{
    cout<<"Wrong choice entered\n";
}
}
}
	return 0;
}


