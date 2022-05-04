#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;
int N;
vector<int> num1;
vector<int> num2;
vector<int> num3;
vector<int> num4;
vector<int> num5;
vector<vector<int>> a {num1,num2,num3,num4,num5};

void fill(){
    for(int i = 0; i < N; i++)
        num1.push_back(rand() % 9);

    for(int i = 0; i < N; i++)
        num2.push_back(rand() % 9);

    for(int i = 0; i < N; i++)
        num3.push_back(rand() % 9);

    for(int i = 0; i < N; i++)
        num4.push_back(rand() % 9);

    for(int i = 0; i < N; i++)
        num5.push_back(rand() % 9);
}

int summ(vector <int> num){
    vector<int>::iterator it;
    int sum = 0;
    for(it = num.begin(); it != num.end(); ++it)
        sum += pow(*it,2);
    return sum;
}

void print(std::vector<vector<int>> a)
{
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a[i].size(); j++)
            cout << a[i][j];
        cout << " ";
    }
}

int main() {
    cout << "Type the N number" << endl;
    cin >> N;

    fill();

    sort(a.begin(), a.end(), [](const vector<int>& a, const vector<int>& b)
    {
        return summ(a) < summ(b);
    });

    print(a);
}