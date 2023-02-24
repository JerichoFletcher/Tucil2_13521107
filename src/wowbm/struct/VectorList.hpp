#ifndef VECTOR_LIST_HPP
#define VECTOR_LIST_HPP

#include <struct/Vector.hpp>
#include <iostream>
using namespace std;

class VectorList{
    public:
        VectorList(int size, int dimension);
        ~VectorList();
        static VectorList* randomOfSize(int size, int dimension);

        int getSize() const;
        void setVector(int idx, Vector* v);

        void sort();
        Vector& operator[](int idx) const;

        friend ostream& operator<<(ostream& os, const VectorList& list);

    private:
        int size;
        int dimension;
        Vector** buffer;

        void sort(int x, int y);
};

#endif
