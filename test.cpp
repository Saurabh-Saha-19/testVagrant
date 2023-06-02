#include <bits/stdc++.h>
#include <string>
#include <vector>
using namespace std;

class MySub {
private:
    string name[5] = {"TOI", "Hindu", "ET", "BM", "HT"};
    float newspapers[5][7] = {
        {3, 3, 3, 3, 3, 5, 6},
        {2.5, 2.5, 2.5, 2.5, 2.5, 4, 4},
        {4, 4, 4, 4, 4, 4, 10},
        {1.5, 1.5, 1.5, 1.5, 1.5, 1.5, 1.5},
        {2, 2, 2, 2, 2, 4, 4}
    };

public:
    float weeklyCost[5];

    void calculateTotalCost() {
        for (int i = 0; i < 5; i++) {
            float sum = 0;
            for (int j = 0; j < 7; j++) {
                sum += newspapers[i][j];

            }
            weeklyCost[i] = sum;
        }


    }


    void calculateWeekCost(float amount) {
        float tempAmount = amount;
        calculateTotalCost();

        for (int i = 0; i < 5; i++) {
            for (int j = i + 1; j < 5; j++) {
                if (weeklyCost[i] + weeklyCost[j] <= tempAmount) {
                    cout << "{" + name[i] + " " + name[j] + "}" << endl;
                }
            }
        }

    }
};




int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif


    int weeklyBudget;

    cin >> weeklyBudget;

    MySub obj1;
    obj1.calculateWeekCost(weeklyBudget);


}
