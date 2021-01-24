//Adapted from https://www.geeksforgeeks.org/print-all-prime-factors-of-a-given-number/
// C++ program to print all prime factors  
#include <bits/stdc++.h>
#include <unordered_map> 
using namespace std; 
  
// A function to print all prime  
// factors of a given number n
unordered_map<int,int> primeFactors(int n)  
{
    unordered_map<int,int> factors;
    // Print the number of 2s that divide n  
    while (n % 2 == 0)  
    {
        factors[2]++;
        n /= 2;
    }  
  
    // n must be odd at this point. So we can skip  
    // one element (Note i = i +2)  
    for (int i = 3; i <= sqrt(n); i = i + 2)  
    {  
        // While i divides n, print i and divide n  
        while (n % i == 0)  
        {  
            factors[i]++;
            n /=i;  
        }  
    }
    if(factors.find(n) == factors.end() && n > 2){
        factors[n]++;
    }
    return factors;
}  
  
// This is code is contributed by rathbhupendra + modified by me.