#include <gtest/gtest.h>

#include <forward_list>

using namespace std;


TEST(stdforward_list, exercise)
{
    {
        forward_list<int> l{1, 2, 3};

        l.insert_after(l.before_begin(), 10);
        l.insert_after(l.begin(), 20);
        l.insert_after(++l.begin(), 30);

        forward_list<int> lExpected{10, 20, 30, 1, 2, 3};

        ASSERT_EQ(lExpected, l);
    }
}

