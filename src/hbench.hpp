#include <chrono>
#include <iostream>

namespace _hbench_internal {
    using s_clock = std::chrono::steady_clock;
    static constexpr char CGREEN[] = "\x1b[32m";
    static constexpr char CRESET[] = "\x1b[0m";

    struct _hbench {
        std::chrono::time_point<s_clock> start, end;
    };
    _hbench _hbench_obj;

    void _print_time(std::string_view statement) {
        std::cout << CGREEN
                  << "Time elapsed for statement [ "
                  << statement 
                  << " ]: "
                  << std::chrono::duration_cast<std::chrono::milliseconds>(_hbench_obj.end - _hbench_obj.start).count()
                  << "ms"
                  << CRESET
                  << std::endl;
    }
}

#define BENCH(statement) \
        _hbench_internal::_hbench_obj.start = _hbench_internal::s_clock::now();     \
        statement;                                                                  \
        _hbench_internal::_hbench_obj.end = _hbench_internal::s_clock::now();       \
        _hbench_internal::_print_time(#statement);