//MlpNetwork.h

#ifndef MLPNETWORK_H
#define MLPNETWORK_H

#include "Dense.h"

#define MLP_SIZE 4

/**
 * @struct digit
 * @brief Identified (by Mlp network) digit with
 *        the associated probability.
 * @var value - Identified digit value
 * @var probability - identification probability
 */
typedef struct digit {
	unsigned int value;
	float probability;
} digit;

const matrix_dims img_dims = {28, 28};
const matrix_dims weights_dims[] = {{128, 784},
									{64,  128},
									{20,  64},
									{10,  20}};
const matrix_dims bias_dims[] = {{128, 1},
								 {64,  1},
								 {20,  1},
								 {10,  1}};

/**
 * @class MlpNetwork
 * @brief This class represents the neural network
 */
class MlpNetwork
{
 public:
  // constructor

  /**
   * constructs the neural network
   * @param weights Array of Matrices of the weights
   * @param biases Array of Matrices of the biases
   */
  MlpNetwork(Matrix weights[MLP_SIZE], Matrix biases[MLP_SIZE]);

  // operator

  /**
   * Applies the entire network on input. returns digit struct.
   * @param img Reference to Matrix object - an image
   * @return digit struct containing the results
   */
  digit operator () (const Matrix& img);

 private:
  Matrix _weights[MLP_SIZE]; // Array of weights of each layer
  Matrix _biases[MLP_SIZE]; // Array of biases of each layer
};

#endif // MLPNETWORK_H