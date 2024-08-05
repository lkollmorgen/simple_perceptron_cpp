#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

#include "s_percept.h"

//constructor
Perceptron::Perceptron(std::string file_path, int num_epochs, 
                        int rows, int cols)
    : _rows(rows), _cols(cols), _data_path(file_path), _num_epochs(num_epochs),
    _features(rows, std::vector<float>(cols))
    {
        read_data();
    }
Perceptron::~Perceptron(){}

void Perceptron::read_data() {
    std::fstream data_file; //data file to be read
    std::string line;
    std::string s;  //for word-by-word processing
    data_file.open(_data_path);

//get size of data
    //get number of columns
    getline(data_file, line, '\n');
    getline(data_file, line, '\n'); //skip csv header
    std::stringstream ss(line); //split line into stringstream
    getline(ss,s,','); // skip row numbers
    while(getline(ss,s,',')) { _cols++; }

    //get number of rows
    while(getline(data_file, line, '\n')) { _rows++; }
    std::cout << "rows: " << _rows;
    std::cout << ", columns: " << _cols << std::endl;

    //reset position to top of csv
    data_file.close();
    data_file.open(_data_path);
    getline(data_file, line, '\n');
    getline(data_file, line, '\n'); //skip csv header
    getline(ss,s,',');

    while(getline(ss,s,',')) {
        std::cout << s << ' ';
    }
    std::cout << std::endl;
//generate data vector
    _features.resize(_rows, std::vector<float>(_cols));
    for (int i = 0; i < _rows; ++i)
    {
        getline(ss,s,','); // skip row number
        for (int j = 0; j < _cols; ++j)
        {
            std::cout << s << " ";
            _features[i][j] = std::stof(s);
            getline(ss,s,',');
        }
        _labels.push_back(std::stoi(s));
        getline(data_file, line, '\n');
        std::cout << std::endl;
    }
    // print_features();
    // print_labels();
}

void Perceptron::print_features() const {
    for (int i = 0; i < _rows; ++i)
    {
        for (int j = 0; j < _cols; ++j)
        {
            std::cout << _features[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void Perceptron::print_labels() const {
    for (int i = 0; i < _rows; ++i)
    {
        std::cout << _labels[i] << " ";
    }
    std::cout << std::endl;
}

/*
154 void CellularAutomata::initializeGrid()
155 {
156     grid.resize(gridHeight, std::vector<int>(gridWidth));
157     for (int i = 0; i < gridHeight; ++i)
158     {
159         for (int j = 0; j < gridWidth; ++j)
160         {
161             grid[i][j] = initFunc(i, j, num_states);
162         }
163     }
164 }
*/

