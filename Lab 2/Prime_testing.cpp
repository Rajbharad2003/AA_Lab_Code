//Lab 2 - Primality Test

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int power(int a, int b, int c)
{
    unsigned long long int result = 1;
    for(unsigned long long int i = 1 ; i <= b ; i++)
    {
        result = (result*a) % c;
    }
    return result;
}

int gcd(int a, int b)
{
    while(b > 0)
    {
        unsigned long long int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int is_prime(int n)
{
    if(n == 2 || n == 3)
        return 1;
        
    if(n%2 == 0)
        return 0;
        
    if(n <= 1 || n == 4)
        return 0;
        
    int k = 100;
    
    while(k > 0)
    {
        unsigned long long int a = 2 + rand()%(n-4);
        
        if(gcd(a,n) != 1)
            return 0;
            
        if(power(a, n-1, n) != 1)
            return 0;
        
        k--;
    }
    return 1;
}

int main() {
    // Write C++ code here
    unsigned long long int n;
    cout << "Enter any number : ";
    cin >> n;
    
    int result = is_prime(n);
    
    if(result == 1)
        cout << "Number is prime";
    else
        cout << "Number is not prime";
    return 0;
}