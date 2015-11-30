#include <gtest/gtest.h>

#include <list>

using namespace std;


TEST(std_list, exercise)
{
    {
        list<int> l{1, 2, 3};

        ASSERT_EQ(3, l.size());

        list<int> lCopied(l);

        ASSERT_EQ(3, lCopied.size());
    }

    {
        list<int> l(3, 5);

        ASSERT_EQ(3, l.size());

        list<int> lMoved(move(l));

        ASSERT_EQ(0, l.size());
        ASSERT_EQ(3, lMoved.size());
    }

    {
        int arr[] = {1, 2, 3, 4, 5};
        list<int> l(arr + 2, arr + 4);

        ASSERT_EQ(2, l.size());

        list<int> lExpected{3, 4};

        ASSERT_EQ(lExpected, l);
    }
}


TEST(std_list, exercise2)
{
    {
        list<int> l{4, 6, 2, 8, 7, 9};
        list<int> lOther{1, 5, 3, 9, 2, 0};

        l.sort();
        lOther.sort();

        l.merge(lOther);

        list<int> lExpected{0, 1, 2, 2, 3, 4, 5, 6, 7, 8, 9, 9};

        ASSERT_EQ(lExpected, l);
    }

    {
        list<int> l{1, 2, 3, 4, 5};
        list<int> lOther{10, 20, 30, 40, 50};

        l.splice(++l.begin(), lOther, ++++lOther.begin(), --lOther.end());

        list<int> lExpected{1, 30, 40, 2, 3, 4, 5};

        ASSERT_EQ(lExpected, l);

        list<int> lExpectedOther{10, 20, 50};
        ASSERT_EQ(lExpectedOther, lOther);
    }
}
