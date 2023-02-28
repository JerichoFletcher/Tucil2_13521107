#ifndef VECTOR_LIST_HPP
#define VECTOR_LIST_HPP

#include <struct/vec/Vector.hpp>
#include <struct/vec/VectorPair.hpp>
#include <iostream>
#include <fstream>
using namespace std;

class VectorList{
    public:
        static VectorList* randomOfSize(int size, int dimension);
        static VectorList* fromFile(const char* path);

        VectorList(int size, int dimension);
        ~VectorList();

        int getSize() const;

        void sort();
        VectorPair* closestPairBf();
        VectorPair* closestPairDnc();

        double loDistance(int i, int j) const;
        double loDistance(int i, double d) const;
        double maxDistance(int i, int j) const;
        Vector* operator[](int idx);
        const Vector operator[](int idx) const;

        ostream& writeToFile(ostream& file) const;
        friend ostream& operator<<(ostream& os, const VectorList& list);

    private:
        int size;
        int dimension;
        Vector** buffer;

        void sort(int i, int j);
        int partition(int i, int j);
        VectorPair* closestPairDnc(int i, int j);
};

#endif
