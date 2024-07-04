#include <chrono>
#include <thread>
#include <hbench.hpp>

void long_func() {
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
}

int main() {
    BENCH(long_func());
}