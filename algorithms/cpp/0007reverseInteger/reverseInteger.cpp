// Source : https://oj.leetcode.com/problems/reverse-integer/
// Author : Ronnie
// Date   : 2016-09-21

/*******************************************************************************
 *
 * Reverse digits of an integer.
 *
 * Example1: x = 123, return 321
 * Example2: x = -123, return -321 
 *
 * Here we need to think some special cases like:
 * 
 * > if the integer's last digit is 0, what should the output be? ie, cases such
 * as 10, 100.
 *
 * > Did you notice that the reversed integer might overflow? Assume the input is
 * a 32-bit integer, then the reverse of 1000000003 overflows. How should we
 * handle such cases? Try exception or other?
 *
 *******************************************************************************/

#include <climits>
#include <cstdio>
#include <cstdlib>
using namespace std;

//#define INT_MAX  numeric_limits<int>::max()
//#define INT_MIN  numeric_limits<int>::min()

class Solution {
public:
    static int reverse(int order) {
        int n;
        int reverse = 0;
        while (order != 0) {
            n = order % 10;
            // over/underflow test
            // Actually, it should be reverse > (int_max-n)/10, but n/10 is 0
            if (reverse > INT_MAX/10 || reverse < INT_MIN/10) {
                return 0;
            }
            reverse = reverse * 10 + n;
            order /= 10;
        }
        return reverse;
    }
};

#define TEST(n ,e) printf("%12d  =>  %-12d    %s!\n", n, Solution::reverse(n), e == Solution::reverse(n)?"passed":"failed") 

int main(int argc, char* argv[]) {
    // basic cases
    TEST(  123,  321);
    TEST( -123, -321);
    TEST( -100,   -1);
    TEST( 1002, 2001);

    // big integer
    TEST( 2147483641,  1463847412);
    TEST(-2147447412, -2147447412);
    TEST( 2147447412,  2147447412);

    // overflow
    TEST( 1000000003, 0);
    TEST( 2147483647, 0);
    TEST(-2147483648, 0);

    // customized cases
    if (argc < 2) {
        return 0;
    }
    printf("\n");
    for (int i = 1; i < argc; i++) {
        int n = atoi(argv[i]);
        printf("%12d  =>  %-12d    %s!\n", n, Solution::reverse(n), Solution::reverse(Solution::reverse(n)) == n?"passed":"failed"); 
    }

    return 0;
}
