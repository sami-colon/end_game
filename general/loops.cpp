#include <iostream>
using namespace std;
int main() {
    char i=0;
    for(i<=5 && i>=-1;++i;i>0);
	printf("%d ",i);
    cout << endl;
	for(;++i;i>5);
	printf("%d ",i);
	cout << endl;
    int j=0;
    // cout << (++j) << endl;
    for(; j++; j<=5){
        cout << j << endl;
    }
    return 0;
}
