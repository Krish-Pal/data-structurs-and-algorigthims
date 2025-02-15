#include<iostream>
using namespace std;
class Stack{
    private:
        int capacity;
        int top;
        int * ptr;
    public:
        Stack(int,int,int *);
        void push(int);
};
Stack::Stack(int cap,int t,int *pointer){
    capacity=cap;
    top=t;
    ptr=pointer;
}
void Stack::push(int data){
    int * p = new int;
        *p=data;
}