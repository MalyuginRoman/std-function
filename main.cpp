#include <iostream>
#include <functional>
using namespace std;

int f(int a, int b) {
    return a + b;
}

// Functions for simple math operations
int add(int a, int b) {
    return a + b;
}
int sub(int a, int b) {
    return a - b;
}
int mul(int a, int b) {
    return a * b;
}
int divs(int a, int b) {
    return a / b;
}

// Using std::function as parameter
void func(int a, int b,
         function<int(int, int)> calc) {

    int res = calc(a, b);
    cout << "Result: " << res << endl;
}

class C {
public:
    int f(int a, int b) {
        return a * b;
    }
};

// Composed function
function<int(int)> cf(function<int(int)> f1,
                        function<int(int)> f2) {

    // Returning a lambda expression that
    // in turn returns a function
    return [f1, f2](int x) {

        // Apply f1 first, then f2
        return f2(f1(x));
    };
}

int main(int ac, char **av)
{
    // C++ Program to illustrate the working std::function
    // std::function wrapping traditional function
    function<int(int,int)> calc = f;
    cout << "Sum:" << calc(8, 2) << endl;

    // std::function wrapping a lambda expression
    calc = [](int a, int b) { return a * b; };
    cout << "Product:" << calc(8, 2) << endl;

    // C++ program to pass the std::function as arguments
    // Calling all the arithmetic functions
    func(8, 2, add);
    func(8, 2, sub);
    func(8, 2, mul);
    func(8, 2, divs);

    // C++ program to demonstrate usage of
    // unction with member functions
    C c;

    // Wrapping member function of C
    function<int(C&, int, int)> calcf = &C::f;

    // Call the member function using function
    if (calcf)
        cout << "Product: " << calcf(c, 4, 5) << endl;
    else
        cout << "No Callable Assigned" << endl;

    // C++ program to demonstrate usage of
    // std::function for function composition
    auto add = [](int x) { return x + 2; };
    auto mul = [](int x) { return x * 3; };

    function<int(int)> calct = cf(add, mul);
    cout << calct(4);
}
