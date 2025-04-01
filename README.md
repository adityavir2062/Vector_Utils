# Vector Utilities Library

This is a simple library that provides various utility functions for vectors (arrays) in C++. It includes operations like vector shuffling, rotations, multi-vector operations, statistical functions, and more.

## Features

- Shuffle and rotate vectors
- Perform union, intersection, and difference of two vectors
- Calculate sum, product, mean, median, and mode of a vector
- Generate frequency map of elements in a vector
- Find maximum subarray sum
- And more...

## Installation

Simply include the `VectorUtils.h` and `VectorUtils.cpp` files in your project and include `VectorUtils.h` in your main file.

## Example Usage

```cpp
#include "VectorUtils.h"

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::cout << "Sum: " << accumulateSum(vec) << std::endl;
    return 0;
}
