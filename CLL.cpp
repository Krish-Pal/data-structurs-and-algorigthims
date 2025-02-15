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
        void insertAtStart(int);
        void insertAtLast(int);
        node *search(int);
        void insertAfter(int,node*);
        void deleteFirst();
        void deleteLast();
        void deleteNode(int);
        ~CLL();
};
CLL::CLL(){
    last=nullptr;
}
CLL::~CLL(){
    while(last!=nullptr)
        deleteFirst();
}
void CLL::insertAtStart(int data){
    node * n = new node;
    if(last==nullptr){
    n->next=n;
    last=n;
    }
    else{
        n->next=last->next;
        last->next=n;
    }
}
void CLL::insertAtLast(int data){
    node * n = new node;
    if(last==nullptr){
    n->next=n;
    last=n;
    }
    else{
        n->next=last->next;
        last->next=n;
        last=n;
    }
}
node * CLL::search(int data){
    if(last==nullptr)
        return nullptr;
    node * temp;
    temp = last->next;
    do{
        if(temp->item==data)
            return temp;
        temp=temp->next;
    }while(temp!=last->next);
        return nullptr;
}
void CLL::insertAfter(int data,node * nod){
    if(nod!=nullptr){
        node *n = new node;
        n->item=data;
        n->next=nod->next;
        nod->next=n;
        if(nod==last)
            last=n;
    }
}
void CLL::deleteFirst(){
    if(last!=nullptr){
        if(last->next==last){
            delete last;
            last=nullptr;
        }
        else{
            node * temp;
            temp=last->next;
            last->next=temp->next;
            delete temp;
        }
    }
    

}
void CLL::deleteLast(){
    if(last!=nullptr){
        if(last->next==last){
            delete last;
            last=nullptr;
        }
        else{
            node * temp;
            temp=last->next;
            while(temp->next!=last)
                temp=temp->next;
            temp->next=last->next;
            delete temp;
            last=temp;
        }
    }
}
void CLL::deleteNode(int data){
    node* r= search(data);
    if(r!=nullptr){
        if(r==last->next)
            deleteFirst();
        else if(r==last)
            deleteLast();
        else{
            node *temp=last->next;
            while(temp->next!=r)
                temp=temp->next;
            temp->next=r->next;
                delete r;
        }
    }
}