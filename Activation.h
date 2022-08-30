#include "Matrix.h"

#ifndef ACTIVATION_H
#define ACTIVATION_H

typedef Matrix (*ActivationFunc) (const Matrix &x);

/**
 * @namespace activation
 * @brief This namespace holds the activation functions - relu and softmax
 */
namespace activation
{
    /**
     * Calculate and return the result of relu(x)
     * @param x Reference to Matrix object.
     * @return The result of relu(x)
     */
    Matrix relu (const Matrix &x);

    /**
     * Calculate and return the result of softmax(x)
     * @param x Reference to Matrix object.
     * @return The result of softmax(x)
     */
    Matrix softmax (const Matrix &x);
}

#endif //ACTIVATION_H