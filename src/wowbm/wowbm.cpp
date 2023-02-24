#include <iostream>
#include <struct/VectorList.hpp>
#include <struct/exc/Exception.hpp>
using namespace std;

int main(){
    try{
        int n, k;
        cout << "Enter the number of points: ";
        cin >> n;
        cout << "Enter the number of axes: ";
        cin >> k;

        VectorList& list = *VectorList::randomOfSize(n, k);
        cout << list << endl;
    }catch(exception* e){
        cout << "ERROR: " << e->what() << endl;
    }
    return 0;
}
