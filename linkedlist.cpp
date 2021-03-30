#include<iostream>
using namespace std;
struct Node
{
    int data;
   struct Node *next;   
};
struct Node* head=NULL;
//insert at start//
void insertAtStart(int newData){
    struct Node* newNode=(struct Node*) malloc(sizeof(struct Node));
    newNode->data=newData;
    newNode->next=head;
    head=newNode;
}
void insertAtEnd(int newData)
{
    struct Node *newNode=(struct Node*) malloc(sizeof(struct Node));
    newNode->data=newData;
    
   if(head == NULL)
    {
        head=newNode;
    }
    else{
        struct Node* temp=head;
        while(temp->next!=NULL) temp=temp->next;
        temp->next=newNode;
        newNode->next=NULL;   
        }
    
}
void print()
{
    struct Node* temp=head;
    
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<"\n";
}
void printRev(Node* temp)
{
    if(temp==NULL)
        return;
    else
    {
        printRev(temp->next);
        cout<<temp->data<<" ";
    }
        
}
void reverseLL(Node* temp)
{
    struct Node* prev=NULL;
    struct Node* cur=temp;
    while(cur!=NULL)
    {
        struct Node* nextNode=cur->next;
        cur->next=prev;
        prev=cur;
        cur=nextNode;
    }
    head=prev;
}
void deleteAtStart()
{
    struct Node* temp=head;
    head=temp->next;
    delete temp;
}
void deleteAtEnd()
{
    struct Node* temp=head;
    if(head==NULL)
        return;
    else if(temp->next==NULL)
    {
        delete head;
        head=NULL;
    }
    else{
        while(temp->next!=NULL && temp->next->next!=NULL)
        {
            temp=temp->next;
        }
        delete temp->next;
        temp->next=NULL;
    }
}
void insertAtPos(int newData,int position)
{
    struct Node* temp=head;
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=newData;
    if(position==0)
        return;
    else if(position==1)
    {
      struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
      temp=head;
      head=newNode;
      newNode->next=temp;
    }
    else{
            while(position-1>1)
            {
                temp=temp->next;
                position--;
            }
            newNode->next=temp->next;
            temp->next=newNode;
        }
}
int main(){
    insertAtStart(3);
    print();
    insertAtStart(4);
    print();
    insertAtStart(5);
    print();
    insertAtEnd(100);
    print();
    insertAtEnd(101);
    print();
    // printRev(head);
    // reverseLL(head);
    // deleteAtStart();
    // deleteAtEnd();
    insertAtPos(500,3);
    print();
    return 0;
}
