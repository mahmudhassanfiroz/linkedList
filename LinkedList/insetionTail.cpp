#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int value;
    Node *Next;

    //Constructer creation....
    Node(int val){
        value = val;
        Next = NULL;
    }
};

void insertAtTail(Node * &head, int val);
void insertAtHead(Node * &head, int val);
void display(Node *n);
int countLength(Node *&head);



void insertAtTail(Node *&head, int val){
    Node *newNode = new Node(val);

    if(head == NULL){
        head = newNode;
        return;
    }
    Node *temp = head;
    while(temp->Next != NULL){
        temp = temp->Next;
    }
    temp->Next = newNode;
}
void insertAtHead(Node * &head, int val){
    //step 1: newNode creation
    Node *newNode = new Node(val);
    //step 2: Update of newNode->Next
    newNode->Next = head;
    //step 3: Update of head
    head = newNode;
}
void display(Node *n){
    while(n != NULL){
        cout << n->value;
        if(n->Next != NULL) cout<<" -> ";
        n = n->Next;
    }
    cout<<endl<<endl;
}
int countLength(Node *&head){
    int count = 0;
    Node *temp = head;

    while(temp != NULL){
        count++;
        temp = temp->Next;
    }
    return count;
}



int main(){
    Node *head = NULL;
    int value;
    
    cout<<"Choice 1: Insertion at Head"<<endl
    <<"Choice 2: Insertion at Tail"<<endl
    <<"Choice 0: Exit"<<endl
    <<endl;
    cout<<"Next Choice: ";
    int choice;
    cin>>choice;

    while(choice != 0){
        switch(choice){
            case 1:
            cout << "Enter the value: ";
            cin >> value;
            insertAtHead(head,value);
            break;
            case 2:
            cout << "Enter the Value: ";
            cin >> value;
            insertAtTail(head, value);
            break;
            default:
            break;

        }
        cout << "Next Choice: ";
        cin >> choice;
    }
    cout << "Linked List: ";
    display(head);

    cout << "Length of the List: "<< countLength(head)<<endl;

    return 0;
}