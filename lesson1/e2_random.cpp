#include <iostream>
#include <random>
using namespace std;

void unseeded_rng()
{
    mt19937 rng(random_device{}());
    cout << "unseeded " << rng() % 10 << "\n";
}

void seeded_rng()
{
    mt19937 rng(42);
    cout << "seeded " << rng() % 10 << "\n";
}

int main()
{
    unseeded_rng();
    unseeded_rng();
    unseeded_rng();
    seeded_rng();
    seeded_rng();
    seeded_rng();

    return 0;
}


