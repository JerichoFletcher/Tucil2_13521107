#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
using namespace std;

class Vector{
    public:
        Vector();
        Vector(int dimension);
        Vector(const Vector& other);
        ~Vector();

        void setComponent(int axis, double value);
        int getDimension() const;

        Vector& operator=(const Vector& other);
        double& operator[](int axis) const;
        int compare(const Vector& other) const;

        static double distanceSqr(const Vector& v1, const Vector& v2);
        static double distance(const Vector& v1, const Vector& v2);
    
        friend ostream& operator<<(ostream& os, const Vector& v);

    private:
        int dimension;
        double* components;

        static int distComputeCount;
};

#endif
