#include<iostream>
using namespace std;
struct node{
    node * prev;
    int item;
    node *next;
};
class CDLL{
    private:
        node * start;
    public:
        CDLL();
        ~CDLL();
        void insertAtStart(int);
        void insertAtLast(int);
        node * search(int);
        void insertNode(node *,int);
        void deleteFirst();
        void deletelast();
};
CDLL::CDLL(){
    start = nullptr;
}
CDLL::~CDLL(){
    
    while(start!=nullptr)
        deleteFirst();
}
void CDLL::insertAtStart(int data){
    node * n = new node;
    if(start!=nullptr){
        start->prev=n;
        n->next=start;
        start=n;
        n->item=data;
        n->prev=nullptr;
    }
    else{
        n->prev=nullptr;
        n->item=data;
        n->next=nullptr;
        start=n;
     }
}
void CDLL::insertAtLast(int data){
    node * n = new node;
    if(start==nullptr)
         insertAtStart(data);
    else{
       start->prev->next=n;
       start->prev=n->next;
       n->item=data;    
    }
}
node * CDLL::search(int data){
    node * temp = start;
    while(temp->next!=start->prev){
        if(temp->item==data)
            return temp;
        temp=temp->next;    
    }
    return nullptr;
}
void CDLL::insertNode(node * nod,int data){
    node * temp = start;
    node * temp2 = start;
    node * n = new node;
    if(nod->next!=nullptr){
    while(temp->next!=start->prev){
        if(temp==nod){
            n->next=temp->next;
            temp->next=n;
            n->prev=temp;
        }
        temp = temp->next;
    }
 }
 else{
    insertAtLast(data);
 }
}
void CDLL::deleteFirst(){
    if(start!=nullptr){
        node * temp = start;
        start=temp->next;
        temp->next->prev=temp->prev;
        delete temp;
    }
}
void CDLL::deletelast(){
    node * temp = start;
    if(start!=nullptr){
        while(temp->next->next!=nullptr)
            temp=temp->next;
        delete temp->next;
        start->prev=temp;
        }
}