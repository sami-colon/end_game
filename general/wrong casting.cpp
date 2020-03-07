#include <iostream>
using namespace std;
int main() {
    int si,t,p;
    float r;
    p = 5000; t = 5; r = 7.5;
    si = (p*r*t) / 100;
    // upcasting.
    printf("%f ", si);
    cout << endl;
    // downcasting.
    float f = 5000;
    printf("%d", f);
    cout << endl;
    // doesnot matter what type of casting is it. If its wrongly casted printf will print default value i.e 0.
}
