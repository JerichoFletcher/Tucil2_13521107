#include <struct/vec/VectorList.hpp>
#include <struct/vec/Vector.hpp>
#include <struct/exc/Exception.hpp>
#include <util/Random.hpp>
#include <cmath>

// PARAM CTOR
VectorList::VectorList(int size, int dimension){
    if(size < 0)throw new InvalidArgException("size must be non-negative");
    this->size = size;
    this->dimension = dimension;
    buffer = new Vector*[size];
}

// DTOR
VectorList::~VectorList(){
    for(int i = 0; i < size; ++i)delete buffer[i];
    delete[] buffer;
}

// Generates a list of random vectors
VectorList* VectorList::randomOfSize(int size, int dimension){
    VectorList* list = new VectorList(size, dimension);
    for(int i = 0; i < size; ++i){
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

// Finds the closest pair of vectors by brute force
VectorPair* VectorList::closestPairBf(){
    VectorPair* d = NULL;
    for(int i = 0; i < size; ++i){
        for(int j = 0; j < size; ++j){
            if(i == j)continue;
            VectorPair* d1 = new VectorPair(buffer[i], buffer[j]);
            if(!d || *d1 < *d){
                delete d;
                d = d1;
            }
        }
    }
    return d;
}

// Closest pair by DnC function kickoff
VectorPair* VectorList::closestPairDnc(){
    sort();
    closestPairDnc(0, size-1);
}

// Finds the closest pair of vectors in this list from index i through j, using the divide-and-conquer strategy
VectorPair* VectorList::closestPairDnc(int i, int j){
    //cout << "will compute " << i << "-" << j << ", ";
    if(j - i < 1){
        //cout << "null case" << endl;
        return NULL;
    }else if(j - i == 1){
        //cout << "two case" << endl;
        return new VectorPair(buffer[i], buffer[j]);
    }else{
        //cout << "many case," << endl;
        int k = (i+j)/2;
        VectorPair
            *d1 = closestPairDnc(i, k),
            *d2 = closestPairDnc(k+1, j),
            *d;
        
        if(d1 && !d2){
            d = d1;
            delete d2;
        }else if(!d1 && d2){
            d = d2;
            delete d1;
        }else{
            if(*d1 < *d2){
                d = d1;
                delete d2;
            }else{
                d = d2;
                delete d1;
            }
        }

        // Search for closest pair within d of midpoint
        double mid = loDistance(k, k+1);
        int
            p = i,
            q = j;
        
        //cout << "current distance " << loDistance(p, mid) << " vs " << d->distance() << endl;
        while(p < k && loDistance(p, mid) > d->distance())++p;
        while(q > k+1 && loDistance(q, mid) > d->distance())--q;
        //cout << "about to compute " << i << "[" << p << "-" << q << "]" << j << endl;

        for(int u = p; u <= k; ++u){
            for(int v = q; v >= k+1; --v){
                //cout << "compute " << u << " " << v;
                if(dimension > 1 && maxDistance(u, v) > d->distance())continue;
                VectorPair* d3 = new VectorPair(buffer[u], buffer[v]);
                //cout << " dist " << d3->distance() << " vs " << d->distance() << endl;
                
                if(*d3 < *d){
                    delete d;
                    d = d3;
                }else{
                    delete d3;
                }
            }
        }

        //cout << "finished compute " << i << "-" << j << endl;
        return d;
    }
}

// Returns the lowest-order-dimension distance between the i-th and j-th vector
double VectorList::loDistance(int i, int j) const{
    if(i < 0 || size <= i || j < 0 || size <= j){
        throw new OutOfRangeException("vector list buffer");
    }else{
        return abs((*buffer[j])[0] - (*buffer[i])[0]);
    }
}

// Returns the lowest-order-dimension distance from the i-th vector to a real number d
double VectorList::loDistance(int i, double d) const{
    if(i < 0 || size <= i){
        throw new OutOfRangeException("vector list buffer");
    }else{
        return abs(d - (*buffer[i])[0]);
    }
}

// Returns the maximum distance across all dimensions between the i-th and j-th vector
double VectorList::maxDistance(int i, int j) const{
    double dist = loDistance(i, j);
    if(dimension == 1)return dist;
    for(int p = 1; p < dimension; ++p){
        double newDist = abs((*buffer[j])[p] - (*buffer[i])[p]);
        if(newDist > dist)dist = newDist;
    }
    return dist;
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
    for(int i = 0; i < d; ++i){
        os << i << ": " << list[i];
        if(i < d-1)os << endl;
    }
    return os;
}
