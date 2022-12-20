
//Write a program to calculate factorial and to compute the factors of a given no. (i)using recursion, (ii) using iteration


#include<iostream>
using namespace std;
int i = 1;
int factorial(int n);
void factor(int n, int i);
int iter_factorial(int n);
void iter_factor(int n);

int main()
{
    int n;

    cout << "Enter a positive integer: ";
    cin >> n;

    cout << "Factorial of " << n << " using recursion = " << factorial(n);
    cout<<endl;
    cout << "Factors of " << n << " using recursion = " ;
    factor(n,i);
    cout<<endl;
    cout << "Factorial of " << n << " using iteration = " << iter_factorial(n);
    cout<<endl;
    cout << "Factors of " << n << " using iteration = " ;
    iter_factor(n);
    cout<<endl;

    return 0;
}

void factor(int n,int i)
{
    if (i<= n) {
        if (n % i == 0) {
            cout << i << " ";
        }
 
        factor(n, i + 1 );
    }
}
 

int factorial(int n)
{
    if(n > 1)
        return n * factorial(n - 1);
    else
        return 1;
}

int iter_factorial(int n){
    int fact = 1;
    for(int i=1;i<=n;i++){
        fact = fact *i;
    }
    return fact;
}

void iter_factor(int n){
    
    for(int j = 1; j <= n; j++) {
        if(n % j == 0)
            cout << j << " ";
    }
    
    

}