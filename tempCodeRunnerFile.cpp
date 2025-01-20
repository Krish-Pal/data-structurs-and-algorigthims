#include<iostream>
using namespace std;
#define null 0;
#define capacity_invalid 1;
 class Array{
    private:
    int capacity;
    int lastIndex;
    int *ptr;
    public:
    Array(int);
};
Array::Array(int size){
    ptr=nullptr;
    if(size<1)
      throw capacity_invalid;


    ptr=new int[size];

}
int main(){
    Array a1(4);
}