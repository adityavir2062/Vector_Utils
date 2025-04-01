#include "VectorUtils.h"  // Include the header file
#include <iostream>
#include <vector>

int main() {
    // 1. Testing shuffleVector
    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::cout << "Original Vector: ";
    printVector(vec);
    
    shuffleVector(vec);  // Shuffle the vector
    std::cout << "Shuffled Vector: ";
    printVector(vec);
    
    // 2. Testing rotateVector
    rotateVector(vec, 2);  // Rotate the vector by 2 positions
    std::cout << "Rotated Vector (by 2): ";
    printVector(vec);
    
    // 3. Testing vectorUnion
    std::vector<int> vec2 = {4, 5, 6, 7};
    std::vector<int> unionVec = vectorUnion(vec, vec2);
    std::cout << "Union of Vectors: ";
    printVector(unionVec);
    
    // 4. Testing vectorIntersection
    std::vector<int> intersectionVec = vectorIntersection(vec, vec2);
    std::cout << "Intersection of Vectors: ";
    printVector(intersectionVec);
    
    // 5. Testing vectorDifference
    std::vector<int> differenceVec = vectorDifference(vec, vec2);
    std::cout << "Difference of Vectors: ";
    printVector(differenceVec);
    
    // 6. Testing accumulateSum
    std::cout << "Sum of Vector: " << accumulateSum(vec) << std::endl;
    
    // 7. Testing accumulateProduct
    std::cout << "Product of Vector: " << accumulateProduct(vec) << std::endl;
    
    // 8. Testing calculateMean
    std::cout << "Mean of Vector: " << calculateMean(vec) << std::endl;

    // 9. Testing calculateMedian
    std::vector<int> medianVec = {1, 2, 3, 4, 5};
    std::cout << "Test Case Vector for Median: " ;
    printVector(medianVec);
    std::cout << "Median of Vector: " << calculateMedian(medianVec) << std::endl;

    // 10. Testing calculateMode
    std::vector<int> modeVec = {1, 2, 2, 3, 3, 3};
    std::cout << "Test Case Vector for Mode: " ;
    printVector(modeVec);

    std::cout << "Mode of Vector: " << calculateMode(modeVec) << std::endl;

    // 11. Testing frequencyMap
    std::unordered_map<int, int> freqMap = frequencyMap(modeVec);
    std::cout << "Test Case Vector for Frequency Count: ";
    printVector(modeVec);
    std::cout << "Frequency Map: " << std::endl;

    for (const auto& pair : freqMap) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    // 12. Testing maxSubArraySum
    std::vector<int> maxSubVec = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    std::cout << "Test Case Vector for Maximum SubArray Sum: ";
    printVector(maxSubVec);
    std::cout << "Max Subarray Sum: " << maxSubArraySum(maxSubVec) << std::endl;

    return 0;
}
