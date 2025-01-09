
## Simple Perceptron C++ Implementation
## Laura Kollmorgen(Jones)
####
### Summary
This project showcases a c++ class implementation of a simple perceptron with a sample usage
## Usage
_in /Test:_
```
make all 
```

## Updates
1/8/2025:
- completed all functions to complete the simple perceptron
- removed '1' feature from sample data
- achieved max of `.670` accuracy after `150` epochs

8/16/2024:
- class can correctly save data into private members
- separated dimension-evaluation script into separate save_dims function

8/5:
- working through read_data bug
- created print_features and print_labels functions for debugging

8/1:
- updated makefiles for cleaning objects/executables
- began implementation of read_data in `source_s_percept.cpp`
    - functionality to gather size of vector from .csv

7/29:
- created directories
- `s_percept.h` class outline
- included single layer perceptron sample dataset
- began class method implementaion in `source_s_percept.cpp` 


## TODO
- double check weight update function
- double check heaviside function
- update to cmake

## Sources
#### Dataset
The dataset was downloaded from Kaggle user Abir Hasan from [this page](https://www.kaggle.com/datasets/abirhasan1703100/single-layer-perceptron-datasetsmall?resource=download)
#### Single Layer Perceptron Theory
https://www.geeksforgeeks.org/what-is-perceptron-the-simplest-artificial-neural-network/#
#### Reading CSV file
https://stackoverflow.com/questions/1120140/how-can-i-read-and-parse-csv-files-in-c

