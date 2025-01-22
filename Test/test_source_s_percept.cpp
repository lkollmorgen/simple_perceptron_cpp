#include <iostream>
#include <vector>

#include "s_percept.h"


int main(void)
{
    int epochs = 20;
    bool verbosity = true;
    // std::string path = "../Data/Single Layer Perceptron Dataset.csv";
    // std::string path = "../Data/data.csv";
    std::string path = "../Data/pima_indian_data.csv";
    Perceptron p = Perceptron(path, epochs, verbosity);

    return 0;
}