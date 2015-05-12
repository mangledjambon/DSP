#include <iostream>
#include <iomanip>
#include <stdlib.h>

void print(float f);
void add(float* f);

using namespace std;

int main() {
/*
    // shows the inaccuracy of floating point
    // addition with small numbers
    float lf = 4.0000000000000000000f;
    for (int i = 0; i < 1000; i++)
    {
        cout << i << ". ";
        add(&lf);
        print(lf);
    }*/

    // random float generation
    //This will generate a number from 0.0 to 1.0, inclusive.
    float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);

    //This will generate a number from 0.0 to some arbitrary float, X:
    float X = 10.f;
    float r2 = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/X));

    //This will generate a number from some arbitrary LO to some arbitrary HI:
    float LO = 0.f;
    float HI = 4.f;
    float r3 = LO + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(HI-LO)));


    return 0;
}

void print(float f)
{
    cout << scientific << setprecision(16) << f << endl;
}

void add(float* f)
{
    // doesn't add anything
    //*f += 0.0000001f;

    // adds
    *f += 0.000001f;
}