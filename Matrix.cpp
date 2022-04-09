
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

        for (size_t i = 0; i < row * col; i++)
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
        for (size_t i = 0; i < row * col; i++)
        {
            copy.arr[i] -= 1;
        }
        return copy;
    }

    Matrix Matrix::operator++()
    {
        int row = this->rows;
        int col = this->columns;

        for (size_t i = 0; i < row * col; i++)
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
        for (size_t i = 0; i < row * col; i++)
        {
            copy.arr[i] += 1;
        }
        return copy;
    }
    Matrix Matrix::operator*(const Matrix &other)
    {
        int row = (size_t)this->rows;
        int col = (size_t)other.columns;
        std::vector<double> mat;
        mat.resize((size_t)(row * col));
        for (size_t i = 0; i < row; i++)
        {
            for (size_t j = 0; j < col; j++)
            {

                double sum = 0.0;
                for (size_t k = 0; k < other.rows; k++)
                {
                    sum = sum + this->arr[(size_t)(i * (size_t)this->columns + k)] * other.arr[(size_t)k * (size_t)col + j];
                }
                mat[(size_t)i * (size_t)col + j] = sum;
            }
        }
        return Matrix(mat,row,col);
    }
    Matrix operator*(Matrix &n, double num)
    {
        int row = (size_t)n.rows;
        int col = (size_t)n.columns;

        std::vector<double> mat;
        mat.resize((size_t)(row * col));
        // Traverse the Matrix x
        for (size_t i = 0; i < row * col; i++)
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

        int row = (size_t)n.rows;
        int col = (size_t)n.columns;

        std::vector<double> mat;
        mat.resize((size_t)row * (size_t)col);
        // Traverse the Matrix x
        for (size_t i = 0; i < row * col; i++)
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
        for (size_t i = 0; i < row * col; i++)
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
        for (size_t i = 0; i < row * col; i++)
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
        for (size_t i = 0; i < row * col; i++)
        {

            // Add the corresponding
            // blocks of Matrices
            this->arr[i] += other.arr.at(i);
            // this->arr.push_back(t);
        }

        return *this;
    }
    Matrix Matrix::operator+() //+a
    {
       

        int row = (size_t)this->rows;
        int col = (size_t)this->columns;

        std::vector<double> mat;
        mat.resize((size_t)row * (size_t)col);

        // Traverse the Matrix x
        for (size_t i = 0; i < row * col; i++)
        {

            // Add the corresponding
            // blocks of Matrices
            if (this->arr.at(i) < 0)
            {
                double t = this->arr.at(i) * (-1);
                mat.push_back(t);
            }
            else
            {
                double t = this->arr.at(i);
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
        mat.resize((size_t)row * (size_t)col);

        // Traverse the Matrix x
        for (size_t i = 0; i < row; i++)
        {
            
                // Add the corresponding
                // blocks of Matrices
                double t = this->arr.at(i) + other.arr.at(i);
                mat.push_back(t);
            
        }

        return Matrix(mat, row, col);
    }

    Matrix Matrix::operator-() //-a
    {
       

        int row = this->rows;
        int col =  this->columns;

        std::vector<double> mat;
        mat.resize((size_t)row * (size_t)col);

        // Traverse the Matrix x
        for (size_t i = 0; i < row * col; i++)
        {

            // Add the corresponding
            // blocks of Matrices
             double t =0.0;
            if(this->arr[i]>0){
              t= this->arr[i] * (-1);
               this->arr[i]=t;   
            
            }
            else{
               t= this->arr[i];
               this->arr[i]=t;  
            }
            //cout << this->arr[i];
            
        }

        return *this;
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
        mat.resize((size_t)row * (size_t)col);

        // Traverse the Matrix x
        for (size_t i = 0; i < row * col; i++)
        {

            // Add the corresponding
            // blocks of Matrices
            double t = this->arr.at(i) - other.arr.at(i);
            mat.push_back(t);
        }
          Matrix m(mat, row, col);
        return m;
    }

    // const NumberWithUnits operator-(const NumberWithUnits& a,const NumberWithUnits b);
    // const NumberWithUnits operator+(const NumberWithUnits& a,const NumberWithUnits b);

    bool Matrix::operator==(const Matrix &other)
    {
        int row = this->rows;
        int col = this->columns;
         for (size_t i = 0; i < row * col; i++)
        {

            // Add the corresponding
            // blocks of Matrices
            if(this->arr[i] !=other.arr[i]){
                return false;
            }
           
        }
        return true;
    }
    bool Matrix::operator!=( const Matrix &other)
    {
        int row = this->rows;
        int col = this->columns;
         for (size_t i = 0; i < row * col; i++)
        {

            // Add the corresponding
            // blocks of Matrices
            if(this->arr.at(i)==other.arr.at(i)){
                 return false;
            }
          
        }
        return true;
    }
    bool Matrix::operator>( Matrix &other)
    {
        if (this->rows != other.rows || this->columns != other.columns)
        {
            throw runtime_error("not");
        }

        int row = this->rows;
        int col = this->columns;

        double s1=0.0;
        double s2=0.0;
        // Traverse the Matrix x
        for (size_t i = 0; i < row * col; i++)
        {

            // Add the corresponding
            // blocks of Matrices
            s1+= this->arr.at(i) ;
             s2+=other.arr.at(i);
        }
        
        return s1>s2;
    }
    bool Matrix::operator>=( Matrix &other)
    {
         if (this->rows != other.rows || this->columns != other.columns)
        {
            throw runtime_error("not");
        }

        int row = this->rows;
        int col = this->columns;

        double s1=0.0;
        double s2=0.0;
        // Traverse the Matrix x
        for (size_t i = 0; i < row * col; i++)
        {

            // Add the corresponding
            // blocks of Matrices
            s1+= this->arr.at(i) ;
             s2+=other.arr.at(i);
        }
        
        return s1>=s2;
    }
    bool Matrix::operator<(Matrix &other)
    {
         if (this->rows != other.rows || this->columns != other.columns)
        {
            throw runtime_error("not");
        }

        int row = this->rows;
        int col = this->columns;

        double s1=0.0;
        double s2=0.0;
        // Traverse the Matrix x
        for (size_t i = 0; i < row * col; i++)
        {

            // Add the corresponding
            // blocks of Matrices
            s1+= this->arr.at(i) ;
             s2+=other.arr.at(i);
        }
       
        return s2>s1;
    }
    bool Matrix::operator<=(Matrix &other)
    {
        if (this->rows != other.rows || this->columns != other.columns)
        {
            throw runtime_error("not");
        }

        int row = this->rows;
        int col = this->columns;

        double s1=0.0;
        double s2=0.0;
        // Traverse the Matrix x
        for (size_t i = 0; i < row * col; i++)
        {

            // Add the corresponding
            // blocks of Matrices
            s1+= this->arr.at(i) ;
             s2+=other.arr.at(i);
        }
       
        return s2>=s1;
    }

    ostream &operator<<(ostream &os, const Matrix &m)
    {
         for (size_t i = 0; i < m.rows; i++)
        {
            cout << '[';
            for (size_t j = 0; j < m.columns; j++)
            {   
                if (j != m.columns -1 )
                {
                    cout << m.arr[(i * (size_t)m.columns + j)] << ' ';
                }
                else{
                    cout <<m.arr[(i * (size_t)m.columns + j)];
                }
            }
            cout << ']' << '\n';
        }
        return os;
       
    }

    istream &operator>>(istream &is, Matrix &m)
    {

        return is >> m.getarr()[0];
    }

}