#include <gtest/gtest.h>

#include <sstream>

using namespace std;


TEST(std_io, extraction_simple)
{
    istringstream iss(" 12 34.5 true foo");

    int i = 0;
    float f = 0.0;
    bool b = false;
    string s;

    iss >> i;

    ASSERT_FALSE(iss.fail());
    ASSERT_FALSE(iss.eof());

    iss >> f >> boolalpha >> b;

    ASSERT_FALSE(iss.fail());
    ASSERT_FALSE(iss.eof());

    iss >> s;

    ASSERT_FALSE(iss.fail());
    ASSERT_TRUE(iss.eof());

    ASSERT_EQ(12, i);
    ASSERT_EQ(34.5, f);
    ASSERT_EQ(true, b);
    ASSERT_EQ("foo", s);
}

TEST(std_io, extraction_when_type_changes)
{
    istringstream iss("34.5 67a");
    int i = 0;
    string s;

    iss >> i;

    ASSERT_FALSE(iss.fail());
    ASSERT_FALSE(iss.eof());

    iss >> s;

    ASSERT_FALSE(iss.fail());
    ASSERT_FALSE(iss.eof());

    ASSERT_EQ(34, i);
    ASSERT_EQ(".5", s);

    iss >> i;

    ASSERT_FALSE(iss.fail());
    ASSERT_FALSE(iss.eof());

    iss >> s;

    ASSERT_FALSE(iss.fail());
    ASSERT_TRUE(iss.eof());

    ASSERT_EQ(67, i);
    ASSERT_EQ("a", s);
}

TEST(std_io, extraction_failures)
{
    istringstream iss("a23");
    int i = 0;

    iss >> i;

    ASSERT_TRUE(iss.fail());
    ASSERT_FALSE(iss.eof());
}

TEST(std_io, extraction_loop)
{
    istringstream iss("1 2 3 4 5");
    int i = 0;
    int sum = 0;

    while(iss >> i)
    {
        sum += i;
    }

    ASSERT_TRUE(iss.fail());
    ASSERT_TRUE(iss.eof());

    ASSERT_EQ(15, sum);
}
