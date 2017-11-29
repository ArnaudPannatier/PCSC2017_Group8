//
// Created by Groupe 8
// Muhammad Haziq Bin Razali and Arnaud Pannatier
// 28.11.17
// PCSC 2017
//

#include "Matrix.h"

Matrix::Matrix () {
    dim = Dimension(0,0);
    values = vector2D();
}
Matrix::Matrix(vector2D arr){
    dim = Dimension(arr.size(), arr[0].size());
    values = arr;
}
Matrix::Matrix (initializer_list< initializer_list<double> > list){
    values = vector2D();
    for(auto l : list){
           values.push_back(vector<double>(l));
    }
    dim = Dimension(values.size(), values[0].size());
}
Matrix::Matrix(const Matrix &m) {
    values = m.values;
    dim = m.dim;
}


double Matrix::Get(const int i, const int j) const {
    return values[i][j];
}

void Matrix::Set(const int i, const int j, const double &value) {
    values[i][j] = value;
}

void Matrix::Transpose() {
    vector2D transpose = vector2D(dim.lines, vector<double>(dim.cols));

    for(size_t i=0; i<dim.lines; i++){
        for(size_t j=0; j<dim.cols; j++) {
                transpose[j][i] = values[i][j];
        }
    }
    dim.transpose();
    values = transpose;
}

Matrix &Matrix::operator=(const Matrix &m) {
    values = m.values;
    dim = m.dim;
    return *this;
}

Matrix Matrix::operator-() const {
    Matrix m;
    m.values = values;
    return m;
}

Matrix Matrix::operator+(const Matrix &m) const {
    return Matrix();
}

Matrix Matrix::operator-(const Matrix &m) const {
    return Matrix();
}

Matrix Matrix::operator*(const double d) const {
    return Matrix();
}

Matrix Matrix::operator*(const Matrix &m) const {
    return Matrix();
}

std::ostream &operator<< (std::ostream &output, const Matrix &m) {
    output << endl << "[";
    for(int l=0; l<m.dim.lines; l++) {
      output << "[";
      for (int c = 0; c < m.dim.cols; c++) {
          output<< m.Get (l,c);
          if(c+1<m.dim.cols) {
              output << ",";
          }
      }
      output << "]";
      if(l+1<m.dim.lines) {
          output << endl;
      }
    }
    output << "]" << endl;
    return output;
}


Dimension::Dimension() {
    lines = 0;
    cols = 0;
}
Dimension::Dimension(size_t lines_, size_t col_) {
    lines = lines_;
    cols = col_;
}

void Dimension::transpose () {
    size_t lines_ = lines;
    lines = cols;
    cols = lines_;
}

