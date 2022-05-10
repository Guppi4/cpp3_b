#include "doctest.h"
#include "Matrix.hpp"
#include <fstream>
#include <string>

using namespace zich;
using namespace std;

// ifstream units_file{"units.txt"};

TEST_CASE("Good Input")
{

    for (double i = 1; i < 10; i++)
    {
        vector<double> v1 = {i, i, i, i};                  // Matrix
        vector<double> v2 = {i, 0, 0, i};                  // Matrix 2x2
        vector<double> vec_ = {i, i, i, i, i, i, i, i, i}; // Matrix 3x3
        Matrix mat(v1, 2, 2);
        Matrix identity_2(v2, 2, 2);
        Matrix mat_(vec_, 3, 3);
        CHECK((mat > identity_2));
        CHECK((mat >= identity_2));
        CHECK((mat != identity_2));
        CHECK((identity_2 < mat));
        CHECK((identity_2 <= mat));
    }
}

TEST_CASE("Bad Input")
{
    for (double i = 1; i < 10; i++)
    {
        vector<double> vec1 = {i, i, i, i};                // Matrix
        vector<double> identity_2 = {i, 0, 0, i};          // Matrix 2x2
        vector<double> vec_ = {i, i, i, i, i, i, i, i, i}; // Matrix 3x3
        Matrix mat(vec1, 2, 2);
        Matrix mat_identity_2(identity_2, 2, 2);
        Matrix mat_(vec_, 3, 3);
        CHECK_THROWS(bool ans = (mat < mat_));
        CHECK_THROWS(bool ans = (mat <= mat_));
        CHECK_THROWS(bool ans = (mat == mat_));
        CHECK_THROWS(bool ans = (mat >= mat_));
        CHECK_THROWS(bool ans = (mat > mat_));
        CHECK_THROWS(bool ans = (mat != mat_));
    }
}