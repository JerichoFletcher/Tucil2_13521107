#include <struct/vec/VectorList.hpp>
#include <struct/vec/Vector.hpp>
#include <struct/exc/Exception.hpp>
#include <util/Random.hpp>
#include <algorithm>

// PARAM CTOR
VectorList::VectorList(int size, int dimension){
    if(size < 0)throw new Exception("Invalid argument: size must be non-negative");
    this->size = size;
    this->dimension = dimension;
    buffer = vector<Vector>();
}

// DTOR
VectorList::~VectorList(){}

// Generates a list of random vectors
VectorList* VectorList::randomOfSize(int size, int dimension){
    VectorList* list = new VectorList(size, dimension);
    for(int i = 0; i < size; i++){
        list->buffer.push_back(Random::nextVector(dimension));
    }
    return list;
}

// Size getter
int VectorList::getSize() const{
    return size;
}

// Vector element getter
void VectorList::setVector(int idx, Vector v){
    if(idx < 0 || size <= idx){
        throw new Exception("Index out of range");
    }else{
        buffer[idx] = v;
    }
}

// Sort function
void VectorList::sort(){
    std::sort(buffer.begin(), buffer.end(), [](const Vector& v1, const Vector& v2){
        if(v1.getDimension() != v2.getDimension()){
            throw new Exception("Invalid argument: vector dimension mismatch");
        }else{
            for(int i = 0; i < v1.getDimension(); i++){
                double
                    a = v1[i],
                    b = v2[i];
                if(a != b)return a < b;
            }
            return false;
        }
    });
}

// Operator []
Vector& VectorList::operator[](int idx){
    if(idx < 0 || size <= idx){
        throw new Exception("Index out of range");
    }else{
        return buffer[idx];
    }
}

// Operator [] constant
const Vector VectorList::operator[](int idx) const{
    if(idx < 0 || size <= idx){
        throw new Exception("Index out of range");
    }else{
        return buffer[idx];
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
