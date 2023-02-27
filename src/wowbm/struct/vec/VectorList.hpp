#ifndef VECTOR_LIST_HPP
#define VECTOR_LIST_HPP

#include <struct/vec/Vector.hpp>
#include <iostream>
#include <vector>
using namespace std;

class VectorList{
    public:
        VectorList(int size, int dimension);
        ~VectorList();
        static VectorList* randomOfSize(int size, int dimension);

        int getSize() const;

        void sort();
        Vector* operator[](int idx);
        const Vector operator[](int idx) const;

        friend ostream& operator<<(ostream& os, const VectorList& list);

    private:
        void sort(int i, int j);
        int partition(int i, int j);

        int size;
        int dimension;
        Vector** buffer;
};

#endif
