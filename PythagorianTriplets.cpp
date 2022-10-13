#include <iostream>
using namespace std;
bool PythagorianTriplet(int a, int b, int c)
{
    int x, y, z;
    x = max(a, max(b, c));
    if (x == a)
    {
        y = b;
        z = c;
    }
    else if (x == b)
    {
        y = a;
        z = c;
    }
    else
    {
        y = a;
        z = b;
    }
    if (x * x == y * y + z * z)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    int a, b, c;
    cout << "Enter the Numbers: \n";
    cin >> a;
    cin >> b;
    cin >> c;
    if (PythagorianTriplet(a, b, c))
    {
        cout << "It is a Pythagorian Triplet";
    }
    else
    {
        cout << "It is not a Pythagorian Triplet";
    }
}
