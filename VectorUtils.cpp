#include "VectorUtils.h"
#include <random>

// 1. Vector Operations
template <typename T>
void shuffleVector(std::vector<T>& vec) {
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(vec.begin(), vec.end(), g);
}

template <typename T>
void rotateVector(std::vector<T>& vec, int steps) {
    std::rotate(vec.begin(), vec.begin() + steps, vec.end());
}

// 2. Multi-Vector Operations
template <typename T>
std::vector<T> vectorUnion(const std::vector<T>& vec1, const std::vector<T>& vec2) {
    std::vector<T> result = vec1;
    for (const T& elem : vec2) {
        if (std::find(result.begin(), result.end(), elem) == result.end()) {
            result.push_back(elem);
        }
    }
    return result;
}

template <typename T>
std::vector<T> vectorIntersection(const std::vector<T>& vec1, const std::vector<T>& vec2) {
    std::vector<T> result;
    for (const T& elem : vec1) {
        if (std::find(vec2.begin(), vec2.end(), elem) != vec2.end()) {
            result.push_back(elem);
        }
    }
    return result;
}

template <typename T>
std::vector<T> vectorDifference(const std::vector<T>& vec1, const std::vector<T>& vec2) {
    std::vector<T> result;
    for (const T& elem : vec1) {
        if (std::find(vec2.begin(), vec2.end(), elem) == vec2.end()) {
            result.push_back(elem);
        }
    }
    return result;
}

// 3. Statistical Operations
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
        return (vec[size / 2 - 1] + vec[size / 2]) / T(2);
    }
    return vec[size / 2];
}

template <typename T>
T calculateMode(const std::vector<T>& vec) {
    std::unordered_map<T, int> freqMap = frequencyMap(vec);
    T mode;
    int maxCount = 0;
    for (const auto& pair : freqMap) {
        if (pair.second > maxCount) {
            mode = pair.first;
            maxCount = pair.second;
        }
    }
    return mode;
}

// 4. Frequency Map
template <typename T>
std::unordered_map<T, int> frequencyMap(const std::vector<T>& vec) {
    std::unordered_map<T, int> freqMap;
    for (const T& elem : vec) {
        freqMap[elem]++;
    }
    return freqMap;
}

// 5. Helper Functions
template <typename T>
void printVector(const std::vector<T>& vec) {
    for (const T& elem : vec) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

// 6. DSA Specific Features 
template <typename T>
T maxSubArraySum(const std::vector<T>& vec) {
    T maxSum = vec[0];
    T currentSum = vec[0];
    for (size_t i = 1; i < vec.size(); ++i) {
        currentSum = std::max(vec[i], currentSum + vec[i]);
        maxSum = std::max(maxSum, currentSum);
    }
    return maxSum;
}

// Explicit instantiation for int
template void shuffleVector<int>(std::vector<int>& vec);
template void rotateVector<int>(std::vector<int>& vec, int steps);
template std::vector<int> vectorUnion<int>(const std::vector<int>& vec1, const std::vector<int>& vec2);
template std::vector<int> vectorIntersection<int>(const std::vector<int>& vec1, const std::vector<int>& vec2);
template std::vector<int> vectorDifference<int>(const std::vector<int>& vec1, const std::vector<int>& vec2);
template int accumulateSum<int>(const std::vector<int>& vec);
template int accumulateProduct<int>(const std::vector<int>& vec);
template int calculateMean<int>(const std::vector<int>& vec);
template int calculateMedian<int>(std::vector<int>& vec);
template int calculateMode<int>(const std::vector<int>& vec);
template std::unordered_map<int, int> frequencyMap<int>(const std::vector<int>& vec);
template void printVector<int>(const std::vector<int>& vec);
template int maxSubArraySum<int>(const std::vector<int>& vec);