#include "Dense.h"

// See full documentation in header file

Dense::Dense (const Matrix &weights,
              const Matrix &bias, ActivationFunc activation_func)
    : _weights (weights), _bias (bias), _activation_func (activation_func)
{
}

Matrix Dense::get_weights () const
{
  return _weights;
}

Matrix Dense::get_bias () const
{
  return _bias;
}

ActivationFunc Dense::get_activation () const
{
  return _activation_func;
}

Matrix Dense::operator() (const Matrix& input)
{
  Matrix temp = _weights * input + _bias;
  return _activation_func(temp);
}