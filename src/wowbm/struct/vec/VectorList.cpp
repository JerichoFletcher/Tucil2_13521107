#include <struct/vec/VectorList.hpp>
#include <struct/vec/Vector.hpp>
#include <struct/exc/Exception.hpp>
#include <util/Random.hpp>
#include <algorithm>

// PARAM CTOR
VectorList::VectorList(int size, int dimension){
    if(size < 0)throw new InvalidArgException("size must be non-negative");
    this->size = size;
    this->dimension = dimension;
    buffer = new Vector*[size];
}

// DTOR
VectorList::~VectorList(){
    for(int i = 0; i < size; i++)delete buffer[i];
    delete[] buffer;
}

// Generates a list of random vectors
VectorList* VectorList::randomOfSize(int size, int dimension){
    VectorList* list = new VectorList(size, dimension);
    for(int i = 0; i < size; i++){
        list->buffer[i] = Random::nextVector(dimension);
    }
    return list;
}

// Size getter
int VectorList::getSize() const{
    return size;
}

// Sort function kickoff
void VectorList::sort(){
    sort(0, size-1);
}

// Operator []
Vector* VectorList::operator[](int idx){
    if(idx < 0 || size <= idx){
        throw new OutOfRangeException("vector list buffer");
    }else{
        return buffer[idx];
    }
}

// Operator [] constant
const Vector VectorList::operator[](int idx) const{
    if(idx < 0 || size <= idx){
        throw new OutOfRangeException("vector list buffer");
    }else{
        return *(buffer[idx]);
    }
}

// Print to stream function
ostream& operator<<(ostream& os, const VectorList& list){
    int d = list.getSize();
    for(int i = 0; i < d; i++){
        os << i << ": " << list[i];
        if(i < d-1)os << endl;
    }
    return os;
}

// Quicksorts the list from index i through j
void VectorList::sort(int i, int j){
    if(i < 0 || j < 0 || i >= j)return;
    
    int k = partition(i, j);
    sort(i, k);
    sort(k+1, j);
}

// Partitions the list into 2 subdivisions and returns the pivot index
int VectorList::partition(int i, int j){
    Vector& pivot = *(buffer[(i+j)/2]);
    int
        p = i,
        q = j;
    while(true){
        while(buffer[p]->compare(pivot) < 0)++p;
        while(buffer[q]->compare(pivot) > 0)--q;

        if(p >= q)return q;
        Vector* temp = buffer[p];
        buffer[p] = buffer[q];
        buffer[q] = temp;
    }
}
