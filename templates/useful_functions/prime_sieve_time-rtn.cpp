// C++ program to print all prime factors  
#include <bits/stdc++.h>
#include <unordered_map> 
using namespace std; 
  
// A function to print all prime  
// factors of a given number n
map<ll, ll> primeFactors(ll n)
{
    map<ll, ll> fac;
    for (ll i = 2; i <= sqrt(n); i++)
    {
        while (n % i == 0)
        {
            n /= i;
            fac[i]++;
        }
    }
    if (n > 1)
    {
        fac[n]++;
    }
    return fac;
} 
  