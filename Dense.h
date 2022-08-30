#ifndef DENSE_H
#define DENSE_H

#include "Activation.h"

/**
 * @class Dense
 * @brief This class represents a layer in the MlpNetwork
 */
class Dense {
 public:
  // constructors

  /**
   * Inits a new layer with given parameters.
   * @param weights Reference to Matrix object - weights
   * @param bias Reference to Matrix object - bias
   * @param activation_func Activation function - relu/softmax
   */
  Dense (const Matrix &weights,
         const Matrix &bias, ActivationFunc activation_func);

  // getters

  /**
   * Returns the weights of this layer.
   * @return Matrix object - weights
   */
  Matrix get_weights () const;

  /**
   * Returns the bias of this layer.
   * @return Matrix object - bias
   */
  Matrix get_bias () const;

  /**
   * Returns the activation function of this layer
   * @return ActivationFunc - relu/softmax
   */
  ActivationFunc get_activation () const;

  // operators

  /**
   * Applies the layer on input and returns output matrix layers operate.
   * @param input Reference to Matrix object - input matrix
   * @return output matrix layers operate.
   */
  Matrix operator() (const Matrix& input);

 private:
  Matrix _weights; // Matrix of weights
  Matrix _bias; // Matrix of bias
  ActivationFunc _activation_func; // Activation func
};

#endif //DENSE_H
