#include<iostream>

using namespace std;


int factorial(int num)
{
    if(num == 0)
        return 1;
    int result = num*factorial(num-1);
    return result;
}

int fibonacci(int n)
{
    if(n <= 1)
        return 1;
    int result = fibonacci(n-1) + fibonacci(n-2);
    return result;
}
int main()
{
    cout<<"factorial: "<<factorial(5)<<endl;
    cout<<"fibonacci: "<<fibonacci(5)<<endl;

}