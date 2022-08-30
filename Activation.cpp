#include "Activation.h"
#include <cmath>

// See full documentation in header file

Matrix activation::relu (const Matrix &x)
{
  Matrix result(x.get_rows(), x.get_cols());
  int rows = result.get_rows(), cols = result.get_cols();
  for (int i = 0; i < rows; i++)
    {
      for (int j = 0; j < cols; j++)
        {
          if (x(i, j) >= 0)
            {
              result[i * cols + j] = x(i, j);
            }
          else
            {
              result[i * cols + j] = 0;
            }
        }
    }
  return result;
}

Matrix activation::softmax (const Matrix &x)
{
  int rows = x.get_rows(), cols = x.get_cols();
  Matrix result(rows, cols);
  float temp_sum = 0.0;
  for (int i = 0; i < rows; i++)
    {
      for (int j = 0; j < cols; j++)
        {
          float value = std::exp(x(i, j));
          result[i * cols + j] = value;
          temp_sum += value;
        }
    }
  float scalar = 1 / temp_sum;
  result = scalar * result;
  return result;
}