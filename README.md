<div align="center">
    <h1>HBench</h1>
    <p>Small library for benchmarking your code</p>
</div>
<br/>

# Contents
- [About project](#about-project)
- [Installation](#installation)
- [Some features](#some-features)
- [Functionality](#functionality)
    - [BENCH](#benchstatement)
    - [BENCHN](#benchstatement)
    - [ALLOCATE_SLOTS](#allocate_slotsnum)
    - [SET_SLOT_NAME](#set_slot_nameslot-name)
    - [BENCH_SLOT](#bench_slotslot-statement)

## About project
This is a small header-only library for benchmarking your code. It can measure execution time to within 1ms. Also its safe-threaded, so, assuming functions are one-threaded - you can use multiple slots for multiple benchmarks, running at the same time.

## Installation
1. Download main header [hbench.hpp](hbench.hpp).
2. Save it somewhere in your project, and include.
3. Voila - write benchmarks now.

## Some features
1. Thread-safe output: one output wont work at the same time as second.
2. High performance of library itself: it wont slow down your benchmarks, and uses high-precision timers.

## Functionality

### BENCH(statement)
Most basic bench. Executes passed statement and measures time.  
Example:
```c++
void long_func() {
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
}
int main() {
    BENCH(long_func());
}
```
Possible output:
```
[ START ] Starting benchmark of statement [ long_func() ]
[  END  ] Finished benchmark of statement [ long_func() ]
[ TOTAL ] 500ms
```
### BENCHN(statement, name)
Same basic bench, but allows you to set custom name.  
Example:
```c++
void long_func() {
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
}
int main() {
    BENCH(long_func(), "Bench 1");
}
```
Possible output:
```
[ START ] Starting benchmark Bench 1
[  END  ] Finished benchmark Bench 1
[ TOTAL ] 500ms
```

### ALLOCATE_SLOTS(num)
Allows you to reserve specified number of slots for multithreaded benchmarks.  
Example:
```c++
int main() {
    ALLOCATE_SLOTS(5); // Exactly five slots will be allocated
}
```

### SET_SLOT_NAME(slot, name)
Allows you to set custom name for specified slot.  
Example:
```c++
int main() {
    ALLOCATE_SLOTS(5);
    SET_SLOT_NAME(1, "Benchmark slot 1"); // Sets name for first slot
}
```

### BENCH_SLOT(slot, statement)
Grabs name from specified slot and runs benchmark. Remember, it checks if slot is not already working, and if it does, program will crash.  
Example:
```c++
void long_func() {
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
}
int main() {
    ALLOCATE_SLOTS(5);
    SET_SLOT_NAME(1, "Bench 1");
    BENCH_SLOT(1, long_func());
}
```
Possible output:
```
[ START ] Starting benchmark Bench 1
[  END  ] Finished benchmark Bench 1
[ TOTAL ] 500ms
```