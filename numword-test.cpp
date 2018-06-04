#include <cstdio>
#include "numword.h"

using namespace nw;

int main()
{
    NumWord converter;
    long long int n;
    n = 0;
    printf("n is %lld, %s\n", n, converter.words(n));
    n = -1;
    printf("n is %lld, %s\n", n, converter.words(n));
    n = 11;
    printf("n is %lld, %s\n", n, converter.words(n));
    n = 42;
    printf("n is %lld, %s\n", n, converter.words(n));
    n = 1474142398007;
    printf("n is %lld, %s\n", n, converter.words(n));
    n = 999999999999999999;
    printf("n is %lld, %s\n", n, converter.words(n));
    n = -999999999999999999;
    printf("n is %lld, %s\n", n, converter.words(n));
    n = 1000000000000000000;
    printf("n is %lld, %s\n", n, converter.words(n));
    return 0;
}
