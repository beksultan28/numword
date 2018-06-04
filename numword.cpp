#include "numword.h"

using namespace nw;

/**
 * Calculates fraction and rounds down to an integer
 * Example:
 *  1) 42 / 10 => 4
 *  2) 500122 / 1000 => 500
*/
lli NumWord::getFraction(const lli num, const lli denom) const
{
    return (num - (num % denom)) / denom;
}

void NumWord::appendBuf(const char *num_str, const char *word = nullptr)
{
    if (!_buf.empty())
    {
        _buf += _hyphen_flag ? _hyphen : _space;
        _hyphen_flag = false;
    }
    _buf += num_str;
    if (word)
    {
        _buf += _space;
        _buf += word;
    }
}

lli NumWord::operator=(const lli num)
{
    setNum(num);
    return getNum();
}

const char *NumWord::words()
{
    return words(_num);
}

const char *NumWord::words(const lli num)
{
    if (num > MAX_NUMBER)
        return "Error: too big number";
    if (num < MIN_NUMBER)
        return "Error: too small number";

    _buf.clear();
    _hyphen_flag = false;
    lli n = num;

    if (n < 0)
    {
        appendBuf(negative);
        n = -n;
    }

    if (n == 0)
    {
        appendBuf(singles[n]);
        return _buf.c_str();
    }

    // Powers of thousand
    if (n >= 1000)
    {
        for (int i = 5; i > 0; --i)
        {
            lli power = pow(1000, i);
            lli _n = getFraction(n, power);
            if (_n)
            {
                int index = i;
                NumWord _nw(_n);
                appendBuf(_nw.words(), powers_of_thousand[index]);
                n -= _n * power;
            }
        }
    }

    // Hundreds
    if (n >= 100 && n < 1000)
    {
        lli _n = getFraction(n, 100);
        NumWord _nw(_n);
        appendBuf(_nw.words(), hundred);
        n -= _n * 100;
    }

    // Tens
    if (n >= 20 && 100)
    {
        lli _n = getFraction(n, 10);
        appendBuf(tens[_n]);
        n -= _n * 10;
        _hyphen_flag = true;
    }

    // Teens
    if (n >= 10 && n < 20)
    {
        appendBuf(teens[n - 10]);
        n -= 0;
    }

    // Singles
    if (n > 0 && n < 10)
    {
        appendBuf(singles[n]);
    }

    return _buf.c_str();
}
