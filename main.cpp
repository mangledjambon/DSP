#include <iostream>
#include <iomanip>
#include "eigen-eigen-10219c95fe65/Eigen/Eigen"
#define eps 0.0000000000001f

void print(float f);
void add(float* f);

using namespace std;
using Eigen::MatrixXcf;
using Eigen::MatrixXf;

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
    }

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


    MatrixXcf comp1 = MatrixXcf::Random(3,3);
    MatrixXcf comp2 = MatrixXcf::Random(3,3);
    MatrixXcf sum = comp1.colwise().sum();

    cout << sum;
*/

    Eigen::Vector3f pan_dir(0, (const float)M_PI / 4, (const float)M_PI / 2);
    MatrixXf projmat(3, 2);
    MatrixXf panmat(3, 2);
    MatrixXf k(3, 3);
    MatrixXf kAbs(3, 3);
    MatrixXf pimat(3, 2);
    MatrixXf kSum, lS;

    projmat << pan_dir.array().sin(), -(pan_dir.array().cos());
    panmat << pan_dir.array().cos(), pan_dir.array().sin();
    k = panmat * projmat.transpose();
    kAbs << k.cwiseAbs();
    kSum = kAbs.colwise().sum().transpose();
    kSum.transposeInPlace();
    lS = kSum.replicate(2049, 1);
    lS.array() + eps;
    Eigen::Matrix3f ident = Eigen::Matrix3f::Identity(3, 3);
    pimat = projmat.fullPivHouseholderQr().solve(ident);

    cout << "Projmat: \n" << projmat << endl;
    cout << "PanMat: \n" << panmat << endl;
    cout << "k: \n" << k << endl;
    cout << "kAbs: \n" << kAbs << endl;
    cout << "Pimat: \n" << pimat << endl;
    //cout << "lS: \n" << lS << endl;
    cout << "kSum: \n" << kSum << endl;

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