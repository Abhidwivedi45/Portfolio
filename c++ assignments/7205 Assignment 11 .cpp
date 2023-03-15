#include<iostream>
#include<string>
using namespace std;

//CREATION OF A NODE
class Node
{
    public:
        int pnr;
        string name;
        Node *next;
};

//DISPLAY FUNCTION
void display(Node* list,int n)
{
    if(n==0){
                cout<<"\nNo Member in the club \n";
                }
                cout<<"\nDisplaying the List: \n";
                Node *temp=list;
                for(int i=0;i<n;i++)
                {
                    if(i==0){
                        cout<<"\nDetails of President: \n";
                        cout<<"PRN: "<<temp->pnr;
                        cout<<"\nName: "<<temp->name;
                    }
                    else if(i==n-1){
                        cout<<"\n\nDetails of Secretary: \n";
                        cout<<"PRN: "<<temp->pnr;
                        cout<<"\nName: "<<temp->name;
                    }

                    else{
                        cout<<"\n\nDetails of Member "<<i<<": \n";
                        cout<<"PRN: "<<temp->pnr;
                        cout<<"\nName: "<<temp->name;
                    }
                    temp=temp->next;

                }

}


//PRINTING IN REVERSE ORDER USING RECURSSION
void Reverseprint(Node* temp)
{
    if(temp==NULL){
        return;
    }
    Reverseprint(temp->next);
    cout<<"\n\nDetails of Member: \n";
    cout<<"PRN: "<<temp->pnr;
    cout<<"\nName: "<<temp->name;
}


//CONCATENATION OF TWO LINKED LIST
Node *concatenate(Node *president, Node *head,int no)
{
    Node *temp;
    if(president==NULL){
        return head;
    }
    if(head==NULL){
        return president;
    }

    for(temp=president;temp->next!=NULL; temp=temp->next);
    temp->next=head;
     return president;   
}


//MAIN FUNCTION
int main()
{
    Node *temp, *president= NULL, *start,*newll, *head2=NULL;

    int n;
    while(1){
    cout<<"\nEnter the number of Members(including President and Secretary) : \n";
    cin >>n;
    if(n<1){
         cout<<"\n----Wrong Input----\nEnter Valid choice\n";
         continue;
    }
    break;
    }

    for(int i=0;i<n-1;i++)
    {
        temp=new Node();
        temp->next=NULL;
        if(president==NULL)
        {
            cout<<"\nEnter the details of President: \n";
            cout<<"PRN: ";
            cin>>temp->pnr;
            cout<<"Name: ";
            cin>>temp->name;

            start=temp;
            president=temp;
        }
        else
        {
            cout<<"\n\nEnter the details of Member: \n";
            cout<<"PRN: ";
            cin>>temp->pnr;
            cout<<"Name: ";
            cin>>temp->name;

            start->next=temp;
            start=temp;

        }
    }
    temp=new Node();
    temp->next=NULL;
    cout<<"\n\nEnter the details of Secretary: \n";
    cout<<"PRN: ";
    cin>>temp->pnr;
    cout<<"Name: ";
    cin>>temp->name;
   
    start->next=temp;
    start=temp;



    lb2:
    cout<<"\n\n-------------------- MENU -------------------\n";
    cout<<"\n1. Display Members";
    cout<<"\n2. Add a member";
    cout<<"\n3. Delete a member";
    cout<<"\n4. Total number of members of club";
    cout<<"\n5. Display list in reverse order";
    cout<<"\n6. Concatenate two lists";
    cout<<"\n7. Exit";

    int ch;
    cout<<"\n\nEnter your choice: ";
    cin>>ch;

    switch(ch)
    {
        case 1:
                display(president,n);               //DISPLAYING LIST
                goto lb2;


        case 2:
                int key;                            //ADDITION OF A MEMBER
                while(1){
                cout<<"\nEnter the place you want to add the member(1 for President, "<<n<<" for secretary): \n";
                cin>>key;
                if(key<1 || key > n){
                     cout<<"\n----Wrong Input----\nEnter Valid choice\n";
                     continue;
                }
                break;
                }
                temp=president, start=president;
                Node *temp1;
                for(int i=0;i<n;i++){

                    if(key-1==0){
                        temp1=new Node();
                        cout<<"\n\nEnter the details of New President: \n";
                        cout<<"PRN: ";
                        cin>>temp1->pnr;
                        cout<<"Name: ";
                        cin>>temp1->name;
                        temp1->next=temp;
                        president=temp1;
                        n++;
                        break;
                    }

                    else if(i==(key-1)){
                        temp1=new Node();
                        cout<<"\n\nEnter the details of Member: \n";
                        cout<<"PRN: ";
                        cin>>temp1->pnr;
                        cout<<"Name: ";
                        cin>>temp1->name;
                        temp=start->next;
                        start->next=temp1;
                        temp1->next=temp;
                        n=n+1;
                        break;

                    }
                    else{
                        temp=start->next;
                        start=temp;
                    }
                }
                goto lb2;

        case 3:                     		                  //DELETING A MEMBER
                cout<<"\nEnter the PNR of the member you want to delete: \n";
                cin>>key;

                temp=president, start=president;
                for(int i=0;i<n;i++){

                    if(president->pnr==key){
                        cout<<"\n\nYou have removed President\nMember 1 will become President now\n ";
                        temp=start->next;
                        start=temp;
                        president=temp;
                        n--;
                        break;
                    }

                    else if(temp->pnr==key){
                        cout<<"\nMember Removed\n";
                        temp=start->next;
                        temp1->next=temp;
                        n=n-1;
                        break;
                        
                    }
                    else{
                        temp1=start;
                        temp=start->next;
                        start=temp;
                    }
                }
                goto lb2;


        case 4:                                        //TOTAL MEMBERS
                cout<<"\nTotal number of members in the club are:  "<<n<<endl;
                goto lb2;

        case 5:                                        //PRINTING LIST IN REVERSE ORDER
                cout<<"\nReverse list is:";
                Reverseprint(president);
                goto lb2;

        case 6:                                        //CONCATENATING TWO LINKED LIST
                Node *temp2, *start2;
                int m;

                cout<<"\nDetails of Second list(SECOND Year student) to be concatenated\n";    
                cout<<"\nEnter the number of members: ";
                cin>>m;
    
                for(int i=0;i<m;i++)
                {
                    temp2=new Node();
        
                    cout<<"\n\nEnter the details of Member "<<i+1<<":\n";
                    cout<<"PRN: ";
                    cin>>temp2->pnr;
                    cout<<"Name: ";
                    cin>>temp2->name;
                    temp2->next=NULL;
                    if(head2==NULL)
                    {
                        start2=temp2;
                        head2=temp2;  
                    }   
                    else
                    {
                        start2->next=temp2;
                        start2=temp2;
                    }
        
                }

                newll=concatenate(president,head2,n+m);
                display(newll,n+m);
                goto lb2;

        case 7: break;                          //EXIT

        default:
                cout<<"\n----Wrong Input----\nEnter Valid choice\n";
                goto lb2;
    }

    return 0;
}
