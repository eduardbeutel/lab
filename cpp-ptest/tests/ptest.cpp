#include <ptest/ptest.h>
#include <list>
using namespace testing;

namespace test_nr_runs_and_measure {

class A {};

void stack_allocation() {
    A a;
}

void heap_allocation() {
    A* a = new A();
}

PTEST(ptest, nr_runs_and_measure) {
    NR_RUNS = {100000,200000,500000};
    MEASURE(stack_allocation);
    MEASURE(heap_allocation);
    ASSERT_TIME_LT(stack_allocation,heap_allocation);
}
    
} // test_nr_runs_and_measure

TEST(ptest, assert_time_macros) {
    std::list<int> _one_times = {1};
    std::list<int> _two_times = {2};
    ASSERT_TIME_LT(one,two);
    ASSERT_TIME_GT(two,one);
}

namespace test_measure_in_and_return_value {

static bool i_ok = true;
static bool n_ok = true;
#define RUNS_100_TIMES 100

void stack_impl(int i, int n) {
    static int last_i = 0;
    auto desired = last_i+1;
    last_i = i;
    if(desired != i) {
        i_ok = false;
    }
    if(n != RUNS_100_TIMES) {
        n_ok = false;
    }
} 

PTEST(ptest, measure_in_and_return_value) {
    NR_RUNS = {RUNS_100_TIMES};
    MEASURE_IN(stack_impl);
    ASSERT_TRUE(i_ok);
    ASSERT_TRUE(n_ok);
}
        
} // test_measure_in_macro_and_return_value

