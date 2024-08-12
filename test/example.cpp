#include <chrono>
#include <hbench.hpp>
#include <thread>

void long_func1() {
  std::this_thread::sleep_for(std::chrono::milliseconds(500));
}

void long_func2() {
  std::this_thread::sleep_for(std::chrono::milliseconds(500));
}

void bench1() { BENCH_SLOT(1, long_func1()); }

void bench2() { BENCH_SLOT(2, long_func2()); }

int main() {
  BENCH(long_func1());
  BENCHN(long_func1(), "Bench 1");
  ALLOCATE_SLOTS(5);
  SET_SLOT_NAME(1, "Bench1");
  SET_SLOT_NAME(2, "Bench2");
  std::thread thr1{bench1};
  std::thread thr2{bench2};
  thr1.join();
  thr2.join();
}