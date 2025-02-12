#include<iostream>
using namespace std;
#define DLL_under_flow 1;
struct node{
    node *prev;
    int item;
    node *next;
};
class DLL{
    private:
        node * start;
    public:
        DLL();
        ~DLL();
        void insertAtStart(int);
        void insertAtLast(int);
        node *search(int);
        void insertAfter(node *,int );
        void deletefirst();
        void deletelast();
        void deletenode(int);
};
DLL::DLL(){
    start=nullptr;
}
DLL::~DLL(){
    while(start!=nullptr){
        deletefirst();
    }
}
void DLL::insertAtStart(int data){
    node * n = new node;
    n->next = start;
    n->item = data;
    n->prev = nullptr;
    if(start!=nullptr)
        start->prev=n;
    start = n;
}
void DLL::insertAtLast(int data){
    node * n = new node;
    node * temp = start;
    while(temp->next!=nullptr){
        temp = temp->next;
    }
    temp->next = n;
    n->item = data;
    n->prev = temp;
    n->next = nullptr;
}
node *DLL::search(int data)
{
    if(start!=nullptr){
        node * temp=start;
        while(temp->next!=nullptr){
            if(temp->item==data)
                return temp;
            temp=temp->next;
        }
        return nullptr;
        
    }

}
void DLL::insertAfter(node * t,int data){
    if(t->next!=nullptr){
        node *n = new node;
        node * temp = start;
        while(temp->next!=nullptr){
            if(temp==t){
                n->next=temp->next;
                temp->next=n;
                n->prev=temp;
               if(temp->next!=nullptr)
                    temp->next->prev=n;
            }
            temp=temp->next;
        }
    }
    if(t->next==nullptr){
        void insertAtLast(int data);
    }
}
void DLL::deletefirst(){
    if(start!=nullptr){
        node * temp = start;
        start=temp->next;
        temp->next->prev=nullptr;
        delete temp;
    }
    
}
void DLL::deletelast(){
    if(start!=nullptr){
        node * temp = start;
        while(temp->next->next!=nullptr){
            temp=temp->next;
        }
        temp->next=nullptr;
        delete temp->next;
    }
}
void DLL::deletenode(int data){
    if(start!=nullptr){
        node * temp = start;
            while(temp->next!=nullptr){
                if(temp->item==data){
                    temp->prev->next=temp->next;
                    delete temp;
                    break;
                }
                temp=temp->next;
            }
            if(temp->next==nullptr){
                throw DLL_under_flow;
            }
    }
}