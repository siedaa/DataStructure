#include <iostream>
using namespace std;

class box
{
    float *volume;

public:
    // default constructor
    box()
    {
        volume = new float;
        *volume = 0;
    }
    // parameterized constructor
    box(float n)
    {
        volume = new float;
        *volume = n;
    }
    // copy constructor
    box(const box &obj)
    {
        volume = new float;
        *volume = *(obj.volume);
    }

    void display()
    {
        cout << "volume is " << *volume << endl;
    }

    void setVolume(float n)
    {
        *volume = n;
    }
};

int main()
{
    box b1(5.5);
    box b2 = b1; // copy constructor is called
    cout << "displaying b1: " << endl;
    b1.display();
    cout << "displaying b2: " << endl;
    b2.display();
    cout << "chanaging vol for b2" << endl
         << endl;
    b2.setVolume(7.77);
    cout << "displaying b1: " << endl;
    b1.display();
    cout << "displaying b2" << endl;
    b2.display();

    return 0;
}