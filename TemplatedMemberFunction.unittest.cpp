#include <cstdint>
#include <iostream>
#include <vector>

#include <gtest/gtest.h>


template<typename T>
class MessageDispatcher
{
public:

	MessageDispatcher(T& t):
		m_t(t)
	{
	}

	template<typename M>
	void Dispatch(const M& m)
	{
		m_t.HandleMessage(m);
	}

private:
	T& m_t;
};


class MyClass: public MessageDispatcher<MyClass>
{
public:
	MyClass():
		MessageDispatcher<MyClass>(*this)
	{
	}

	void HandleMessage(int i)
	{
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}

	void HandleMessage(long p)
	{
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}

	void ProcessMessage(/*const std::vector<std::uint8_t>& bytes*/)
	{
		Dispatch<int>(1);
		Dispatch<long>(5L);
	}
};


TEST(MyClass, Exercise)
{
	MyClass mc;

	mc.ProcessMessage();
}


// testing template member specializations
template <typename T>
class Numbers
{
public:

    template<typename U>
    U get()
    {
        return U(0);
    }
};


template<> template<>
int Numbers<int>::get<int>()
{
    return 1;
}


template<> template<>
float Numbers<int>::get<float>()
{
    return 2.0;
}


template<> template<>
int Numbers<float>::get<int>()
{
    return 3;
}


template<> template<>
float Numbers<float>::get<float>()
{
    return 4.0;
}


TEST(Numbers, ExerciseInt)
{
	Numbers<int> n;

	ASSERT_EQ(1, n.get<int>());
	ASSERT_EQ(2.0, n.get<float>());
}


TEST(Numbers, ExerciseFloat)
{
	Numbers<float> n;

	ASSERT_EQ(3, n.get<int>());
	ASSERT_EQ(4.0, n.get<float>());
}


TEST(Numbers, ExerciseAny)
{
	Numbers<short> n;

	ASSERT_EQ(0, n.get<int>());
	ASSERT_EQ(0.0, n.get<float>());
}

