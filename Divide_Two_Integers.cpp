#include <iostream>
#include <vector>
//#include <vector>
//using namespece std;
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        int sign = (dividend >> 31) + (divisor >> 31);
        if (dividend == INT_MIN && divisor == 1)
        return INT_MIN;
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        if (divisor == 1)
            return dividend;
        if (divisor == -1)
            return -dividend;

        if (dividend == 0)
            return 0;
        if (dividend == divisor)
            return 1;
        if (divisor == 0)
            return INT_MAX;
        //cout << sign << endl;
        if (dividend<divisor && sign == (0))
            return 0;
        long result;
        long den,div;
        den = convert(dividend);
        div = convert(divisor);
        if (den == div)
            return -1;
        if (den<div)
            return 0;
//        cout << den << endl;
//        cout << div << endl;
        //long div = (divisor>0)?divisor:(0-divisor);
        result = long(multiply(den, div));

        //cout << "sign " << sign << endl;
        long r = find_result(den, div, result);
//        cout << r << endl;

        if (sign == -1) {
            r = 0 - r;
        }
//        cout << "result " << result << endl;
//        cout << "r " << r << endl;
        if (r > INT_MAX || r < INT_MIN){
            return INT_MAX;
        }

        return r;


    }

    int multiply(long dividend, long divisor){   //find the appropriate range quickly, each time <<2 is equivalent to multiply 2
//        cout << dividend<< endl;
//        cout << divisor<< endl;
        int i = 0;
        long mul_result = divisor;
        while (mul_result<dividend){
            mul_result = mul_result << long(1);
//            cout << "result " << mul_result<< endl;
            ++i;
//            cout << i<< endl;
        }
//        cout << i;

        return i;
    }

    long find_result(long dividend, long divisor, long i){   //count concreate number from divisor to dividend
        long result = divisor << (i-1);

        if (result * 2 == dividend) {
//            return (2 << i);
            long count;
            count = long(1)<<i;

            return count;
        }
        int j = 0;
        while (result<dividend){
            result += divisor;
//            if (result <)

            ++j;
        }
//        cout << "find_result " << result << endl;
//        cout << "j " << j << endl;
//        cout << i << endl;
        long count = long(1)<<(i-1);
//        cout << "count " << count << endl;
        if (result == dividend)
            count += j;
        else
            count += j-1;


        return count;
    }

    long convert(int dividend) {  //convert dividend and divisor to positive value
        long den;
        if (dividend > 0) {
            den = dividend;
        } else {
            den = dividend;
            den = 0 - den;

        }
        return den;
    }

};

void test(Solution & s){                //Create testcase and test here
    std::vector<int> test_case;
//    test_case.push_back(2);
//    test_case.push_back(0);
//    test_case.push_back(INT_MAX);
//    test_case.push_back(1);
//    test_case.push_back(INT_MIN);
//    test_case.push_back(-1);
//    test_case.push_back(9);
//    test_case.push_back(5);
//    test_case.push_back(-9);
//    test_case.push_back(3);
//
    test_case.push_back(-2147483648);
    test_case.push_back(-3);
    test_case.push_back(-10);
    test_case.push_back(-2);
    test_case.push_back(-1);
    test_case.push_back(1);

    int result = 0;
    for (int i=0; i<test_case.size(); ++i){
        if (i%2 == 1){
//            cout << test_case[i-1] << endl;
//            cout << test_case[i] << endl;
            result = s.divide(test_case[i-1],test_case[i]);
            cout << result << endl;
        }
    }


}



int main() {
    Solution s;

    //test_case[0] = 1;
    //std::cout << INT_MAX << std::endl;
    test(s);
    cout << s.divide(-1,1) << endl;
    return 0;
}




