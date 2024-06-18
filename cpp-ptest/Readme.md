# ptest

ptest is a C++ performance testing library based on gtest and gmock. 
Its main goal is to have a simple, clean, declarative like API.
You can use it to write performance regression tests.

## Example

Let's say you want to test the performance of heap vs. stack allocation of a class A object.
You first implement each allocation type in a function. 

    #include <ptest/ptest.h>

    class A {};
    
    void stack_allocation() {
        A a;
    }
    
    void heap_allocation() {
        A* a = new A();
    }

Now you can declare your test. 
You have to tell it how many times to run and what to measure.
You can have more than one measure point, that is why NR_RUNS is a list.
Afterwards you can set time expectations via the ASSERT_TIME_* macros.

    PTEST(allocation,stack_vs_heap) {
        NR_RUNS = {100000,200000,500000};
        MEASURE(stack_allocation);
        MEASURE(heap_allocation);
        ASSERT_TIME_LT(stack_allocation,heap_allocation);
    }
    
## Using ptest

### Setup

ptest depends on gmock.
You have to include gmocks root directory (./) and gmocks include directory (./Include).
ptest should have the same compiler support as gmock.

### Writing tests

There is only one rule when writing tests: NR_RUNS before MEASURE* before ASSERT_TIME_*. 
That is the order they have to be declared in a test.

MEASURE() expects a function with no arguments that returns void.

    void zero_arg_function() {
        // code that needs to be performance tested
    }
    
MEASURE_IN() expects a function with two int arguments that returns void.

    void two_arg_function(int i, int n) {
        // code that needs to be performance tested
        // i is the current run
        // n the number of runs
    }

### Compiling tests

Performance tests should be compiled with the release/"production" flags and should run on 
the "production"/end user hardware.

### Running tests

When you run the tests you will only see if they passed or failed. 
The measured times in ms can be found by using:

    --gtest_output=xml:report.xml
    
### Saving tests

You can commit the tests together with the dated report for documentation purposes.
    
## API

- PTEST(suite, test)
- NR_RUNS 
- MEASURE(function)
- MEASURE_IN(function)
- ASSERT_TIME_LT(first, second)
- ASSERT_TIME_GT(first, second)

## ptest development

This is how you get and build ptest. 
ptest uses gmock via [cshelf](https://github.com/eduardbeutel/cshelf).

    git clone --recursive https://github.com/eduardbeutel/ptest
    cd ptest
    mkdir build
    cd build
    cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release ..
    make
    




