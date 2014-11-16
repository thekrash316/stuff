#include <gtest/gtest.h>

template<class A, class B>
bool IsLess(A a, B b)
{
	if(a < b)
	{
		std::cout << "(a < b) for " << " a:" << a << ", b:" << b << std::endl;
		return true;
	}
	else
	{
		std::cout << "(a >= b) for " << " a:" << a << ", b:" << b << std::endl;
		return false;
	}
}

TEST(Conversion, Sizes)
{
	std::cout << "sizeof(long):" << sizeof(int) << " sizeof(long):" << sizeof(long) << std::endl;

	// assert sizes
	ASSERT_EQ(4, sizeof(int));
	ASSERT_EQ(8, sizeof(long));
}

TEST(Conversion, SignedToUnsigned)
{
	// int and unsigned int have equal rank
	int a1 = -1, a2 = 0, a3 = 1;
	unsigned b = 5;

	// a is converted to unsigned int
	ASSERT_FALSE(IsLess(a1, b)); // -1 becomes a large value
	ASSERT_TRUE(IsLess(a2, b));
	ASSERT_TRUE(IsLess(a3, b));
}

TEST(Conversion, UnsignedToSigned)
{
	// long long has greater rank than unsigned int
	unsigned a1 = 4294967295, a2 = 0, a3 = 1;
	long b1 = 5, b2 = 4294967296ll;

	// a is converted to long long
	ASSERT_FALSE(IsLess(a1, b1)); // -1 becomes a large value
	ASSERT_TRUE(IsLess(a2, b1));
	ASSERT_TRUE(IsLess(a3, b1));
	ASSERT_TRUE(IsLess(a1, b2)); // -1 becomes a large value
}
