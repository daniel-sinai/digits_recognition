#include "Matrix.h"
#include <stdexcept>
#include <exception>
#include <iostream>
#include <cmath>

// See full documentation and macros in header file

Matrix::Matrix (int rows, int cols)
{
  if (rows <= 0 || cols <= 0)
    {
      throw std::length_error (INVALID_LENGTH);
    }
  _rows = rows;
  _cols = cols;
  _mat = new float[rows * cols] ();
}

Matrix::Matrix () : Matrix (DEFAULT_SIZE, DEFAULT_SIZE)
{
}

Matrix::Matrix (const Matrix &m) : Matrix (m._rows, m._cols)
{
  for (int i = 0; i < m._rows; i++)
    {
      for (int j = 0; j < m._cols; j++)
        {
          _mat[i * _cols + j] = m._mat[i * _cols + j];
        }
    }
}

Matrix::~Matrix ()
{
  delete[] _mat;
}

int Matrix::get_rows () const
{
  return _rows;
}

int Matrix::get_cols () const
{
  return _cols;
}

Matrix &Matrix::transpose ()
{
  // transposing the matrix
  float *transpose = new float[_cols * _rows] ();
  for (int i = 0; i < _rows; i++)
    {
      for (int j = 0; j < _cols; j++)
        {
          transpose[j * _rows + i] = _mat[i * _cols + j];
        }
    }
  // delete current matrix and replace it with transpose
  delete[] _mat;
  _mat = transpose;
  // swap the sizes of rows and cols
  int temp = _rows;
  _rows = _cols;
  _cols = temp;
  return *this;
}

Matrix &Matrix::vectorize ()
{
  int temp = _cols;
  _cols = VECTOR_COLUMNS;
  _rows *= temp;
  return *this;
}

void Matrix::plain_print () const
{
  for (int i = 0; i < _rows; i++)
    {
      for (int j = 0; j < _cols; j++)
        {
          std::cout << _mat[i * _cols + j] << BLANK_SPACE;
        }
      std::cout << std::endl;
    }
}

Matrix Matrix::dot (const Matrix &m) const
{
  if (_rows != m._rows || _cols != m._cols)
    {
      throw std::length_error (DIFFERENT_MATRICES_SIZE);
    }
  Matrix ret (_rows, _cols);
  for (int i = 0; i < _rows; i++)
    {
      for (int j = 0; j < _cols; j++)
        {
          ret._mat[i * _cols + j] =
              _mat[i * _cols + j] * m._mat[i * _cols + j];
        }
    }
  return ret;
}

float Matrix::norm () const
{
  float norm = 0;
  for (int i = 0; i < _rows; i++)
    {
      for (int j = 0; j < _cols; j++)
        {
          norm += (float) std::pow (_mat[i * _cols + j], SQUARE);
        }
    }
  return std::sqrt (norm);
}

Matrix Matrix::operator+ (const Matrix &m) const
{
  if (_rows != m._rows || _cols != m._cols)
    {
      throw std::length_error (DIFFERENT_MATRICES_SIZE);
    }
  Matrix ret (_rows, _cols);
  for (int i = 0; i < _rows; i++)
    {
      for (int j = 0; j < _cols; j++)
        {
          ret._mat[i * _cols + j] =
              _mat[i * _cols + j] + m._mat[i * _cols + j];
        }
    }
  return ret;
}

Matrix &Matrix::operator= (const Matrix &m)
{
  if (this == &m)
    {
      return *this;
    }

  _rows = m._rows;
  _cols = m._cols;
  delete[] _mat;
  _mat = new float[_rows * _cols] ();
  for (int i = 0; i < _rows; i++)
    {
      for (int j = 0; j < _cols; j++)
        {
          _mat[i * _cols + j] = m._mat[i * _cols + j];
        }
    }
  return *this;
}

Matrix Matrix::operator* (const Matrix &m) const
{
  if (_cols != m._rows)
    {
      throw std::length_error (MULT_SIZES_ERROR);
    }

  Matrix ret (_rows, m._cols);
  for (int i = 0; i < _rows; i++)
    {
      for (int j = 0; j < m._cols; j++)
        {
          for (int k = 0; k < _cols; k++)
            {
              ret._mat[i * ret._cols + j] +=
                  _mat[i * _cols + k] * m._mat[k * m._cols + j];
            }
        }
    }
  return ret;
}

Matrix Matrix::operator* (float c) const
{
  Matrix ret (_rows, _cols);
  for (int i = 0; i < ret._rows; i++)
    {
      for (int j = 0; j < ret._cols; j++)
        {
          ret._mat[i * ret._cols + j] = _mat[i * _cols + j] * c;
        }
    }
  return ret;
}

Matrix operator* (float c, const Matrix &m)
{
  Matrix ret (m._rows, m._cols);
  for (int i = 0; i < m._rows; i++)
    {
      for (int j = 0; j < m._cols; j++)
        {
          ret._mat[i * ret._cols + j] = m._mat[i * m._cols + j] * c;
        }
    }
  return ret;
}

Matrix &Matrix::operator+= (const Matrix &m)
{
  if (_rows != m._rows || _cols != m._cols)
    {
      throw std::length_error (DIFFERENT_MATRICES_SIZE);
    }
  for (int i = 0; i < _rows; i++)
    {
      for (int j = 0; j < _cols; j++)
        {
          _mat[i * _cols + j] += m._mat[i * _cols + j];
        }
    }
  return *this;
}

float &Matrix::operator() (int i, int j)
{
  if ((i < 0 || i >= _rows) || (j < 0 || j >= _cols))
    {
      throw std::out_of_range (OUT_OF_RANGE);
    }
  return _mat[i * _cols + j];
}

const float &Matrix::operator() (int i, int j) const
{
  if ((i < 0 || i >= _rows) || (j < 0 || j >= _cols))
    {
      throw std::out_of_range (OUT_OF_RANGE);
    }
  return _mat[i * _cols + j];
}

float &Matrix::operator[] (int i)
{
  if (i < 0 || i >= (_rows * _cols))
    {
      throw std::out_of_range (OUT_OF_RANGE);
    }
  return _mat[i];
}

const float &Matrix::operator[] (int i) const
{
  if (i < 0 || i >= (_rows * _cols))
    {
      throw std::out_of_range (OUT_OF_RANGE);
    }
  return _mat[i];
}

std::ostream &operator<< (std::ostream &os, const Matrix &m)
{
  for (int i = 0; i < m._rows; i++)
    {
      for (int j = 0; j < m._cols; j++)
        {
          if (m (i, j) > PRINT_THRESHOLD)
            {
              os << DOUBLE_ASTERISK;
            }
          else
            {
              os << DOUBLE_SPACE;
            }
        }
      os << std::endl;
    }
  return os;
}

std::istream &operator>> (std::istream &is, Matrix &m)
{
  if (is)
    {
      is.seekg (0, std::ios::end);
      int length = (int) is.tellg ();
      is.seekg (0, std::ios::beg);

      if ((int) (length / sizeof (float)) != m._cols * m._rows)
        {
          throw std::runtime_error (INVALID_INPUT_SIZE);
        }
      int counter = 0;
      while (counter < m._rows * m._cols
             && is.read (reinterpret_cast<char *>(&m[counter]),
                         sizeof (float)))
        {
          counter++;
        }
      if (counter != m._rows * m._cols)
        {
          throw std::runtime_error (READING_ERROR);
        }
    }
  return is;
}