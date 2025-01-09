#include <iostream>
#include <vector>

#include "s_percept.h"

int main(void)
{
    int epochs = 100;
    // std::string path = "../Data/Single Layer Perceptron Dataset.csv";
    std::string path = "../Data/data.csv";
    Perceptron p = Perceptron(path, epochs);

    return 0;
}