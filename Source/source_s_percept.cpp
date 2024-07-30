#include <iostream>
#include <vector>

#include "s_percept.h"

void test_printer() {
    std::cout << "include, print correctly!";
    std::cout << std::endl;
}

//constructor
Perceptron::Perceptron(std::string file_path)
    : data_path(file_path)
    {
        
    }
Perceptron::~Perceptron(){}


