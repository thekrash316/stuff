#include "RomanNumber.h"

unsigned long RomanNumber::Decode(const std::string& s)
{
    unsigned long num = 0;
    int prev = 0;

    char syms[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
    int vals[] = {1, 5, 10, 50, 100, 500, 1000};

    for(std::string::const_reverse_iterator i = s.crbegin(); i != s.crend(); ++i)
    {
        int val = 0;

        for(int j = 0; j < sizeof(syms); ++j)
        {
            if(syms[j] == *i)
            {
                val = vals[j];
                break;
            }
        }

        if(val == 0)
            throw std::invalid_argument(s);

        if(prev != 0)
        {
            if(val < prev)
                num -= val;
            else
                num += val;
        }
        else
            num += val;

        prev = val;
    }

    if(num > 0)
        return num;

    throw std::invalid_argument(s);
}

