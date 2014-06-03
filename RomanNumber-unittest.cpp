#include "RomanNumber.h"

#include <gtest/gtest.h>

TEST(RomanNumberTest, InvalidInput)
{
    ASSERT_THROW(RomanNumber::Decode("ABCD"), std::exception);
}

TEST(RomanNumberTest, Decode)
{
    ASSERT_EQ(4, RomanNumber::Decode("IV"));
    ASSERT_EQ(7, RomanNumber::Decode("VII"));
    ASSERT_EQ(14, RomanNumber::Decode("XIV"));
    ASSERT_EQ(27, RomanNumber::Decode("XXVII"));
    ASSERT_EQ(401, RomanNumber::Decode("CDI"));
    ASSERT_EQ(1954, RomanNumber::Decode("MCMLIV"));
    ASSERT_EQ(1990, RomanNumber::Decode("MCMXC"));
    ASSERT_EQ(2014, RomanNumber::Decode("MMXIV"));
}

