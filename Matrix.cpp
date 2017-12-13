//
// Created by Groupe 8
// Muhammad Haziq Bin Razali and Arnaud Pannatier
// 28.11.17
// PCSC 2017
//

#include "Matrix.h"
#include "Exceptions.h"
#include "inputOutput.h"

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

double Matrix::Determinant() const {

    //try{
    if(isSquare()){
        double Determinant=0.0;

        if(dim.lines == 1){
            return values[0][0];
        }

        for(int i=0;i<dim.lines;i++){
            Matrix subMatrix(dim.lines-1,dim.cols-1);
            for(int j=0;j<dim.lines-1;j++){
                for(int k=0;k<dim.cols-1;k++){
                    if(k<i){
                        subMatrix[j][k] = values[j+1][k];
                    }else{
                        subMatrix[j][k] = values[j+1][k+1];
                    }
                }
            }

            double subMatrixDeterminant = subMatrix.Determinant();
            Determinant = Determinant + std::pow(-1,i) * values[0][i] * subMatrixDeterminant;
        }

        // raise exception if determinant zero
        return Determinant;
    }
    else
        Exceptions::SquareMatrixException();

    //}catch (std::exception const& exc){
    //    std::cerr << exc.what() << "\n";
    //    abort();
    //}
}


Matrix Matrix::Adjugate() const {

    //raise exception if not square

    if(dim.lines==1){
        Matrix ad(1,1);
        ad(0,0) = values[0][0];
        return ad;
    }else{
        Matrix ad(dim.lines,dim.lines);
        Matrix subAd(dim.lines-1,dim.lines-1);
        for(int i=0;i<dim.lines;i++){
            for(int j=0;j<dim.cols;j++){
                for(int k=0;k<dim.lines-1;k++){
                    for(int h=0;h<dim.cols-1;h++){
                        if(k<i&&h<j){
                            subAd[k][h]=values[k][h];
                        } else if(k>=i&&h<j){
                            subAd[k][h]=values[k+1][h];
                        } else if(k<i&&h>=j){
                            subAd[k][h]=values[k][h+1];
                        }else{
                            subAd[k][h]=values[k+1][h+1];
                        }
                    }
                }
                ad[j][i] = pow(-1,(i+j))*subAd.Determinant();
            }
        }
        return ad;
    }
}

Matrix Matrix::Inverse() const {

    // todo
    return Matrix(values).Adjugate() * (1/Matrix(values).Determinant());
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
    try{
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
    }catch (const std::exception& e)
    {
        std::cerr << e.what() << "\n";
        abort();
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

/// @brief returns true if the 2 matrices are multipliable
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

    try{
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
    }catch (const std::exception& e) {
        std::cerr << e.what() << "\n";
        abort();
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

