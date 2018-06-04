#ifndef _NUMWORD_H
#define _NUMWORD_H

#include <cstdio>
#include <string>
#include <cmath>

namespace nw {

#define lli long long int
#define MAX_NUMBER 999999999999999999
#define MIN_NUMBER -999999999999999999

const char *negative = "minus";

const char *singles[] = {
    "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

const char *teens[] = {
    "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen",
    "seventeen", "eighteen", "nineteen"};

const char *tens[] = {
    "", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety", "hundred"};

const char *hundred = "hundred";

const char *powers_of_thousand[] = {
    "", "thousand", "million", "billion", "trillion", "quadrillion"};

static const char * _hyphen = "-";
static const char * _space = " ";

/**
 * Class NumWord
 * Converts numbers into string representation
*/
class NumWord
{
    lli _num = 0;
    bool _hyphen_flag = false;
    std::string _buf;
    lli getFraction(const lli num, const lli denom) const;
    void appendBuf(const char *num_str, const char *word);

  public:
    NumWord() : _num(0) {}
    NumWord(const lli num) : _num(num) {}
    ~NumWord() {}
    void setNum(const lli num) { _num = num; }
    lli getNum() const { return _num; }
    lli operator=(const lli num);
    const char *words();
    const char *words(const lli num);
};

} // namespace nw

#endif // _NUMWORD_H
