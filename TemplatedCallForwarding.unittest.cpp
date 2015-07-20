#include <iostream>
#include <string>

#include <gtest/gtest.h>

using namespace testing;

namespace
{

class TargetClass
{
public:
    TargetClass():
        m_callACount( 0 ),
        m_callBCount( 0 ),
        m_callCCount( 0 ),
        m_callDCount( 0 )
    {
    }
    
    void CallA()
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        ++m_callACount;
    }

    void CallB()
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        ++m_callBCount;
    }
    
    void CallC( int a )
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        ++m_callCCount;
    }

    void CallD( int a, const std::string& b )
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        ++m_callDCount;
    }

    int m_callACount;
    int m_callBCount;
    int m_callCCount;
    int m_callDCount;
};

class Caller
{
public:
    
    Caller( TargetClass& tc ):
        m_tc( tc )
    {
    }
    
    Caller( const Caller& ) = delete;
    
    template<typename Object, typename Function, typename... Args>
    void ForwardCall( Object& obj, Function func, Args... args )
    {
        ( obj.*func )( args... );
    }
    

    void CallCallA()
    {
        ForwardCall( m_tc, &TargetClass::CallA );
    }

    void CallCallB()
    {
        ForwardCall( m_tc, &TargetClass::CallB );
    }

    void CallCallC()
    {
        ForwardCall( m_tc, &TargetClass::CallC, 1 );
    }
    
    void CallCallD()
    {
        ForwardCall( m_tc, &TargetClass::CallD, 1, "hello" );
    }

private:
    
    TargetClass& m_tc;
};


TEST( TemplatedCallForwarding, Exercise )
{
    TargetClass tc;
    Caller c( tc );

    ASSERT_EQ( 0, tc.m_callACount );
    ASSERT_EQ( 0, tc.m_callBCount );
    ASSERT_EQ( 0, tc.m_callCCount );
    ASSERT_EQ( 0, tc.m_callDCount );

    c.CallCallA();
    
    ASSERT_EQ( 1, tc.m_callACount );
    ASSERT_EQ( 0, tc.m_callBCount );
    ASSERT_EQ( 0, tc.m_callCCount );
    ASSERT_EQ( 0, tc.m_callDCount );

    c.CallCallB();

    ASSERT_EQ( 1, tc.m_callACount );
    ASSERT_EQ( 1, tc.m_callBCount );
    ASSERT_EQ( 0, tc.m_callCCount );
    ASSERT_EQ( 0, tc.m_callDCount );
    
    c.CallCallC();

    ASSERT_EQ( 1, tc.m_callACount );
    ASSERT_EQ( 1, tc.m_callBCount );
    ASSERT_EQ( 1, tc.m_callCCount );
    ASSERT_EQ( 0, tc.m_callDCount );

    c.CallCallD();
    
    ASSERT_EQ( 1, tc.m_callACount );
    ASSERT_EQ( 1, tc.m_callBCount );
    ASSERT_EQ( 1, tc.m_callCCount );
    ASSERT_EQ( 1, tc.m_callDCount );
}

}