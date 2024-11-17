#include <stdio.h>

#define OUT_SIZE 10

double relu(double);
double linear_scalar(double, double, double);

typedef struct list
{
    void *data;
    int capacity;
    int size;
    void (*append) (void *item, struct list *self);
} list;

void append_d(void *x, list *l)
{
    ((double *)l->data)[l->size++] = *(double *)x;
}

void append_i(void *x, list *l)
{
    ((int *)l->data)[l->size++] = *(int *)x;
}


double linear(double *weights, double input)
{

    double y = weights[0] +
               weights[1] * relu(linear_scalar(weights[5], weights[4], input)) +
               weights[2] * relu(linear_scalar(weights[7], weights[6], input)) +
               weights[3] * relu(linear_scalar(weights[9], weights[8], input));

    return y;
}

double linear_scalar(double slope, double intercept, double input)
{
    return input * slope + intercept;
}

double relu(double x)
{
    if (x < 0)
        return 0;

    return x;
}

void print_list_double(list *l)
{
    printf("Capacity: %d\n", l->capacity);
    printf("Size: %d\n", l->size);
    printf("Elements:\n");
    int i;
    for (i = 0; i < l->size; i++)
    {
        printf("%.2lf ", ((double *)l->data)[i]);
    }
    printf("\n");
}

void print_list_int(list *l)
{
    printf("Capacity: %d\n", l->capacity);
    printf("Size: %d\n", l->size);
    printf("Elements:\n");
    int i;
    for (i = 0; i < l->size; i++)
    {
        printf("%d ", ((int *)l->data)[i]);
    }
    printf("\n");
}

int main(int argc, char **argv)
{
    double slope, intercept, x;
    double weights[] = {1, 0.5, -0.2, 0.7, 1, 0.3, 1, 0.4, 1, 0.5};

    double data_d[2];
    list ld = {data_d, 2, 0, append_d};

    double a = 0.5;
    ld.append(&a, &ld);

    print_list_double(&ld);


    int data_i[2];
    list li = {data_i, 2, 0, append_i};

    int b = 10;
    li.append(&b, &li);
    
    print_list_int(&li);


    double y;
    y = linear(weights, 1);

    return 0;
}