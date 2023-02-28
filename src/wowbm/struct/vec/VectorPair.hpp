#ifndef VECTOR_PAIR_HPP
#define VECTOR_PAIR_HPP

#include <struct/vec/Vector.hpp>
#include <iostream>
#include <fstream>
using namespace std;

class VectorPair{
    public:
        VectorPair(Vector& v1, Vector& v2, int i, int j);
        VectorPair(Vector* v1, Vector* v2, int i, int j);

        Vector V1() const;
        Vector V2() const;
        int I() const;
        int J() const;
        double distance() const;

        bool operator<(const VectorPair& other) const;
        ostream& writeToFile(ostream& file) const;
        friend ostream& operator<<(ostream& os, const VectorPair& vecpair);

    private:
        Vector* v1;
        Vector* v2;
        int i;
        int j;
        double dist;
};

#endif
