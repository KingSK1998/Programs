#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

#define f(x, p, q) ((x*p) + q)
typedef unsigned long long ULONG;
int main(){
    int n, s, p, q;
    cin >> n >> s >> p >> q;

    ULONG pp = static_cast<ULONG>(pow(2,31));

    ULONG x0 = s%pp;
    ULONG vals = 1;
    // Floyd's Cycle Problem
    ULONG tortoise = f(x0, p, q) % pp;
    ULONG hare = f(x0, p , q) % pp;
    hare = f(x0, p, q) % pp;

    while(tortoise!=hare){
        if(vals >= n){
            cout << vals << endl;
            return 0;
        } else{
            vals++;
        }
        tortoise = f(tortoise, p, q) % pp;
        hare = f(hare, p, q) % pp;
        hare = f(hare, p, q) % pp;
    }    

    ULONG mu = 0;
    tortoise = x0;
    while(tortoise != hare){
        tortoise = f(tortoise, p, q) % pp;
        hare  = f(hare, p, q) % pp;
        mu++;
    }

    ULONG lam = 1;
    hare = f(tortoise, p, q) % pp;
    while(tortoise != hare){
        hare = f(hare, p, q);
        lam++;
    }

    cout << lam+mu;
    return 0;
}
