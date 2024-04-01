#include <stdio.h>
int isPrime(int n) {
    if (n <= 1) {
        return 0;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}
void AltPrime(int N) {
    int count = 0;
    int num = 2;
    while (count < N*2) {
        if (isPrime(num)) {
            if (count % 2 == 0) {
                printf("%d ", num);
            }
            count++;
        }
        num++;
    }
}
int main() {
    int N;
    printf("Enter the value of N: ");
    scanf("%d", &N);
    printf("First %d prime numbers skipping every alternate prime number:\n", N);
    AltPrime(N);
    return 0;
}
