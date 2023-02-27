#include <iostream>
#include <struct/vec/Vector.hpp>
#include <struct/vec/VectorList.hpp>
#include <struct/vec/VectorPair.hpp>
#include <struct/exc/Exception.hpp>
using namespace std;

int main(){
    try{
        int n, k;
        cout << "Enter the number of points: ";
        cin >> n;
        cout << "Enter the number of axes: ";
        cin >> k;

        VectorList* list = VectorList::randomOfSize(n, k);

        VectorPair* pairBf = list->closestPairBf();
        int countBf = Vector::computeCount();
        Vector::resetComputeCount();

        VectorPair* pairDnc = list->closestPairDnc();
        int countDnc = Vector::computeCount();
        Vector::resetComputeCount();

        cout << endl;
        if(!pairBf){
            cout << "No pairs found by brute-force" << endl;
        }else{
            cout << "Closest pair found by brute-force:" << endl;
            cout << *pairBf << endl;
            cout << "Calculation done with " << countBf << " distance computations" << endl;
        }

        cout << endl;
        if(!pairDnc){
            cout << "No pairs found by divide-and-conquer" << endl;
        }else{
            cout << "Closest pair found by divide-and-conquer:" << endl;
            cout << *pairBf << endl;
            cout << "Calculation done with " << countDnc << " distance computations" << endl;
        }

        delete pairBf;
        delete pairDnc;
        delete list;
        
    }catch(exception* e){
        cout << "ERROR: " << e->what() << endl;
    }
    return 0;
}
