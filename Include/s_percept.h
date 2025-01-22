// Simple perceptron project
// Laura Kollmorgen
//
// Last updated: 1.21.2025
//
// Directory Path: simple_perceptron/Include
//
// Include file for c++ class for a simple perceptron
//
//
#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <ctime>
#include <cstdlib>

void test_printer();

//class definition
class Perceptron
{
    private:
        int _rows;
        int _cols;
        std::string _data_path;
        bool _verbose;

        std::vector<std::vector<float>> _features;
        std::vector<float> _weights;
        float _bias;
        std::vector<int> _labels;
        std::vector<float> _loss;

        // intermediate values prior to input in activation function
        std::vector<float> _z;
        float _learning_rate = 0.05;
        float _threshold; //later on, calculate the median for the threshold

        std::vector<int> _predictions;

    public:
        Perceptron(std::string _data_path,
                    int _num_epochs, bool _verbose, int _row=0, int _cols=0);
        ~Perceptron();

        //save dimensions of features 
        void save_dims();
        // set features and labels
        void read_data();

        // initiliaze weights as random values from 0-1 and biases as 1
        void init_ws_bs();

        // calculate the intermediate value with current weights/features/biases
        void forward();

        // gather the median of the intermediate values to get the threshhold
        void set_threshold();

        // calculate the predictions using activation function (Heaviside)
        std::vector<int> predict(std::vector<float>&);

        // calculate the adjustment to be made to the weights
        void calc_loss(std::vector<int>&, std::vector<int>&);

        //updates weights(training)
        void update_weights();

        
        //fit model for set number of epochs
        void fit(int);

        void print_accuracy() const;

        //debugging method for viewing weights & biases        
        void print_ws_bs() const;

        //debugging method for viewing feautures
        void print_features() const;

        //debugging method for viewing labels
        void print_labels() const;

        //debugging method for viewing intermediate values (z)
        void print_intermediates() const;

        //debugging method for viewing predicted values
        void print_predictions() const;


};
