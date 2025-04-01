#ifndef VECTOR_UTILS_H
#define VECTOR_UTILS_H

#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <random>
#include <numeric>
#include <iterator>

template <typename T>
void shuffleVector(std::vector<T>& vec) {
    std::random_shuffle(vec.begin(), vec.end());
}

template <typename T>
void rotateVector(std::vector<T>& vec, int steps) {
    std::rotate(vec.begin(), vec.begin() + steps, vec.end());
}

template <typename T>
std::vector<T> vectorUnion(const std::vector<T>& vec1, const std::vector<T>& vec2) {
    std::vector<T> result = vec1;
    result.insert(result.end(), vec2.begin(), vec2.end());
    std::sort(result.begin(), result.end());
    result.erase(std::unique(result.begin(), result.end()), result.end());
    return result;
}

template <typename T>
std::vector<T> vectorIntersection(const std::vector<T>& vec1, const std::vector<T>& vec2) {
    std::vector<T> result;
    std::set_intersection(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), std::back_inserter(result));
    return result;
}

template <typename T>
std::vector<T> vectorDifference(const std::vector<T>& vec1, const std::vector<T>& vec2) {
    std::vector<T> result;
    std::set_difference(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), std::back_inserter(result));
    return result;
}

template <typename T>
T accumulateSum(const std::vector<T>& vec) {
    return std::accumulate(vec.begin(), vec.end(), T(0));
}

template <typename T>
T accumulateProduct(const std::vector<T>& vec) {
    return std::accumulate(vec.begin(), vec.end(), T(1), std::multiplies<T>());
}

template <typename T>
T calculateMean(const std::vector<T>& vec) {
    return accumulateSum(vec) / static_cast<T>(vec.size());
}

template <typename T>
T calculateMedian(std::vector<T>& vec) {
    std::sort(vec.begin(), vec.end());
    size_t size = vec.size();
    if (size % 2 == 0) {
        return (vec[size / 2 - 1] + vec[size / 2]) / 2;
    } else {
        return vec[size / 2];
    }
}

template <typename T>
T calculateMode(const std::vector<T>& vec) {
    std::unordered_map<T, int> frequencyMap;
    for (const auto& val : vec) {
        frequencyMap[val]++;
    }

    T mode;
    int maxCount = 0;
    for (const auto& entry : frequencyMap) {
        if (entry.second > maxCount) {
            maxCount = entry.second;
            mode = entry.first;
        }
    }
    return mode;
}

template <typename T>
std::unordered_map<T, int> frequencyMap(const std::vector<T>& vec) {
    std::unordered_map<T, int> frequencyMap;
    for (const auto& val : vec) {
        frequencyMap[val]++;
    }
    return frequencyMap;
}

template <typename T>
void printVector(const std::vector<T>& vec) {
    for (const auto& val : vec) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

template <typename T>
T maxSubArraySum(const std::vector<T>& vec) {
    T maxSoFar = vec[0];
    T maxEndingHere = vec[0];

    for (size_t i = 1; i < vec.size(); ++i) {
        maxEndingHere = std::max(vec[i], maxEndingHere + vec[i]);
        maxSoFar = std::max(maxSoFar, maxEndingHere);
    }

    return maxSoFar;
}

#endif // VECTOR_UTILS_H