
#include <iostream>
#include <fstream>
#include "Matrix.hpp"
using namespace std;

namespace zich
{

    // void Matrix::read_units(ifstream & file){}
    Matrix::Matrix(std::vector<double> arr, int row, int col)
    {
        this->columns = col;
        this->rows = row;
        for (size_t i = 0; i < arr.size(); i++)
        {
            this->arr.push_back(arr[i]);
        }
    }

    Matrix Matrix::operator--()
    {
        int row = this->rows;
        int col = this->columns;

        for (int i = 0; i < row * col; i++)
        {
            this->arr[i] -= 1;
        }
        return *this;
    }
    Matrix Matrix::operator--(int)
    {

        int row = this->rows;
        int col = this->columns;
        Matrix copy = *this;
        for (int i = 0; i < row * col; i++)
        {
            copy.arr[i] -= 1;
        }
        return copy;
    }

    Matrix Matrix::operator++()
    {
        int row = this->rows;
        int col = this->columns;

        for (int i = 0; i < row * col; i++)
        {
            this->arr[i] += 1;
        }
        return *this;
    }
    Matrix Matrix::operator++(int)
    {
        int row = this->rows;
        int col = this->columns;
        Matrix copy = *this;
        for (int i = 0; i < row * col; i++)
        {
            copy.arr[i] += 1;
        }
        return copy;
    }
    Matrix Matrix::operator*(const Matrix &other)
    {
        int row = this->rows;
        int col = other.columns;
        std::vector<double> mat;
        mat.resize(row * col);
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {

                double sum = 0.0;
                for (int k = 0; k < other.rows; k++)
                {
                    sum = sum + this->arr[i * this->columns + k] * other.arr[k * col + j];
                }
                mat[i * col + j] = sum;
            }
        }
        return Matrix(mat,row,col);
    }
    Matrix operator*(Matrix &n, double num)
    {
        int row = n.rows;
        int col = n.columns;

        std::vector<double> mat;
        mat.resize(row * col);
        // Traverse the Matrix x
        for (int i = 0; i < row * col; i++)
        {

            // Add the corresponding
            // blocks of Matrices
            mat[i] = n.arr[i] * num;
            // this->arr.push_back(t);
        }

        return Matrix(mat, row, col);
    }
    Matrix operator*(double num, Matrix &n)
    {

        int row = n.rows;
        int col = n.columns;

        std::vector<double> mat;
        mat.resize(row * col);
        // Traverse the Matrix x
        for (int i = 0; i < row * col; i++)
        {

            // Add the corresponding
            // blocks of Matrices
            mat[i] = n.arr[i] * num;
            // this->arr.push_back(t);
        }

        return Matrix(mat, row, col);
    }

    Matrix &Matrix::operator*=(const double num)
    {

        int row = this->rows;
        int col = this->columns;

        // Traverse the Matrix x
        for (int i = 0; i < row * col; i++)
        {

            // Add the corresponding
            // blocks of Matrices
            this->arr[i] *= num;
            // this->arr.push_back(t);
        }

        return *this;
    }
    Matrix &Matrix::operator-=(const Matrix &other)
    {
        if (this->rows != other.rows || this->columns != other.columns)
        {
            throw runtime_error("not");
        }

        int row = this->rows;
        int col = this->columns;

        // Traverse the Matrix x
        for (int i = 0; i < row * col; i++)
        {

            // Add the corresponding
            // blocks of Matrices
            this->arr[i] += other.arr.at(i);
            // this->arr.push_back(t);
        }

        return *this;
    }
    Matrix &Matrix::operator+=(const Matrix &other)
    {
        if (this->rows != other.rows || this->columns != other.columns)
        {
            throw runtime_error("not");
        }

        int row = this->rows;
        int col = this->columns;

        // Traverse the Matrix x
        for (int i = 0; i < row * col; i++)
        {

            // Add the corresponding
            // blocks of Matrices
            this->arr[i] += other.arr.at(i);
            // this->arr.push_back(t);
        }

        return *this;
    }
    Matrix Matrix::operator+(const Matrix &other) //+a
    {
        if (this->rows != other.rows || this->columns != other.columns)
        {
            throw runtime_error("not");
        }

        int row = other.rows;
        int col = other.columns;

        std::vector<double> mat;
        mat.resize(row * col);

        // Traverse the Matrix x
        for (int i = 0; i < row * col; i++)
        {

            // Add the corresponding
            // blocks of Matrices
            if (other.arr.at(i) < 0)
            {
                double t = other.arr.at(i) * (-1);
                mat.push_back(t);
            }
            else
            {
                double t = other.arr.at(i);
                mat.push_back(t);
            }
        }

        return Matrix(mat, row, col);
    }
    Matrix Matrix::operator+(const Matrix &other) // a+b
    {
        if (this->rows != other.rows || this->columns != other.columns)
        {
            throw runtime_error("not");
        }

        int row = this->rows;
        int col = this->columns;

        std::vector<double> mat;
        mat.resize(row * col);

        // Traverse the Matrix x
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {

                // Add the corresponding
                // blocks of Matrices
                double t = this->arr.at(i + j) + other.arr.at(i + j);
                mat.push_back(t);
            }
        }

        return Matrix(mat, row, col);
    }

    Matrix Matrix::operator-(const Matrix &other) //-a
    {
        if (this->rows != other.rows || this->columns != other.columns)
        {
            throw runtime_error("not");
        }

        int row = other.rows;
        int col = other.columns;

        std::vector<double> mat;
        mat.resize(row * col);

        // Traverse the Matrix x
        for (int i = 0; i < row * col; i++)
        {

            // Add the corresponding
            // blocks of Matrices
            double t = other.arr.at(i) * (-1);
            mat.push_back(t);
        }

        return Matrix(mat, row, col);
    }

    Matrix Matrix::operator-(const Matrix &other) // a-b
    {
        if (this->rows != other.rows || this->columns != other.columns)
        {
            throw runtime_error("not");
        }

        int row = this->rows;
        int col = this->columns;

        std::vector<double> mat;
        mat.resize(row * col);

        // Traverse the Matrix x
        for (int i = 0; i < row * col; i++)
        {

            // Add the corresponding
            // blocks of Matrices
            double t = this->arr.at(i) - other.arr.at(i);
            mat.push_back(t);
        }

        return Matrix(mat, row, col);
    }

    // const NumberWithUnits operator-(const NumberWithUnits& a,const NumberWithUnits b);
    // const NumberWithUnits operator+(const NumberWithUnits& a,const NumberWithUnits b);

    bool operator==(const Matrix &a, const Matrix &b)
    {
        return true;
    }
    bool operator!=(const Matrix &a, const Matrix &b)
    {
        return true;
    }
    bool operator>(const Matrix &a, const Matrix &b)
    {
        return true;
    }
    bool operator>=(const Matrix &a, const Matrix &b)
    {
        return true;
    }
    bool operator<(const Matrix &a, const Matrix &b)
    {
        return true;
    }
    bool operator<=(const Matrix &a, const Matrix &b)
    {
        return true;
    }

    ostream &operator<<(ostream &os, const Matrix &m)
    {
        return os << "[" << m.arr[0] << "]" << endl;
    }

    istream &operator>>(istream &is, Matrix &m)
    {

        return is >> m.getarr()[0];
    }

}