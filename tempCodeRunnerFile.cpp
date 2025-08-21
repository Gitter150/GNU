float sqrt(long long num, int prec = 2) {
    if(num < 0) return -1;
    if(num <= 1) return num;
    int ten_to_the_2_times_prec = 1;
    int ten_to_the_prec = 1;
    for(int i=0; i < prec; i++) {
        ten_to_the_2_times_prec *= 100;
        ten_to_the_prec *= 10;
    }
    return (float) intSqrt(num*ten_to_the_2_times_prec) / ten_to_the_prec;
}