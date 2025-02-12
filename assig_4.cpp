#include<iostream>
using namespace std;
#define link_list_underflow 1
#define unspecified_node 2
struct node{
    int item;
    node *next;
};
class SSL{
    private:
        node *start;
    public:
        SSL();
       ~SSL();
        void insertAtStart(int);
        void insertAtLast(int);
        node *search(int);
        void insertAfter(int,node *);
        void deleteFirst();
        void deleteLast();
        void deleteAfter(int);
};
SSL::SSL(){
    start=nullptr;
}
SSL::~SSL(){
    while(start!=nullptr){
        deleteFirst();
    }
}
void SSL::insertAtStart(int data){
       node * n = new node;
       n->next=start;
       n->item=data;
       start=n;
   }
void SSL::insertAtLast(int data){
     node * n = new node;
     n->item=data;
     n->next=nullptr;

    if(start==nullptr)
        start=n;
    else{
        node * temp=start;
    while(temp->next!=nullptr)
        temp=temp->next;
    temp->next=n;
    }
   }
node* SSL::search(int data){
    if(start==nullptr)
        return nullptr;
    node * temp = start;
    while(temp!=nullptr){
        if(temp->item==data)
            return temp;
        else
            temp=temp->next;
    }
        return nullptr;
}
void SSL::insertAfter(int data,node * nod){
    if(nod!=nullptr){
        node *n=new node;
        n->item=data;
        n->next=nod->next;
        nod->next=n;
    }
}
void SSL::deleteFirst(){
    if(start==nullptr)
        throw link_list_underflow;
    else
    {
        node *temp=start;
        start=start->next;
        delete temp;
    }
}
void SSL::deleteLast(){

    if(start==nullptr)
        throw link_list_underflow;
    if(start->next==nullptr){
         delete start;
         start=nullptr;
    }
    else{
        node *temp=start;
        while(temp->next->next!=nullptr){
            temp=temp->next;
        }
        delete temp->next;
        temp->next=nullptr;
    }
    node * n = new node;
    node * temp = start;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
}
void SSL::deleteAfter(int data){
    if(start==nullptr)
        throw link_list_underflow;
    node *t1,*t2;
        t1=start;
        t2=nullptr;
    while(t1!=nullptr){
        if(t1->item==data)
            break;
        t2=t1;
        t1=t1->next;
    }
    if(t2==nullptr)
        deleteFirst();
    if(t1!=nullptr){
        t2->next=t1->next;
        delete t1;
    }
    }