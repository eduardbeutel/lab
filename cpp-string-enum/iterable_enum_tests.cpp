#include <gtest/gtest.h>
#include <iterable_enum.hpp>

#define NR_OF_COLORS 4
iterable_enum(Color,
	Red,
	Green,
	Blue,
	White
);

TEST(iterable_enum, check_size) {
	ASSERT_EQ(NR_OF_COLORS, size(Color()));
}

TEST(iterable_enum, iterate_and_check) {
	unsigned int j = 0;
	for (const auto& color : Color()) {
		ASSERT_EQ(j, int(color));
		j++;
	}
	ASSERT_EQ(size(Color()), j);
}
