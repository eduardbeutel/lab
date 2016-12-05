#include <gtest/gtest.h>
#include <string_enum.hpp>

static std::string const STATE_STRINGS[] = { "Connected", "Connecting", "NotConnected", "Error" };
#define NR_OF_STATES 4
string_enum(State, 
	Connected, 
	Connecting, 
	NotConnected, 
	Error
);

TEST(string_enum, check_size) {
	ASSERT_EQ(NR_OF_STATES, size(State()));
}

TEST(string_enum, iterate_and_check_conversion_to_and_from_string) {
	unsigned int j = 0;
	for (const auto& state : State()) {
        auto& stateString = STATE_STRINGS[int(state)];
		ASSERT_EQ(stateString, to_string(state));
        ASSERT_EQ(state,from_string(stateString));
	}	
}
