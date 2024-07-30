// Simple perceptron project
// Laura Kollmorgen
//
// Last updated: 7/29/24
//
// Directory Path: simple_perceptron/Include
//
// Include file for c++ class for a simple perceptron
//
//
#include <iostream>
#include <vector>

void test_printer();

//class definition
class Perceptron
{
    private:
        //int rows;
        //int cols;
        std::string data_path;
        int num_epochs;

        std::vector<std::vector <float>> features;
        std::vector<float> weights;
        std::vector<float> biases;
        std::vector<int> labels;

        // intermediate values prior to input in activation function
        std::vector<float> z;
        float learning_rate = 0.05;

        std::vector<int> predictions;

    public:
        Perceptron(std::string data_path = "../Data/Single Layer Perceptron Dataset.csv");
        ~Perceptron();

        // set features and labels
        void read_data();

        // initiliaze weights as random values from 0-1 and biases as 1
        void init_ws_bs();

        // calculate the intermediate value with current weights/features/biases
        void forward();

        // calculate the predictions using activation function (Heaviside)
        std::vector<int> predict(std::vector<float>);

        // calculate the adjustment to be made to the weights
        std::vector<float> calc_loss(std::vector<int>, std::vector<int>);

        //updates weights(training)
        void update_weights();

        
        //fit model for set number of epochs
        void fit();

        void print_accuracy() const;

        //debugging method for viewing weights & biases        
        void print_ws_bs() const; 



};
