#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip> // For setting output format
#include <cmath> // For log function

using namespace std;

class Knap {
public:
    int profit;
    int value;

    Knap(int profit, int value) {
        this->profit = profit;
        this->value = value;
    }
};

bool compare(Knap a, Knap b) {
    return (double)a.profit / a.value > (double)b.profit / b.value;
}

int main() {
    vector<vector<int>> profits = {{25, 24, 15}, {30, 20, 50}, {10, 40, 30}};
    vector<vector<int>> values = {{18, 15, 10}, {10, 40, 30}, {20, 15, 25}};
    vector<int> capacities = {20, 50, 30}; // Knapsack capacities for each test case

    cout << left << setw(10) << "Test Case" << setw(15) << "Items Count" << setw(15) << "Capacity"
         << setw(15) << "Max Profit" << setw(15) << "Steps" << endl;
    cout << "---------------------------------------------------------------" << endl;

    for (int t = 0; t < profits.size(); t++) {
        vector<int> profit = profits[t];
        vector<int> value = values[t];
        int W = capacities[t];  // Knapsack capacity for current test case
        vector<double> part(profit.size(), 0);  // Fraction of each item taken

        vector<Knap> knap;
        for (int i = 0; i < profit.size(); i++) {
            knap.push_back(Knap(profit[i], value[i]));
        }

        int stepCount = 0; // Count the steps during sorting and item selection
        sort(knap.begin(), knap.end(), compare);
        stepCount += (int)(knap.size() * log(knap.size())); // Estimate steps for sorting (O(n log n))

        double maxprofit = 0;
        for (int i = 0; i < knap.size(); i++) {
            stepCount++; // Increment for each item checked
            if (knap[i].value <= W) {
                W -= knap[i].value;
                part[i] = 1;
                maxprofit += knap[i].profit;
            } else {
                double fraction = (double)W / knap[i].value;
                maxprofit += knap[i].profit * fraction;
                part[i] = fraction;
                W = 0; // No more space left in the knapsack
                break;
            }
        }

        // Printing the results in a table format
        cout << left << setw(10) << t + 1 
             << setw(15) << profit.size() 
             << setw(15) << capacities[t] 
             << setw(15) << fixed << setprecision(2) << maxprofit
             << setw(15) << stepCount << endl;
    }

    return 0;
}
