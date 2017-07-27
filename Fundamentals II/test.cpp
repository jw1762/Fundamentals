#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
     int foo = 9;
   // int *ptr = &foo;
    float foo2 = 5.7;

//    *ptr = 2;
    foo2 = foo - foo2;

    if (foo > foo2)
       cout << "Hello!";
    else if (foo < foo2)
       cout << foo2;
    else
       cout << foo;

    cout << endl;

    cout << "foo2 is: " << fixed
         << setprecision(1) << foo2 << endl;

}
