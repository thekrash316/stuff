#include <gtest/gtest.h>
#include <algorithm>
#include <functional>
#include <vector>


long Calculate(const std::vector<int>& nums, std::function<bool (int)> selector, std::function<long (bool, long, int)> op)
{
    long ret = 0;
    bool first = true;

    std::for_each(nums.begin(), nums.end(), [&first, &ret, selector, op] (int n)
        {
            if(selector(n))
            {
                ret = op(first, ret, n);

                if (first)
                {
                    first = false;
                }
            }
        });

    return ret;
}


TEST(LambdaTry, Exercise)
{
    std::vector<int> nums;

    for(int i = 1; i <= 10; ++i)
        nums.push_back(i);

    auto even_selector = [] (int n)
    {
        return (n % 2 == 0)? true: false;
    };

    auto odd_greater_than_6_selector = [] (int n)
    {
        return (n > 6 &&  n % 2 == 1)? true: false;
    };

    auto sum = [](bool first, long lhs, int rhs)
    {
        if (first)
            return (long)rhs;
        return lhs + rhs;
    };

    auto prod = [](bool first, long lhs, int rhs)
    {
        if (first)
            return (long)rhs;
        return lhs * rhs;
    };

    auto sum_of_squares = [](bool first, long lhs, int rhs)
    {
        if (first)
            return (long)rhs*(long)rhs;
        return lhs + rhs*rhs;
    };

 
    ASSERT_EQ(2 + 4 + 6 + 8 + 10, Calculate(nums, even_selector, sum));
    ASSERT_EQ(2 * 4 * 6 * 8 * 10, Calculate(nums, even_selector, prod));
    ASSERT_EQ((7*7)+(9*9), Calculate(nums, odd_greater_than_6_selector, sum_of_squares));
}

