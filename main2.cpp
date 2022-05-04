#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> num1{1,5,2};
vector<int> num2{2,0,8};
vector<int> num3{5};
vector<int> num4{1,0};
vector<int> num5{1,2};
vector<int> a[5] {num1,num2,num3,num4,num5};

int summ(vector <int> num){
    vector<int>::iterator it;
    int sum = 0;
    for(it = num.begin(); it != num.end(); ++it)
        sum += pow(*it,2);
    return sum;
}

void SelectionSort()
{
    vector <int> count;
    int key;
    for (int i = 0; i < 4; i++)
    {
        count = a[i]; key=i;
        for (int j = i+1; j < 5; j++)
            if (summ(a[j]) < summ(a[key])) key=j;
        if (key!=i)
        {
            a[i] = a[key];
            a[key] = count;
        }
    }
}

void print()
{

    for (int i = 0; i < 5; i++) {
        for (auto it = a[i].begin();
             it != a[i].end(); it++) {
            cout << *it;
        }
        cout << " ";
    }
}

int main() {
    SelectionSort();
    print();
}
