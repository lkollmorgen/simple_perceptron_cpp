// Simple perceptron project
// Laura Kollmorgen
//
// Last updated: 1.21.2025
//
// Directory Path: simple_perceptron/Source
//
// File holding source scripts to be compiled into a static library
//
//

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include <algorithm>

#include "s_percept.h"

//constructor
Perceptron::Perceptron(std::string file_path, int num_epochs, 
                        bool verb, int rows, int cols)
    : _rows(rows), _cols(cols), _data_path(file_path),
    _features(rows, std::vector<float>(cols)), _verbose(verb)
    {
        //seed random number
        unsigned int seed = 1;
        //change seed to time(0) for random weight generation
        srand (seed);
        save_dims();
        read_data();

        init_ws_bs();

        fit(num_epochs);
    }
Perceptron::~Perceptron(){}

void Perceptron::save_dims() {
    std::fstream data_file; //data file to be read
    std::string line;
    std::string s;  //for word-by-word processing
    data_file.open(_data_path);

//get size of data
    //get number of columns
    getline(data_file, line, '\n');
    // getline(data_file, line, '\n'); //skip csv header
    std::stringstream ss(line); //split line into stringstream
    // getline(ss,s,','); // skip row numbers
    while(getline(ss,s,',')) { _cols++; }
    _cols --; //remove label

    //get number of rows
    while(getline(data_file, line, '\n')) { _rows++; }
    
    if(_verbose){
        std::cout << "rows: " << _rows;
        std::cout << ", columns: " << _cols << std::endl;
    }
}

void Perceptron::read_data() {
    //reset position to top of csv
    std::fstream data_file;
    std::string line;
    std::string s;

    data_file.open(_data_path);
    getline(data_file, line, '\n');
    getline(data_file, line, '\n'); //skip csv header
    
//generate data vector
    _features.resize(_rows, std::vector<float>(_cols));
    for (int i = 0; i < _rows; ++i)
    {
        std::stringstream ss(line); //split line into stringstream
        getline(ss,s,',');
        getline(ss,s,',');
        for (int j = 0; j < _cols; ++j)
        {
            _features[i][j] = std::stof(s);
            getline(ss,s,',');
        }
        _labels.push_back(std::stoi(s));
        getline(data_file, line, '\n');
    }
}

void Perceptron::init_ws_bs() {
    float random_f;
    for(int i = 0; i < _cols; i++){
        random_f = static_cast<float> (rand()) /static_cast<float> (RAND_MAX);
        _weights.push_back(random_f);
    }

    _bias = 1;

    if(_verbose) {
        std::cout << "Initial weights: " << std::endl;
        print_ws_bs();
    }
}

void Perceptron::forward() {
    //generates a new set of intermediates
    _z.clear();
    for(int i = 0; i < _rows; i++) {
        double z = 0;
        for(int j = 0; j <_cols; j++) {
            z += _weights[j] * _features[i][j];
        }
        _z.push_back(z + _bias);
    }  
}

void Perceptron::set_threshold() {
    int n = _z.size();
    std::vector<float> sort_z = _z;
    std::sort(sort_z.begin(), sort_z.end());
    if(n % 2 == 0 ) {
        _threshold = (sort_z[n / 2 - 1] + sort_z[n / 2]) / 2.0;
    }
    else {
        _threshold = sort_z[n / 2];
    }
}

std::vector<int> Perceptron::predict(std::vector<float>& _z) {
    _predictions.clear();
    std::vector<int> results;
    for(float i : _z) {
        if(i > _threshold) results.push_back(1);
        else results.push_back(0);
    }
    return results;
}

void Perceptron::calc_loss(std::vector<int>& p, std::vector<int>& l) {
    _loss.clear();
    for(int i = 0; i < _rows; i++) {
        for(int j = 0; j < _cols; j++) {
            _loss.push_back(l[i] - p[i]);
        }
    }
}

void Perceptron::update_weights() {
    std::vector<float> n_weights;
    for(int i = 0; i < _rows; i++) {
        for(int j = 0; j < _cols; j++) {
            n_weights.push_back( \
                _weights[j] + _learning_rate *_loss[i]* _features[i][j]);
        }
    }
    _weights = n_weights;
}

void Perceptron::fit(int epochs) {
    for(int i = 0; i < epochs; i++) {
        forward();
        set_threshold();
        
        _predictions = predict(_z);
        
        calc_loss(_predictions,_labels);
        update_weights();        
        
        if(_verbose) {
            std::cout << "Epoch " << i << std::endl;
            // print_intermediates();
            // print_predictions();
            // print_labels();
            std::cout << "accuracy: ";
            print_accuracy();
            std::cout << std::endl;
        }
    }
    std::cout << "final accuracy after " << epochs << " epochs: ";
    print_accuracy(); 
}

void Perceptron::print_accuracy() const{
    //init true positive/negative vals, false positive/negative vals
    double tp, tn, fp, fn = 0;
    for(int i = 0; i < _rows; i++) {
        if(_labels[i] == 1) {
            if(_predictions[i] == 1) ++tp;
            else ++fn;
        }
        else {
            if(_predictions[i] == 0) ++tn;
            else ++fp;
        }
    }
    double accuracy = (tp + tn) / (tp + tn + fp + fn);
    std::cout << accuracy << std::endl;
}

void Perceptron::print_ws_bs() const {
    std::cout << "weights: " << std::endl;

    for(auto i : _weights) std::cout << i << " ";
    std::cout << std::endl;

    std::cout << "bias: " << std::endl;
    std::cout << _bias << " " << std::endl;
}

void Perceptron::print_features() const {
    for (int i = 0; i < _rows; ++i) {
        for (int j = 0; j < _cols; ++j) {
            std::cout << _features[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void Perceptron::print_labels() const {
    std::cout << "labels: " << std::endl;
    for(auto i : _labels) std::cout << i << " ";
    std::cout << std::endl;
}

void Perceptron::print_intermediates() const {
    std::cout << "intermediates: " << std::endl;
    for(auto i : _z) std::cout << i << " ";
    std::cout << std::endl;
}

void Perceptron::print_predictions() const {
    std::cout << "predictions: " << std::endl;
    for(auto i : _predictions) std::cout << i << " ";
    std::cout << std::endl;
}


