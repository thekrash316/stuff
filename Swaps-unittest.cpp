#include <gtest/gtest.h>

void swap1(int * a, int * b)
{
    if(a && b)
    {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
}

void swap2(int & a, int & b)
{
    int temp = a;
    a = b;
    b = temp;
}

void swap2_xor(int & a, int & b)
{
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

void swap2_add(int & a, int & b)
{
    a = a + b;
    b = a - b;
    a = a - b;
}

void AssertSwaped1(void (swapper)(int *, int *))
{
    int a = 5, b = 10;
    
    swapper(&a, &b);
    
    ASSERT_EQ(10, a);
    ASSERT_EQ(5, b);

    swapper(&a, &b);
  
    ASSERT_EQ(5, a);
    ASSERT_EQ(10, b);
}

void AssertSwaped2(void (swapper)(int &, int &))
{
    int a = 5, b = 10;
    
    swapper(a, b);
    
    ASSERT_EQ(10, a);
    ASSERT_EQ(5, b);

    swapper(a, b);
  
    ASSERT_EQ(5, a);
    ASSERT_EQ(10, b);
}


TEST(SwapTest, Decode)
{
    ASSERT_NO_FATAL_FAILURE(AssertSwaped1(swap1));

    ASSERT_NO_FATAL_FAILURE(AssertSwaped2(swap2));
    ASSERT_NO_FATAL_FAILURE(AssertSwaped2(swap2_xor));
    ASSERT_NO_FATAL_FAILURE(AssertSwaped2(swap2_add));
}

