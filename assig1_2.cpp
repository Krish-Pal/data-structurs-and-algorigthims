#include<iostream>
using namespace std;
#define invalid_capacity 1;
 class Array{
    private:
        int capacity;
        int lastIndex;
        int *ptr;
    public:
        Array(int);
        void createArray(int);
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
int main(){
    Array a1(4);
}
