#ifndef VECTORUTILS_H
#define VECTORUTILS_H

// Libraries imported!
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <iostream>

// 1. Vector Operations
template <typename T>
void shuffleVector(std::vector<T>& vec);

template <typename T>
void rotateVector(std::vector<T>& vec, int steps);

// 2. Multi-Vector Operations
template <typename T>
std::vector<T> vectorUnion(const std::vector<T>& vec1, const std::vector<T>& vec2);

template <typename T>
std::vector<T> vectorIntersection(const std::vector<T>& vec1, const std::vector<T>& vec2);

template <typename T>
std::vector<T> vectorDifference(const std::vector<T>& vec1, const std::vector<T>& vec2);

// 3. Statistical Operations
template <typename T>
T accumulateSum(const std::vector<T>& vec);

template <typename T>
T accumulateProduct(const std::vector<T>& vec);

template <typename T>
T calculateMean(const std::vector<T>& vec);

template <typename T>
T calculateMedian(std::vector<T>& vec);

template <typename T>
T calculateMode(const std::vector<T>& vec);

// 4. Frequency Map
template <typename T>
std::unordered_map<T, int> frequencyMap(const std::vector<T>& vec);

// 5. Helper Functions
template <typename T>
void printVector(const std::vector<T>& vec);

// 6. DSA Specific Features 
template <typename T>
T maxSubArraySum(const std::vector<T>& vec);

#endif // VECTORUTILS_H