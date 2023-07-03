#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <numeric>

void straight_merge(std::vector<int>& data) {
    constexpr int step_initial {1};
    bool is_merging_upwards {true};
    auto half_size {data.size() / 2};
    int merge_size {1};

    while (merge_size < half_size) {
        auto step {step_initial};
        auto remaining_merge_items {half_size};
        int first_source_idx, second_source_idx, target_idx, swap_idx;

        if (is_merging_upwards) {
            first_source_idx = 0; 
            second_source_idx = half_size - 1;
            target_idx = half_size;
            swap_idx = 2 * half_size - 1;
        } else {
            target_idx = 0; 
            swap_idx = half_size - 1;
            first_source_idx = half_size; 
            second_source_idx = 2 * half_size - 1;
        }

        while (remaining_merge_items != 0) {
            auto first_source_merge_items {std::min(remaining_merge_items, merge_size)};
            remaining_merge_items -= first_source_merge_items;
            auto second_source_merge_items {std::min(remaining_merge_items, merge_size)};
            remaining_merge_items -= second_source_merge_items;

            while (first_source_merge_items > 0 && second_source_merge_items > 0) {
                if (data[first_source_idx] < data[second_source_idx]) {
                    data[target_idx] = data[first_source_idx]; 
                    target_idx += step; 
                    first_source_idx++; 
                    first_source_merge_items--;
                } else {
                    data[target_idx] = data[second_source_idx];
                    target_idx += step;
                    second_source_idx--;
                    second_source_merge_items--;
                }
            }

            while (second_source_merge_items > 0) {
                data[target_idx] = data[second_source_idx]; 
                target_idx += step; 
                second_source_idx--;
                second_source_merge_items--;
            }

            while (first_source_merge_items > 0) {
                data[target_idx] = data[first_source_idx]; 
                target_idx += step; 
                first_source_idx++;
                first_source_merge_items--;
            }

            step = -step; 
            std::swap(target_idx, swap_idx);
        }

        is_merging_upwards = !is_merging_upwards; 
        merge_size *= 2;
    }
    
    if (!is_merging_upwards) {
        std::copy(data.begin() + half_size, data.begin() + 2*half_size, data.begin());
    }
}

int main() {
    constexpr auto half_size {10};
    std::vector<int> data(2*half_size);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 99);

    // Fill the array with some data
    std::generate(data.begin(), data.end(), [&]() { return dis(gen); });

    // Print unsorted array
    std::cout << "Unsorted array: \n";
    for (const auto& num : data) {
        std::cout << num << ' ';
    }
    std::cout << '\n';

    // Sort the array
    straight_merge(data);

    // Print sorted array
    std::cout << "Sorted array: \n";
    for (const auto& num : data) {
        std::cout << num << ' ';
    }
    std::cout << '\n';

    return 0;
}

