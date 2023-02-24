#include <struct/VectorList.hpp>
#include <struct/Vector.hpp>
#include <struct/exc/Exception.hpp>
#include <util/Random.hpp>

// PARAM CTOR
VectorList::VectorList(int size, int dimension){
    if(size < 0)throw new Exception("Invalid argument: size must be non-negative");
    this->size = size;
    this->dimension = dimension;
    buffer = new Vector*[size];
}

// DTOR
VectorList::~VectorList(){
    for(int i = 0; i < size; i++){
        delete buffer[i];
    }
    delete[] buffer;
}

// Generates a list of random vectors
VectorList* VectorList::randomOfSize(int size, int dimension){
    VectorList* list = new VectorList(size, dimension);
    for(int i = 0; i < size; i++){
        list->setVector(i, Random::nextVector(dimension));
    }
    return list;
}

// Size getter
int VectorList::getSize() const{
    return size;
}

// Vector element getter
void VectorList::setVector(int idx, Vector* v){
    if(idx < 0 || size <= idx){
        throw new Exception("Index out of range");
    }else{
        buffer[idx] = v;
    }
}

// Sort function kickoff
void VectorList::sort(){

}

// Operator []
Vector& VectorList::operator[](int idx) const{
    if(idx < 0 || size <= idx){
        throw new Exception("Index out of range");
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
