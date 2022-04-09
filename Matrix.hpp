#pragma once
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <utility>

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
        // NumberWithUnits(double num,std::string str):number(num),_str(str){}
        // static void read_units(std::ifstream& units_file);
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
        Matrix &operator+=(const Matrix &other);
        Matrix &operator-=(const Matrix &other);
        Matrix operator+(const Matrix &other);
        Matrix operator-(const Matrix &other);
        friend Matrix operator-(const Matrix &other);
        friend Matrix operator+(const Matrix &other);
        

        Matrix operator--();
        Matrix operator--(int);
        Matrix operator++();
        Matrix operator++(int);
        Matrix& operator*=(int num);
        friend Matrix operator*(Matrix &n, double num);
        friend Matrix operator*(double num, Matrix &n);

        friend bool operator==(const Matrix &a, const Matrix &b);
        friend bool operator!=(const Matrix &a, const Matrix &b);
        friend bool operator>(const Matrix &a, const Matrix &b);
        friend bool operator>=(const Matrix &a, const Matrix &b);
        friend bool operator<(const Matrix &a, const Matrix &b);
        friend bool operator<=(const Matrix &a, const Matrix &b);

        friend std::ostream &operator<<(std::ostream &os, const Matrix &num);
        friend std::istream &operator>>(std::istream &is, Matrix num);
    };
}
