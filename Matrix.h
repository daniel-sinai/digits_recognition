// Matrix.h
#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

#define PRINT_THRESHOLD 0.1
#define DOUBLE_ASTERISK "**"
#define DOUBLE_SPACE "  "
#define OUT_OF_RANGE "Desired index is out of range"
#define INVALID_LENGTH "Invalid lengths for matrix"
#define DIFFERENT_MATRICES_SIZE "Two matrices needs to be the same size"
#define MULT_SIZES_ERROR "Invalid sizes for multiplication"
#define READING_ERROR "Couldn't read all the file"
#define INVALID_INPUT_SIZE "Input needs to correspond matrix sizes"
#define DEFAULT_SIZE 1
#define VECTOR_COLUMNS 1
#define BLANK_SPACE " "
#define SQUARE 2

/**
 * @struct matrix_dims
 * @brief Matrix dimensions container. Used in MlpNetwork.h and main.cpp
 */
typedef struct matrix_dims {
    int rows, cols;
} matrix_dims;

/**
 * @class Matrix
 * @brief This class represents a matrix
 */
class Matrix {
 public:
  // constructors and destructors

  /**
   * Default constructor - Constructs Matrix of size 1×1.
   * Inits the single element to 0.
   */
  Matrix ();

  /**
   * Constructor - Constructs Matrix of size rows × cols.
   * Inits all elements to 0.
   * @param rows Integer - number of rows of the matrix.
   * @param cols Integer - Number of cols of the matrix.
   */
  Matrix (int rows, int cols);

  /**
   * Copy-constructor - Constructs matrix from another Matrix m.
   * @param m Matrix to copy from.
   */
  Matrix (const Matrix &m); // copy-ctr

  /**
   * Destructor - frees the matrix array.
   */
  ~Matrix ();

  // getters

  /**
   * returns the amount of rows as int.
   * @return Integer - number of rows of the current matrix
   */
  int get_rows () const;

  /**
   * returns the amount of cols as int.
   * @return Integer - number of cols of the current matrix
   */
  int get_cols () const;

  // methods

  /**
   * Transforms a matrix into its transpose matrix.
   * Supports function calling concatenation.
   * @return Matrix reference - transposed matrix.
   */
  Matrix &transpose ();

  /**
   * Transforms a matrix into a column vector.
   * Supports function calling concatenation
   * @return Matrix reference - vectorized matrix
   */
  Matrix &vectorize ();

  /**
   * Prints matrix elements.
   */
  void plain_print () const;

  /**
   * Returns a matrix which is the elementwise multiplication
   * (Hadamard product) of this matrix and another matrix m.
   * @param m Reference to Matrix object
   * @return Result matrix - this dot m
   */
  Matrix dot (const Matrix &m) const;

  /**
   * Returns the Frobenius norm of the given matrix.
   * @return float - norm of the matrix.
   */
  float norm () const;

  //operators

  /**
   * Returns the sum of this matrix and another matrix m.
   * @param m Reference to Matrix object.
   * @return Result - sum of this matrix and m.
   */
  Matrix operator+ (const Matrix &m) const;

  /**
   * Assign matrix m to this matrix.
   * @param m Reference to Matrix object.
   * @return this matrix after assigning m to it.
   */
  Matrix &operator= (const Matrix &m);

  /**
   * Returns the multiplication of this matrix and another matrix m
   * @param m Reference to Matrix object.
   * @return Product of this matrix and m
   */
  Matrix operator* (const Matrix &m) const;

  /**
   * Returns scalar multiplication of this matrix on the right.
   * @param c float - a scalar
   * @return Product of this matrix * c
   */
  Matrix operator* (float c) const; // scalar multiplication on the right

  /**
   * Returns scalar multiplication of a matrix m on the left.
   * @param c float - a scalar
   * @param m Reference to Matrix object.
   * @return Product of c * this matrix
   */
  friend Matrix operator* (float c, const Matrix &m); // now on the left

  /**
   * Matrix addition accumulation of this matrix and another matrix m
   * @param m Reference to Matrix object
   * @return this matrix after adding m
   */
  Matrix &operator+= (const Matrix &m);

  /**
   * Parenthesis indexing - for i,j indices, Matrix m: m(i,j) will return
   * the i,j element in the matrix - non-const version, can change values
   * @param i Integer - row index
   * @param j Integer - col index
   * @return i,j element in the matrix
   */
  float& operator() (int i, int j);

  /**
   * Parenthesis indexing - for i,j indices, Matrix m: m(i,j) will return
   * the i,j element in the matrix - const version, only read values
   * @param i Integer - row index
   * @param j Integer - col index
   * @return i,j element in the matrix
   */
  const float& operator() (int i, int j) const;

  /**
   * Brackets indexing - for i index, Matrix m: m[i] will return the
   * element in position i. non-const version, can change values.
   * @param i Integer - index
   * @return the element in position i
   */
  float& operator[] (int i);

  /**
   * Brackets indexing - for i index, Matrix m: m[i] will return the
   * element in position i. const version, only read values.
   * @param i Integer - index
   * @return the element in position i
   */
  const float& operator[] (int i) const;

  /**
   * Output stream - pretty export of matrix.
   * @param os Reference to std::ostream
   * @param m Reference to Matrix object.
   * @return Output - reference to std::ostream
   */
  friend std::ostream &operator<<(std::ostream &os, const Matrix &m);

  /**
   * Input stream - fills matrix elements.
   * @param is Reference to std::istream
   * @param m Reference to Matrix object.
   * @return Input - reference to std::istream
   */
  friend std::istream &operator>>(std::istream &is, Matrix &m);

 private:
  int _rows; // Number of rows
  int _cols; // Number of columns
  float *_mat; // Matrix itself
};

#endif //MATRIX_H