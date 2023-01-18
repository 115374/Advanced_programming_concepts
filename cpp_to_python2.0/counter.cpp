//
// Created by daany on 1/18/2023.
//

#include "counter.h"
#include <iostream>
#include <pybind11/pybind11.h>
namespace py = pybind11;

void count_to_billion() {
    std::cout << "the counter is: " << std::endl;
    for (int i = 0; i < 10000; ++i){
        std::cout << i << std::endl;
    }
};

PYBIND11_MODULE(mymodule, m) {
m.doc() = "pybind11 example plugin"; // optional module docstring
m.def("count_to_billion", &count_to_billion, "a  function that counts to a billion in cpp");
}