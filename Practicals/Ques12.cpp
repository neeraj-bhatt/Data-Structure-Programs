//WAP to display fibonacci series (i) using recursion, (ii) using iteration

#include <iostream>
using namespace std;

int fibonacciRecursion(int x) {
    if((x==1)||(x==0)) {
        return(x);
    }else {
        return(fibonacciRecursion(x-1)+fibonacciRecursion(x-2));
    }
}

void fibonacciIteration(int num) {
    int x = 0, y = 1, z = 0;
    for (int i = 0; i < num; i++) {
        cout << x << " ";
        z = x + y;
        x = y;
        y = z;
    }
}
int main() {
    int choice;
    int x , i=0;
    cout << "Enter the number of terms of series : ";
    cin >> x;
    cout << "1.Recursion\n2.Iteration\n3.Exit\n";
    cout << "Choice : ";
    cin >> choice;
    cout << "Fibonnaci Series : ";
    switch (choice)
    {
    case 1:
        while(i < x) {
        cout << fibonacciRecursion(i) << " ";
        i++;
        }
        break;
    case 2:
        fibonacciIteration(x);
    case 3:
        exit(0);
    default:
        cout << "Wrong Choice" << endl;
        break;
    }
    return 0;
}