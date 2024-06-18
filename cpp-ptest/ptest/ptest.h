#ifndef _PTEST_H
#define _PTEST_H

#include <gmock/gmock.h>
#include <list>
// using the timers from gtest:
#define GTEST_IMPLEMENTATION_ 1
    #include <src/gtest-internal-inl.h>
#undef GTEST_IMPLEMENTATION_

#define PTEST(suite, test) \
    TEST(suite, test )

#define NR_RUNS \
    static std::vector<int> _nr_runs_list
            
#define MEASURE_BASE(function, function_call_line) \
    std::list<testing::TimeInMillis> _##function##_times; \
    for(int i=0; i<_nr_runs_list.size(); i++) { \
        int n = _nr_runs_list[i]; \
        std::string n_string = std::to_string(n); \
        testing::TimeInMillis _##function##_##start_time = testing::internal::GetTimeInMillis(); \
        for (int i = 1; i <= n; i++) { \
            function_call_line \
        } \
        testing::TimeInMillis _##function##_time = testing::internal::GetTimeInMillis() - _##function##_##start_time; \
        RecordProperty( std::string( #function "_" ) + n_string , (int)_##function##_time ); \
        _##function##_times.push_back(_##function##_time); \
    }
    
#define MEASURE(function) \
    MEASURE_BASE(function, function();)

#define MEASURE_IN(function) \
    MEASURE_BASE( function , function(i,n); )
    
#define ASSERT_TIME_LT(first, second) \
    ASSERT_THAT( _##first##_times ,testing::Lt(_##second##_times));
    
#define ASSERT_TIME_GT(first, second) \
    ASSERT_THAT( _##first##_times ,testing::Gt(_##second##_times));

#endif // _PTEST_H
