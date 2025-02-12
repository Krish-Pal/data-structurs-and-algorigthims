#include<iostream>
using namespace std;

#define invalid_capacity 1
#define array_not_created 2
#define array_overflow 3
#define IndexInvalid 4

class Array {
    private:
        int capacity;
        int lastIndex;
        int *ptr;
    public:
        Array(int);
        void createArray(int);
        bool isempty();
        void append(int);
        bool is_full();
        void insert(int, int);
        void edit(int, int);
        void del(int);
        int get(int);
        int count();
        virtual ~Array();
        int find(int);
};

Array::Array(int size) {
    ptr = nullptr;
    if (size < 1)
        throw invalid_capacity;
    capacity = size;
    lastIndex = -1;
    ptr = new int[capacity];
}

void Array::createArray(int size) {
    if (ptr == nullptr) {
        if (size < 1)
            throw invalid_capacity;
        capacity = size;
        lastIndex = -1;
        ptr = new int[capacity];
    } else {
        if (size < 1)
            throw invalid_capacity;
        delete[] ptr;
        ptr = new int[capacity];
    }
}

bool Array::isempty() {
    if (ptr == nullptr)
        throw array_not_created;
    return lastIndex == -1;
}

void Array::append(int data) {
    if (ptr == nullptr)
        throw array_not_created;
    if (is_full())
        throw array_overflow;
    lastIndex++;
    ptr[lastIndex] = data;
}

bool Array::is_full() {
    if (ptr == nullptr)
        throw array_not_created;
    return capacity == lastIndex + 1;
}

void Array::insert(int data, int index) {
    if (ptr == nullptr)
        throw array_not_created;
    if (is_full())
        throw array_overflow;
    if (index < 0 || index > lastIndex + 1)
        throw IndexInvalid;
    for (int i = lastIndex; i >= index; i--)
        ptr[i + 1] = ptr[i];
    ptr[index] = data;
    lastIndex++;
}

void Array::edit(int NewData, int index) {
    if (ptr == nullptr)
        throw array_not_created;
    if (index < 0 || index > lastIndex)
        throw IndexInvalid;
    ptr[index] = NewData;
}

void Array::del(int index) {
    if (index < 0 || index >= lastIndex)
        throw IndexInvalid;
    for (int i = index; i < lastIndex; i++)
        ptr[i] = ptr[i + 1];
    lastIndex--;
}

int Array::get(int index) {
    if (ptr == nullptr)
        throw array_not_created;
    if (index < 0 || index > lastIndex)
        throw IndexInvalid;
    return ptr[index];
}

int Array::count() {
    if (lastIndex < 0 || capacity < lastIndex)
        throw IndexInvalid;
    if (ptr == nullptr)
        throw array_not_created;
    return lastIndex + 1;
}

Array::~Array() {
    if (ptr != nullptr)
        delete[] ptr;
}

int Array::find(int data) {
    if (ptr == nullptr)
        throw array_not_created;
    for (int i = 0; i <= lastIndex; i++) {
        if (ptr[i] == data)
            return i;
    }
    return -1;
}

int main() {
    Array a1(4);
    // Add test cases to verify the functionality of the Array class
}