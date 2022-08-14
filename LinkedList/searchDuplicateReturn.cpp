#include <bits/stdc++.h>
using namespace std;

struct Test
{
    int position[100];
};


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
void insertionAtSpecificPosition(Node *&head, int pos, int val);
int searchByValueUnique(Node *&head, int key);
void searchByValueDuplicate(Node *&head, int key);
Test searchByValueDuplicateReturn(Node *&head, int key);


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
void insertionAtSpecificPosition(Node *&head, int pos, int val){
    int i = 0;
    Node *temp = head;

    while (i < pos-2)
    {
        temp = temp->Next;
        i++;
    }
    Node *newNode = new Node(val);
    newNode->Next = temp->Next;
    temp->Next= newNode;
    
}
int searchByValueUnique(Node *&head, int key){
    Node *temp = head;
    if(temp == NULL){
        return -1;
    }
    int count = 1;
    while(temp->value != key){
        if(temp->Next == NULL){
            return -1;
        }
        temp = temp->Next;
        count++;
    }
    return count;
}
void searchByValueDuplicate(Node *&head, int key){
    Node * temp = head; 
    int count = 1;
    int flag = 0;
    int size;
    size = countLength(head);
    int position[size+1], k = 1;
    while(temp != NULL){
        if(temp->value == key){
            //cout << count << " ";
            position[k] = count;
            k++;
            flag = 1;
        }
        temp = temp->Next;
        count++;
    }
    if(flag == 0) cout << "The Search Value is not yet in the List" << endl;
    else{
        position[0] = k;
        cout << "The Value is found at position: ";
        for(int i = 1; i<position[0]; i++){
            cout << position[i];
            if(i < position[0]-1) cout << " , ";
        }
        cout << endl;
    }
}
Test searchByValueDuplicateReturn(Node *&head, int key){
    Node *temp = head;
    Test T;
    int count = 1;
    int k;
    while(temp != NULL){
        if(temp->value == key){
            //cout << count << " ";
            T.position[k] = count;
            k++;
        }
        temp = temp->Next;
        count++;
    }
    T.position[0] = k;
    return T;
}



int main(){
    Node *head = NULL;
    int value, position;
    
    cout<<"Choice 1: Insertion at Head"<<endl
    <<"Choice 2: Insertion at Tail"<<endl
    <<"Choice 3: Insertion at Specific Positon: "<<endl 
    <<"Choice 4: Search Value At Unique Value: "<<endl
    <<"Choice 5: Search Duplicate Value: " << endl
    <<"Choice 6: Search Duplicate Value Return: "<< endl
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
            case 3:
            cout << "Enter the Desired Position: ";
            cin >> position;
            cout << "Enter the value: ";
            cin >> value;
            insertionAtSpecificPosition(head,position,value);
            break;
            case 4:
            cout << "Enter the value to Search: ";
            cin >> value;
            position = searchByValueUnique(head,value);
            if(position != -1){
                cout << "The Number is at position " << position << endl;
            }
            else{
                cout << "The Number is not yet in the List" << endl;
            }
            break;
            case 5:
            cout << "Enter the Value to Search: ";
            cin >> value;
           cout << "The Number Is At Position: ";
           searchByValueDuplicate(head, value);
            break;
            case 6:
            cout << "Enter The Value To Search: ";
            cin >> value;
            Test T;
            T = searchByValueDuplicateReturn(head, value);
            if(T.position[0] == 1){
                cout << "The Search Value is Not Yet In the List"<< endl;
            }
            else{
                int size = T.position[0];
                cout << "The Value is found at position: ";
                for(int i = 1; i<size; i++){
                    cout << T.position[i];
                    if(i < size-1) cout << " , ";
                }
                cout << endl;
            }
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