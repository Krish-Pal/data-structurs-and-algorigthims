#include<iostream>
using namespace std;
#define ssl_underflow 1;
struct node{
    int item;
    node * next;
};
class SSL{
    private:
        node * start;
    public:
        SSL();
        ~SSL();
        void insertAtStart(int);
        void inserAtEnd(int);
        node *search(int);
        void insertAfter(node *,int);
        void deletefirst();
        void deletelast();
        void deletenode(node *);
};
SSL::SSL(){
    start=nullptr;
}
SSL::~SSL(){

    while(start!=nullptr)
        deletelast();
}
void SSL::insertAtStart(int data){
    node *n = new node;
    n->item=data;
    n->next=start;
    start=n;
}
void SSL::inserAtEnd(int data){
    node * n = new node;
    n->item=data;
    node * temp = start;
        while(temp->next!=nullptr)
            temp=temp->next;
    temp->next=n;
    n->next=nullptr;
}
node *SSL::search(int data){
    node * temp=start;
    if(start==nullptr)
        return nullptr;
    while(temp->next!=nullptr){
        if(temp->item==data)
            return temp;
        temp=temp->next;
    }
    return nullptr;
}
void SSL::insertAfter(node *t,int data){
    node *n = new node;
    node * temp = start;
    while(temp->next!=nullptr){
        if(temp==t){
            n->next=temp->next;
            temp->next=n;
        }
    }
    throw ssl_underflow;
}
void SSL::deletefirst(){
    node * temp = start;
    start = start->next;
     delete temp;
}
void SSL::deletelast(){
    node *temp=start;
    node *temp2;
    if(start==nullptr)
        throw ssl_underflow;
    while(temp->next->next!=nullptr){
        temp=temp->next;
        temp2=temp->next;
    }
    temp->next=nullptr;
    delete temp2;
}
void SSL::deletenode(node * n){
    if(start==nullptr)
     throw ssl_underflow;
    node *temp=start;
    node *temp2;
    while(temp->next!=nullptr){
        temp=temp->next;
        temp2=temp->next;
        if(temp->next==n){
            temp->next=temp2->next;
            delete temp2;
        }
    }
    throw ssl_underflow;
}
