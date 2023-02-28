#include <iostream>
#include <fstream>
#include <string>
#include <struct/vec/Vector.hpp>
#include <struct/vec/VectorList.hpp>
#include <struct/vec/VectorPair.hpp>
#include <struct/exc/Exception.hpp>
#include <util/Timer.hpp>
using namespace std;

int main(int _argc, char* _argv[]){
    try{
        cout << "======================= WOW BEST MATCH =======================" << endl;

        VectorList* list = NULL;
#ifdef DEBUG
        VectorPair* pairBf = NULL;
        uint64_t timeBf;
        int countBf;
#endif
        VectorPair* pairDnc = NULL;
        uint64_t timeDnc;
        int countDnc;

        if(_argc == 1){
            int n, k;
            cout << "Enter the number of points: ";
            cin >> n;
            cout << "Enter the number of axes: ";
            cin >> k;

            list = VectorList::randomOfSize(n, k);
        }else if(_argc == 2){
            cout << "Attempting to read from file " << _argv[1] << endl;
            list = VectorList::fromFile(_argv[1]);
            cout << "Read successful!" << endl;
        }

#ifdef DEBUG
        //cout << "Data:" << endl;
        //cout << *list << endl;

        Timer::start();
        pairBf = list->closestPairBf();
        timeBf = Timer::lap();
        countBf = Vector::computeCount();
        Vector::resetComputeCount();
#endif

        Timer::start();
        pairDnc = list->closestPairDnc();
        timeDnc = Timer::lap();
        countDnc = Vector::computeCount();
        Vector::resetComputeCount();

#ifdef DEBUG
        cout << endl;
        if(!pairBf){
            cout << "No pairs found by brute-force" << endl;
        }else{
            cout << "Closest pair found by brute-force:" << endl;
            cout << *pairBf << endl;
            cout << "Found with " << countBf << " dist-computations over " << Timer::toMilli(timeBf) << "ms" << endl;
        }
#endif

        cout << endl;
        if(!pairDnc){
            cout << "No pairs found by divide-and-conquer" << endl;
        }else{
            cout << "Closest pair found by divide-and-conquer:" << endl;
            cout << *pairDnc << endl;
            cout << "Found with " << countDnc << " dist-computations over " << Timer::toMilli(timeDnc) << "ms" << endl;
        }

        ofstream file("result.txt");
        if(pairDnc){
            pairDnc->writeToFile(file) << endl;
        }else{
            file << "-1 -1" << endl;
        }
        list->writeToFile(file);
        file.close();

#ifdef DEBUG
        delete pairBf;
#endif
        delete pairDnc;
        delete list;
        
    }catch(exception* e){
        cout << "ERROR: " << e->what() << endl;
    }
    return 0;
}
