#include <iostream>
#include <iomanip>

void print(float f);
void add(float* f);

using namespace std;

int main() {

    // shows the inaccuracy of floating point
    // addition with small numbers
    float lf = 4.0000000000000000000f;

    for (int i = 0; i < 1000; i++)
    {
        cout << i << ". ";
        add(&lf);
        print(lf);
    }

    return 0;
}

void print(float f)
{
    cout << scientific << setprecision(16) << f << endl;
}

void add(float* f)
{
    // doesn't add anything when printed
    //*f += 0.0000001f;

    // adds
    *f += 0.000001f;
}