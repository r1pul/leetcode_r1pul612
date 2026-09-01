bool checkDivisibility(int n) {
    int temp = n;

    int sum = 0 , product = 1;

    while(temp > 0){
        sum += temp % 10;
        product *= temp % 10;

        temp = temp / 10;
    }
    if( n % (sum + product) == 0)
        return true;

    return false;

}