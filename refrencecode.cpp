#include<iostream>
using namespace std;
#define INVALID_CAPACITY 1;
class Array{
    private:
    int capacity,last_index,*ptr;
    public:
    Array(int);
    };
Array::Array(int size){
        ptr= nullptr;
        if(size<1)
            throw INVALID_CAPACITY;
        last_index=-1;
        capacity=size;
        if(capacity=last_index-1)
        ptr=new int [size];
    }
int main(){
    Array a1(5);
}
