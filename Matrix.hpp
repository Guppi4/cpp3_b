#pragma once
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <utility>
// (size_t) is the unsigned integer type of the result of sizeof which is used to represent the size of objects in bytes
// (const Matrix &mat) - const - can't change Matrix, & - object not copied
// Matrix &Matrix - for p1+=p2+=p3... for work with object
namespace zich
{

    class Matrix
    {
    public:
        std::vector<double> arr;
        int rows;
        int columns;

    public:
        Matrix(std::vector<double> arr,int row,int col);
         ~Matrix (){}
       
        std::vector<double> getarr(){
            return arr;
        }
        int getRows()
        {
            return rows;
        }
        int getCols()
        {
            return columns;
        }
        Matrix &operator+=(const Matrix &other); //Matrix &Matrix - for p1+=p2+=p3... for work with object

        Matrix &operator-=(const Matrix &other);
        Matrix operator+();
        Matrix operator-(const Matrix &other);
        Matrix operator-();
       
        Matrix operator+(const Matrix &other);
        
        Matrix operator*(const Matrix &other);
         Matrix operator--();
        Matrix operator--(int);
        Matrix operator++();
        Matrix operator++(int);
        Matrix& operator*=(const Matrix &m);
        Matrix& operator*=(const double num);
        
        friend Matrix operator*(Matrix &n, double num);//function frend of class can use of elemnts of class (private)
        friend Matrix operator*(double num, Matrix &n);

         friend bool operator==(const Matrix &thiss,const Matrix &other);
         bool operator!=( const Matrix &other);
         bool operator>( Matrix &other);
         bool operator>=( Matrix &other);
         bool operator<( Matrix &other);
         bool operator<=( Matrix &other);

        friend std::ostream &operator<<(std::ostream &os, const Matrix &num);
        friend std::istream &operator>>(std::istream &input, Matrix &mat);
    };
}
