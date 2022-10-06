import math
class Solution:
    def countPrimes(self, n: int) -> int:
        isPrime = [1]*n
        primes = 0
        for i in range(2,n):
            if isPrime[i] == 1:
                primes += 1
                for j in range(i*i,n,i):
                    isPrime[j] = 0
        return primes
