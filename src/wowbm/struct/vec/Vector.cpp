#include <struct/vec/Vector.hpp>
#include <struct/exc/Exception.hpp>
#include <iostream>
#include <cmath>

int Vector::distComputeCount = 0;

// PARAM CTOR
Vector::Vector(int dimension){
    if(dimension < 1)throw new InvalidArgException("dimension must be positive");
    this->dimension = dimension;
    components = new double[dimension];
}

// CCTOR
Vector::Vector(const Vector& other){
    dimension = other.dimension;
    components = new double[dimension];
    for(int i = 0; i < dimension; i++)
        components[i] = other[i];
}

// DTOR
Vector::~Vector(){
    delete[] components;
}

// Component setter
void Vector::setComponent(int axis, double value){
    if(axis < 0 || dimension <= axis){
        throw new OutOfRangeException("vector component");
    }else{
        components[axis] = value;
    }
}

// Dimension getter
int Vector::getDimension() const{
    return dimension;
}

// Operator =
Vector& Vector::operator=(const Vector& other){
    delete[] components;
    dimension = other.dimension;
    components = new double[dimension];
    for(int i = 0; i < dimension; i++)
        components[i] = other[i];
    return *this;
}

// Operator []
double& Vector::operator[](int axis) const{
    if(axis < 0 || dimension <= axis){
        throw new OutOfRangeException("vector component");
    }else{
        return components[axis];
    }
}

// Comparison function, returns 1 if A>B, -1 if A<B, 0 if A=B
int Vector::compare(const Vector& other) const{
    if(getDimension() != other.getDimension()){
        throw new InvalidArgException("vector dimension mismatch");
    }
    int idx = 0;
    while(idx < dimension){
        double
            a = (*this)[idx],
            b = other[idx];
        
        if(a > b){
            return 1;
        }else if(a < b){
            return -1;
        }else{
            ++idx;
        }
    }
    return 0;
}

// Returns Euclidean distance squared between v1 and v2
double Vector::distanceSqr(const Vector& v1, const Vector& v2){
    if(v1.getDimension() != v2.getDimension()){
        throw new InvalidArgException("vector dimension mismatch");
    }else{
        double sum = 0;
        for(int i = 0; i < v1.getDimension(); i++){
            double d = v2[i] - v1[i];
            sum += d * d;
        }
        return sum;
    }
}

// Returns Euclidean distance between v1 and v2
double Vector::distance(const Vector& v1, const Vector& v2){
    ++distComputeCount;
    double d = distanceSqr(v1, v2);
    return d >= 0 ? sqrt(d) : d;
}

// Print to stream function
ostream& operator<<(ostream& os, const Vector& v){
    os << "(";
    int d = v.getDimension();
    for(int i = 0; i < d; i++){
        os << v[i];
        if(i < d-1)os << ", ";
    }
    os << ")";
    return os;
}
