<<<<<<< HEAD
#include <iostream>
#include <format>
using namespace std;

void test(int i);

int main() {
    int t;
    cin>>t;

    for (int i = 0; i<t;i++) {
        int n;
        cin>>n;
        test(n);
    }


    return 0;

}

void test(int i) {
    if (i>=1&& i<=20) {
        for (int j = 1; j<=i;j++) {
            cout<<j<<" ";


        }
        cout<<endl;

    }
=======
#include <iostream>
#include <format>
using namespace std;

void test(int i);

int main() {
    int t;
    cin>>t;

    for (int i = 0; i<t;i++) {
        int n;
        cin>>n;
        test(n);
    }


    return 0;

}

void test(int i) {
    if (i>=1&& i<=20) {
        for (int j = 1; j<=i;j++) {
            cout<<j<<" ";


        }
        cout<<endl;

    }
>>>>>>> dcbfba99abc125426315d3c34dc631f876e36730
}