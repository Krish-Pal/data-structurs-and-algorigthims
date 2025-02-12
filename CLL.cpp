#include<iostream>
using namespace std;
#define CLL_Overflow 1;
struct node{
    int item;
    node *next;
};
class CLL{
    private:
        node * last;
    public:
        CLL();
        ~CLL();
        void insertAtStart(int);
        void insertAtLast(int);
        node *search(int);
        void insertNode(int,node *);
        void deleteFirst();
        void deleteLast();
        void deleteNode(int);
};
CLL::CLL(){
    last=nullptr;
}
CLL::~CLL(){
    node * temp = last->next;
    if(temp!=last)
        deleteFirst();
}
void CLL::insertAtStart(int data){
    node * n = new node;
    n->next=last->next;
    n->item=data;
    last->next=n;
}
void CLL::insertAtLast(int data){
    node * n = new node;
    n->next=last->next;
    last->next=n;
    n->item=data;
    last=n;
}
node * CLL::search(int data){
    node * temp = last->next;
    while(temp!=last){
        if(temp->item==data)
            return temp;
        temp=temp->next;
    }
    return nullptr;
}
void CLL::insertNode(int data,node * nod){
    node * temp = last->next;
    node * n = new node;
    while(temp!=last){
        if(temp==nod){
            n->next=temp->next;
            temp->next=n;
        }
   }
    throw CLL_Overflow;
}
void CLL::deleteFirst(){
    node * temp = last->next;
    temp=last->next;
    last=temp->next;
    delete temp;
}
void CLL::deleteLast(){
    node * temp = last->next;
    node * temp2 = last->next;
    while(temp->next!=last){
        temp=temp->next;
    }
    last=temp;
    last->next=temp2;
    delete temp->next;
}
void CLL::deleteNode(int data){
    node * temp = last->next;
    node * temp2 = last->next;
    while(temp!=last){
        if(temp->item==data){
            while(temp2->next->item!=data){
                    temp2=temp2->next;
            }
            temp2->next=temp->next;
            delete temp;
             break;
        }
        temp=temp->next;
    }
    throw CLL_Overflow;
}