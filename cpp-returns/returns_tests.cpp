#include <gtest/gtest.h>
#include <returns.hpp>

TEST(returns, defines_an_in_function_returns_see_if_it_compiles) {
	returns(int anInt; double aDouble;) var;
	var.anInt = 0;
	var.aDouble = 0;
    ASSERT_EQ(0,var.anInt);
    ASSERT_EQ(0,var.aDouble);
}

returns(std::string name;) say_my_name() {
	return {"zum"};
}

TEST(returns, function_returns_returns_containing_string) {
    auto ret = say_my_name();
    ASSERT_EQ("zum",ret.name);
}

returns(int a; int b;) returns_two_vars() {
    return {2,3};
}

TEST(returns, function_returns_two_variables) {
    auto ret = returns_two_vars();
    ASSERT_EQ(2,ret.a);
    ASSERT_EQ(3,ret.b);
}
