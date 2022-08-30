#include "MlpNetwork.h"

// See full documentation in header file

MlpNetwork::MlpNetwork (Matrix *weights, Matrix *biases)
{
  for (int i = 0; i < MLP_SIZE; i++)
    {
      _weights[i] = weights[i];
      _biases[i] = biases[i];
    }
}

digit MlpNetwork::operator() (const Matrix &img)
{
  Dense first (_weights[0], _biases[0], activation::relu);
  Dense second (_weights[1], _biases[1], activation::relu);
  Dense third (_weights[2], _biases[2], activation::relu);
  Dense fourth (_weights[3], _biases[3], activation::softmax);
  Matrix r1 = first (img);
  Matrix r2 = second (r1);
  Matrix r3 = third (r2);
  Matrix r4 = fourth (r3);
  int val = 0;
  float prob = r4[0];
  for (int i = 1; i < r4.get_rows(); i++)
    {
      if (r4[i] > prob)
        {
          prob = r4[i];
          val = i;
        }
    }
  digit result;
  result.value = val;
  result.probability = prob;
  return result;
}