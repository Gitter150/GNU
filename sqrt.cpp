#include <iostream>

int intSqrt(long long num) {
    if(num < 0) return -1;
    if(num <= 1) return num;
    long long min = 1, max = num, res, mid;
    while(min <= max) {
        mid = (min + max) / 2;
        if(mid <= num / mid) {
            min = mid + 1;
            res = mid;
        }  
        else {
            max = mid - 1;
        }
    }
    return res;
}

long long intPow(int base, int exp) {
    if(exp == 0) return 1;
    if(base <= 1 || exp == 1) return base;
    long long res = 1;
    for(int i=0; i < exp; i++) res *= base;
    return res;
}

float sqrt(long long num, int prec = 3) { 
    if(num < 0) return -1;
    if(num <= 1) return num;
    long long scale = intPow(10, prec);
    return (float) intSqrt(num * scale * scale) / scale;
}

int main() {
    // make sure num is less than ~9.22 trillion for the default sqrt to work
    long long num;
    std::cout << "Enter the number: ";
    std::cin >> num;
    std::cout << "The integer square root of " << num << " is " << intSqrt(num) << "\n";
    std::cout << "The square root of " << num << " is " << sqrt(num) << "\n";
    return 0;
}