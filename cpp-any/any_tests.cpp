#include <gtest/gtest.h>
#include <any.hpp>
#include <typeinfo>

TEST(any, empty_on_initialization) {
    any var;
    ASSERT_TRUE(var.empty());
}

TEST(any, declare_and_asign) {
    any var = 2.0;
    ASSERT_EQ(var.value<double>(),2.0);
}

TEST(any, move_constructor) {
    any first = 6;
    any second = std::move(first);
    ASSERT_TRUE(first.empty());
    ASSERT_EQ(second.value<int>(),6);
}

TEST(any, set_get_int_const_value) {
    any var;
    var = 3;
    ASSERT_EQ(var.value<int>(),3);   
    var.setValue(-1);
    ASSERT_EQ(var.value<int>(),-1);
}

TEST(any, set_get_string) {
    std::string name = "goodies";
    any var;
    var = name;
    ASSERT_EQ(var.value<std::string>(),"goodies");
}

TEST(any, type) {
    std::string name = "goodies";
    any var = name;
    ASSERT_EQ(var.type(),typeid(std::string));
}

TEST(any, value_throws_no_data) {
	ASSERT_THROW(any().value<int>(),any::no_data);
}

TEST(any, valueRef_throws_no_data) {
	ASSERT_THROW(any().valueRef<int>(),any::no_data);
}

TEST(any, type_returns_void_if_empty) {
	ASSERT_EQ(any().type(),typeid(void));
}
#ifndef NDEBUG
TEST(any, throws_wrong_type) {
	any var = 3;
	ASSERT_DEATH(var.value<std::string>(),"");
}
#else
TEST(any, throws_wrong_type) {
	any var = 3;
	ASSERT_THROW(var.value<std::string>(), any::wrong_type);
}
#endif
