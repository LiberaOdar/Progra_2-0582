#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool compara(const int &a, const int &b) {
    return a > b;
}

int main() {
    vector<int>mivector;
    cout << mivector.size() << endl;
    mivector.push_back(10);
    mivector.push_back(15);
    mivector.push_back(14);
    mivector.push_back(2);
    mivector.push_back(8);
    mivector.push_back(16);
    mivector.push_back(20);
    for (int i = 0; i < mivector.size(); i++)
        cout << mivector[i] << " ";
    cout << endl;
    for (int i = 0; i < mivector.size(); i++)
        cout << mivector[i] << " ";
    cout << endl;
    mivector.erase(mivector.begin());
    for (int i = 0; i < mivector.size(); i++)
        cout << mivector[i] << " ";
    cout << endl;
    int i=0;
    while (i<mivector.size()) {
        if (mivector[i]<=10) {
            mivector.erase(mivector.begin() + i);
        }
        else
            i++;
    }
    sort(mivector.begin(), mivector.end(),compara);
    for (int i = 0; i < mivector.size(); i++)
        cout << mivector[i] << " ";
    cout << endl;
    return 0;
}
