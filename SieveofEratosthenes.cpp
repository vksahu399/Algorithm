//Sieve of Eratosthenes

#include <bits/stdc++.h>
using namespace std;
void SieveOfEratosthenes(int n)
{
    vector<bool> prime(n + 1, true);
    for (int p = 2; p * p <= n; p++)
        if (prime[p] == true)
            for (int i = p * 2; i <= n; i += p)
                prime[i] = false;
    for (int p = 2; p <= n; p++)
        if (prime[p])
            cout << p << " ";
}
int main()
{
    int n;
    cout << "Enter the number";
    cin >> n;
    cout << "Following are the prime numbers smaller "
         << " than or equal to " << n << endl;
    SieveOfEratosthenes(n);
    cout << "\n";
    return 0;
}