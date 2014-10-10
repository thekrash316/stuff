#include <iostream>

#include <gtest/gtest.h>


template<typename T>
const T& max(const T& a, const T& b)
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;

	return (a > b)? a : b;
}


const int& max(const int& a, const int& b)
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;

	return (a > b)? a : b;
}


template<typename T>
const T* max(const T* a, const T* b)
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;

	return (*a > *b)? a : b;
}


TEST(FuncTemplateTest, Exercise)
{
	ASSERT_EQ(5, max(4, 5));

	ASSERT_EQ(4.5, max(4.5, 3.5));

	ASSERT_EQ(6, max<int>(5, 6));

	int a = 5, b = 6;

	ASSERT_EQ(&b, max<int>(&a, &b));
}
