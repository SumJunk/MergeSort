#include <iostream>
#include <vector>
#include <random>
#include <chrono>

std::vector<int> generateData(size_t n) {
    std::vector<int> nums(n);
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<> dist(0, 1000000);

    for (size_t i = 0; i < n; i++) {
        nums[i] = dist(rng);
    }

    return nums;
}

void mergeHalves(std::vector<int>& nums, int low, int mid, int high) {
    int i = low, j = mid + 1;
    std::vector<int> temp;

    while (i <= mid && j <= high) {
        if (nums[i] <= nums[j]) {
            temp.push_back(nums[i++]);
        } else {
            temp.push_back(nums[j++]);
        }
    }

    while (i <= mid) {
        temp.push_back(nums[i++]);
    }

    while (j <= high) {
        temp.push_back(nums[j++]);
    }

    for (int k = 0; k < temp.size(); k++) {
        nums[low + k] = temp[k];
    }
}

void sort(std::vector<int>& nums, int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;
        sort(nums, low, mid);
        sort(nums, mid + 1, high);
        mergeHalves(nums, low, mid, high);
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <size>\n";
        return 1;
    }

    long n = std::strtol(argv[1], nullptr, 10);

    std::vector<int> nums = generateData(n);

    auto t1 = std::chrono::high_resolution_clock::now();
    sort(nums, 0, nums.size() - 1);
    auto t2 = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> duration = t2 - t1;

    std::cout << "Time taken to sort array of size " << n << ": " << duration.count() << " seconds\n";

    return 0;
}