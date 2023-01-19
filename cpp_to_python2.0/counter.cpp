//
// Created by daany on 1/18/2023.
//

#include "counter.h"
#include <iostream>
#include <pybind11/pybind11.h>
namespace py = pybind11;

void count_to_million() {
    for (int i = 0; i < 1000001; ++i){
        std::cout << i << std::endl;
    }
};



PYBIND11_MODULE(mymodule, m) {
m.doc() = "pybind11 example plugin"; // optional module docstring
m.def("count_to_million", &count_to_million, "a  function that counts to a million in cpp");
}

