#include<iostream>
using namespace std;
#define invalid_size 1
class DynArray{
    private:
        int capacity;
        int  last_index;
        int *ptr; 
    public:
        DynArray(int);
        void doubleArray(int,int&);

};
DynArray::DynArray(int size){

    capacity=size;
    if(size<=0)
        throw invalid_size; 
    ptr=new int[size];
    last_index=-1;
}
void DynArray::doubleArray(int size,int &ptr){ 
    capacity=size;
    last_index=size-1;
    if(size<=0)
        throw invalid_size;
    int *temp=new int[size*2];
    for(int i=0;i<=last_index;i++){
        temp[i]=ptr[i];
    }
    delete []ptr;
        ptr=temp;
    capacity=size*2;
}
int main(){
 DynArray d1(0);
}
