#include <gtest/gtest.h>

#include <string>
#include <sstream>

using namespace std;


TEST(std_string, exercise)
{
    {
        string s("hello\0there");

        ASSERT_EQ(5, s.size());
        ASSERT_EQ("hello", s);
        ASSERT_EQ(string("hello"), s.c_str());
    }
    {
        string s("hello\0there", 11);

        ASSERT_EQ(11, s.size());
        ASSERT_EQ(string("hello\0there", 11), s);
        ASSERT_EQ(string("hello"), s.c_str());
    }
}

TEST(std_string, find)
{
    string s("hello there hello");

    ASSERT_EQ(3, s.find("lo"));
    ASSERT_EQ(12, s.find("hel", 1));
    ASSERT_EQ(6, s.find('t'));


    ASSERT_EQ(1, s.find_first_of("aeiou"));
    ASSERT_EQ(0, s.find_first_not_of("aeiou"));

    ASSERT_EQ(16, s.find_last_of("aeiou"));
    ASSERT_EQ(15, s.find_last_not_of("aeiou"));
}

TEST(std_string, to)
{
    {
        string s("1.23");
        size_t n = 0;

        ASSERT_EQ(1, stoi(s, &n));
        ASSERT_EQ(1, n);
        ASSERT_FLOAT_EQ(1.23, stof(s, &n));
        ASSERT_EQ(4, n);
    }

    {
        string s("4a");

        ASSERT_EQ(4, stoi(s));

    }
}

TEST(std_string, getline)
{
    istringstream iss("1\n2\n3\n4\n5\n");
    int sum = 0;

    for(string line; getline(iss, line);)
    {
        sum += stoi(line);
    }

    ASSERT_EQ(15, sum);
}
