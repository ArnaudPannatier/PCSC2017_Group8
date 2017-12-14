//
// Created by Groupe 8
// Muhammad Haziq Bin Razali and Arnaud Pannatier
// 28.11.17
// PCSC 2017
//

#include "Matrix.h"
#include "../Helpers/inputOutput.h"
#include "../Helpers/Exceptions.h"

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
           values.push_back(std::vector<double>(l));
    }
    dim = Dimension(values.size(), values[0].size());
}

Matrix::Matrix (size_t i, size_t j) {
    dim = Dimension(i,j);
    values =vector2D(i, vector<double>(j));
}

void Matrix::Transpose() {
    Matrix transpose = Matrix(dim.cols, dim.lines);
    for(size_t l=0; l<dim.lines; l++){
        for(size_t c=0; c<dim.cols; c++) {
            transpose(c,l) = values[l][c];
        }
    }
    dim.transpose();
    values = transpose.values;
}

Matrix Matrix::T() const {
    Matrix transpose = Matrix(dim.cols, dim.lines);
    for(size_t l=0; l<dim.lines; l++){
        for(size_t c=0; c<dim.cols; c++) {
            transpose[c][l] = values[l][c];
        }
    }

    return transpose;
}

Matrix Matrix::Inverse() const {

    float d = 0;

    // Left half of the augmented matrix in gaussian elimination
    Matrix L = Matrix(values);

    // Right half of the augmented matrix (identity matrix) in gaussian elimination
    Matrix R = Matrix(dim.lines, dim.cols);
    for (size_t i = 0; i < dim.lines; i++)
        R[i][i] = 1;

    // Partial pivoting
    for (size_t i = dim.lines - 1; i > 0; i--) {
        if (L[i - 1][0] < L[i][0])
            for (size_t j = 0; j < dim.lines; j++) {
                d = L[i][j];
                L[i][j] = L[i - 1][j];
                L[i - 1][j] = d;

                d = R[i][j];
                R[i][j] = R[i - 1][j];
                R[i - 1][j] = d;
            }
    }

    //cout << "pivoted output: " << endl;
    //cout << L << endl;
    //cout << R << endl;

    // reduce to diagonal matrix

    for (size_t i = 0; i < dim.lines; i++) {
        for (size_t j = 0; j < dim.lines; j++)
            if (j != i) {
                d = L[j][i] / L[i][i];

                if(isnan(d)) Exceptions::InvertibleException();

                for (size_t k = 0; k < dim.lines; k++) {
                    R[j][k] -= R[i][k] * d;
                    L[j][k] -= L[i][k] * d;
                }
            }
    }

    //cout << "diag " << endl;
    //cout << L << endl;
    //cout << R << endl;

    // reduce to identity matrix
    for (size_t i = 0; i < dim.lines; i++) {
        d = L[i][i];
        for (size_t j = 0; j < dim.lines; j++)
            R[i][j] = R[i][j] / d;
    }

    return R;
}



Matrix Matrix::Diagonal() const {

    if(isSquare()){
        Matrix diagonal(dim.lines, dim.cols);

        for (size_t i = 0; i < dim.lines; i++) {
            diagonal[i][i] = values[i][i];
        }

        return diagonal;
    }
    else{
        Exceptions::SquareMatrixException();
    }
}

Matrix Matrix::operator-() const {
    return Matrix(*this) * -1;
}

Matrix Matrix::operator+(const Matrix &m) const {

    if(dim == m.dim){
        Matrix ret = m;
        for(size_t l=0; l<dim.lines; l++){
            for(size_t c=0; c<dim.cols; c++) {
                ret(l,c) += values[l][c];
            }
        }
        return ret;
    }else{
        Exceptions::DimensionsException(Matrix(values), m);
    }
}

Matrix Matrix::operator-(const Matrix &m) const {
    return Matrix(*this) + (-m);
}

Matrix Matrix::operator*(const double& d) const {
    Matrix ret = *this;
    for(size_t l=0; l<dim.lines; l++){
        for(size_t c=0; c<dim.cols; c++) {
            ret(l,c) *= d;
        }
    }
    return ret;
}

Matrix Matrix::operator*(const Matrix &m) const {
    if (multipliable(m)) {
        Matrix ret = Matrix(dim.lines, m.dim.cols);
        for (size_t i = 0; i < ret.dim.lines; i++) {
            for (size_t j = 0; j < ret.dim.cols; j++) {
                for (size_t h = 0; h < dim.cols; h++) {
                    ret(i, j) += values[i][h] * m(h, j);
                }
            }
        }
        return ret;
    } else {
        Exceptions::DimensionsException(Matrix(values), m);
    }
}

std::ostream &operator<< (std::ostream &output, const Matrix &m) {
    output << endl << "[";
    for(int l=0; l<m.dim.lines; l++) {
      output << "[";
      for (int c = 0; c < m.dim.cols; c++) {
          output<< m(l,c);
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

bool Matrix::multipliable (const Matrix &m) const {
    return (dim.cols == m.dim.lines);
}

vector<double>& Matrix::operator[] (size_t i) {
    return values[i];
}

const vector<double>& Matrix::operator[] (size_t i) const {
    return values[i];
}

const double &Matrix::operator() (size_t i, size_t j) const {
    return values[i][j];
}

double &Matrix::operator() (size_t i, size_t j) {
    return values[i][j];
}

/// @brief returns the dimensions of the matrix
Dimension Matrix::size () const {
    return dim;
}

bool Matrix::hasZeroOnDiag () const {

    if(isSquare()) {
        bool hasZero = false;
        for (size_t i = 0; i < dim.lines; i++) {
            if (abs(values[i][i]) < epsilonMatrix) {
                hasZero = true;
            }
        }
        return hasZero;

    }else {
        Exceptions::SquareMatrixException();
    }
}

/// @brief returns true if the matrix is square
bool Matrix::isSquare () const {
    return (dim.lines == dim.cols);
}

/// @brief returns true is the matrix is symmetric
bool Matrix::isSymmetric () const {
    if(!isSquare()){
        return false;
    }else{
        for(size_t i = 0; i<dim.lines; i++){
            for(size_t j = i+1; j< dim.cols; j++){
                if(abs(values[i][j] - values[j][i]) > epsilonMatrix){
                    return false;
                }

            }
        }
    }
   return true;
}

istream &operator>> (std::istream &is, Matrix &m) {

    string str;
    is >> str;
    m = inputOutput::readFromText(str);
    return is;
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

bool Dimension::operator== (const Dimension& d) const {
    return (lines == d.lines && cols == d.cols);
}

bool Dimension::operator!= (const Dimension & d) const {
    return !(*this == d);
}

