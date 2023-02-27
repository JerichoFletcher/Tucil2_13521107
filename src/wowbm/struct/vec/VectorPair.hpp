#ifndef VECTOR_PAIR_HPP
#define VECTOR_PAIR_HPP

#include <struct/vec/Vector.hpp>
#include <iostream>
using namespace std;

class VectorPair{
    public:
        VectorPair(Vector& v1, Vector& v2);
        VectorPair(Vector* v1, Vector* v2);

        Vector V1() const;
        Vector V2() const;
        double distance() const;

        bool operator<(const VectorPair& other) const;
        friend ostream& operator<<(ostream& os, const VectorPair& vecpair);

    private:
        Vector* v1;
        Vector* v2;
        double dist;
};

#endif
