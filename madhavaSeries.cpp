#include <iostream>
#include <iomanip>
int main(){
    double sum = 0;
    short sign = 1; 
    long long terms = 20000000000;
    for(long long i = 1; i < terms; i += 2) {
        sum += sign / (double) i;
        sign = -sign;
    }
    std::cout << std::setprecision(20) << "Value of pi for " << terms/2 <<" terms is " << sum*4.0 << "\n";
    return 0;
}