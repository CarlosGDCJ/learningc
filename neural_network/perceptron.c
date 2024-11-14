#include <stdio.h>

#define OUT_SIZE 10

void linear(double *weights, double *biases, double *input, double *result, int hidden_units, int input_size)
{

    for (int i = 0; i < hidden_units; i++)
    {
        for (int j = 0; j < input_size; j++)
        {
            result[i] += input[j] * weights[i] + biases[i];
        }
    }
}

double relu(double x)
{
    if (x < 0)
        return 0;

    return x;
}


int main(int argc, char** argv)
{
    double slope, intercept, x;
    double weights[] = {0.5, -0.2, 0.7};
    double biases[] = {-3, 1, 5};
    double input[] = {1, 0, 1, 1, 0};

    int hidden_units = sizeof(weights) / sizeof(weights[0]);
    printf("%d\n", hidden_units);

    double result[OUT_SIZE] = {0.0};
    linear(weights, biases, input, result, hidden_units, 5);

    for (int i = 0; i < hidden_units; i++)
    {
        printf("%lf ", result[i]);
    }

    return 0;
}