#include<iostream>
using namespace std;
#define invalid_capacity 1
#define array_not_created 2
 class Array{
    private:
        int capacity;
        int lastIndex;
        int *ptr;
    public:
        Array(int);
        void createArray(int);
        bool isempty();
};
Array::Array(int size){
    ptr=nullptr;
    if(size<1)
        throw invalid_capacity;
    capacity = size;
    lastIndex=-1;
    ptr = new int [capacity];
    
}
void Array::createArray(int size){
    if(ptr==nullptr){
        if(size<1)
            throw invalid_capacity;
            if(size<1)
            throw invalid_capacity;
            capacity = size;
            lastIndex=-1;
            ptr = new int [capacity];
    
}
else{
    if(size<1)
    throw invalid_capacity;
    delete []ptr;
}
}
bool Array::isempty(){
    if(ptr==nullptr)
        throw array_not_created;
    return lastIndex=-1;
}
int main(){
    Array a1(4);
}
