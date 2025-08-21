#include <iostream>
#include <vector>
#include <chrono>

int main() {
    auto start = std::chrono::high_resolution_clock::now();

    // Allocate a vector of size 1e9 + 1 with initial value 0
    std::vector<long long> obj(1'000'000'001, 0);

    for (long long i = 1; i <= 1'000'000'000; ++i) {
        obj[i] += i; // same logic, but way faster and memory-safe
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "Time taken: " << duration.count() << " ms\n";
    return 0;
}
