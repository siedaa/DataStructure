#include <iostream>
using namespace std;

class ResearchPaper {
    string *author;
    int size;
    public:
    // constructor
    ResearchPaper(int n){
        size = n;
        author = new string [n];

        for (int i=0;i<size ;i++){
            cout<<"enter name of the author "<<i+1<<endl;
            cin>>author[i];
        
        }
    }

    // destructor
    ~ResearchPaper(){
     delete[] author;
     author = NULL;

    }

    // copy constructor
    ResearchPaper(const ResearchPaper &obj ) {
        size = obj.size;
        author = new string[size];
        for (int i=0;i<size;i++){
            author [i] = obj.author[i];
        }
    }

    // assignment operator

    ResearchPaper & operator = (const ResearchPaper &obj) {
        if (this != &obj) {
            size = obj.size;
            author = new string [size];
            for (int i=0;i<size;i++) {
                author[i] = obj.author[i];
            }
        }
        return *this;
    }

    void display() {
        for (int i=0;i<size;i++) {
            cout<<author[i]<<endl;
        }
    }

};

int main () {
ResearchPaper rp1(2);
cout<<"displaying rp1"<<endl;
rp1.display();
ResearchPaper rp2 = rp1; // copy constructor
cout<<"displaying rp2"<<endl;
rp2.display();
ResearchPaper rp3(1);
cout<<"displaying rp3"<<endl;
rp3.display();
rp3 = rp1; // assignment operator
cout<<"displaying rp3 using assignment operator"<<endl;
rp3.display();
    return 0;
}