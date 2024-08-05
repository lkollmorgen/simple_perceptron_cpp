#include <iostream>
#include <vector>

#include "s_percept.h"

int main(void)
{
    int epochs = 3;
    std::string path = "../Data/Single Layer Perceptron Dataset.csv";
    Perceptron p = Perceptron(path, epochs);

    return 0;
}