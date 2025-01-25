#include<iostream>
using namespace std;
#define invalid_capacity 1
#define array_not_created 2
#define not_empty 3
#define invalid_index 4

class DynArray{
    private:
        int capacity;
        int  last_index;
        int *ptr; 
    protected:
        void doubleArray();
        void halfArray();
    public:
        DynArray(int);
        DynArray();
        void createArray(int);
        int current_capacity(int);
        bool isempty();
        bool isfull();
        void append(int);
        void insert(int,int);
        void del(int);
        int find(int);
        ~DynArray();
        int count_elements();

};
DynArray::DynArray(){
    capacity=1;
    last_index=-1;
    ptr=new int[capacity];
}
DynArray::DynArray(int size){
    capacity=size;
    if(size<0)
        throw invalid_capacity; 
    ptr=new int[size];
    last_index=-1;
}
DynArray::~DynArray(){
    delete []ptr;
}
int DynArray::count_elements(){
    return last_index+1;
}
int DynArray::find(int element){

    for(int i=0;i<=last_index;i++){
        if(ptr[i]==element)
            return i;
    }
    return -1;
}
void DynArray::insert(int index,int data){
    if(index<0 || index>last_index+1)
        throw invalid_index;
    if(isfull())
        doubleArray();
        for(int i=last_index;i>=index;i--)
            ptr[i+1]=ptr[i];
    ptr[index]=data;
}
void DynArray::del(int index){
      if(index<0 || index>last_index+1)
        throw invalid_index;
      for(int i=index;i<=last_index;i++){
            ptr[i]=ptr[i+1];
      }
      last_index--;
      if(capacity>1 && (last_index+1==capacity/2))
        halfArray();

}
void DynArray::append(int data){
    if(ptr==nullptr)
        throw array_not_created;
    if(!isempty())
        doubleArray();
    last_index++;
    ptr[last_index+1]=data;
    
}
void DynArray::doubleArray(){ 
    int *temp=new int[capacity*2];
    for(int i=0;i<=last_index;i++){
        temp[i]=ptr[i];
    }   
    delete []ptr;
        ptr=temp;
    capacity*=2;
}
void DynArray::halfArray(){
    int *temp = new int [capacity/2];
    for(int i=0;i<=last_index;i++)
        temp[i]=ptr[i];
    delete []ptr;
     ptr=temp;
     capacity/=2;  
} 
void DynArray::createArray(int size){
    if(ptr==nullptr){
        if(size<1)
        throw invalid_capacity;
        ptr=new int[size];
        capacity=size;
        last_index=-1;
        ptr = new int[capacity];
    }
    else{
        if(size<1)
            throw invalid_capacity;
            delete []ptr;
    }
}
int DynArray::current_capacity(int size){
    capacity=size;
    return capacity;
}
bool DynArray::isempty(){
    
    return last_index+1>capacity;
}
bool DynArray::isfull(){
    
    return last_index+1==capacity;
}
int main(){
 DynArray d1(0);
}
