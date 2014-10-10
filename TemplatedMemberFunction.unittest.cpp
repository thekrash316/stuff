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
