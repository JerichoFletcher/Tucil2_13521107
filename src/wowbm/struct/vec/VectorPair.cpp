#include <struct/vec/VectorPair.hpp>

VectorPair::VectorPair(Vector& v1, Vector& v2, int i, int j){
    this->v1 = &v1;
    this->v2 = &v2;
    this->i = i;
    this->j = j;
    dist = Vector::distance(v1, v2);
}

VectorPair::VectorPair(Vector* v1, Vector* v2, int i, int j){
    this->v1 = v1;
    this->v2 = v2;
    this->i = i;
    this->j = j;
    dist = Vector::distance(*v1, *v2);
}

Vector VectorPair::V1() const{
    return *v1;
}

Vector VectorPair::V2() const{
    return *v2;
}

int VectorPair::I() const{
    return i;
}

int VectorPair::J() const{
    return j;
}

double VectorPair::distance() const{
    return dist;
}

bool VectorPair::operator<(const VectorPair& other) const{
    return distance() < other.distance();
}

ostream& VectorPair::writeToFile(ostream& file) const{
    file << i << " " << j;
    return file;
}

ostream& operator<<(ostream& os, const VectorPair& vecpair){
    os << "{" << *vecpair.v1 << ", " << *vecpair.v2 << "}: " << vecpair.dist;
    return os;
}
