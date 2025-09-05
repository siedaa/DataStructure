#include <iostream>
using namespace std;

class exam {
    float *marks;
    int size;
    public:
    exam (int n) {
        size = n ;
        marks = new float [size];
        for (int i=0;i<size;i++) {
            cout<<"enter marks for your exam " <<i+1<<endl;
            cin >>marks[i];
        }
    }

    ~ exam () {
        delete [] marks;
        marks = NULL;
    }

    void dsiplay () {
        for (int i =0;i< size;i++) {
            cout <<marks[i] <<endl;
        }
    }
};

int main () {
    exam e1 (3);
    exam e2 (e1);
    cout<<"displaying exam for e1" <<endl;
    e1.dsiplay();
    cout<<"displaying exam for e2" <<endl;
    e2.dsiplay();

    return 0;
}