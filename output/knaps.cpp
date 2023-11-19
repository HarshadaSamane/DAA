#include <iostream>
#include <algorithm>

using namespace std;

struct Item {
    int weight;
    int value;
};

// Function to solve Fractional Knapsack problem using Greedy algorithm
double fractionalKnapsack(Item items[], int n, int capacity) {
    sort(items, items + n, [](Item a, Item b) {
        return (double)a.value / a.weight > (double)b.value / b.weight;
    });

    double totalValue = 0.0;
    for (int i = 0; i < n; ++i) {
        if (capacity >= items[i].weight) {
            totalValue += items[i].value;
            capacity -= items[i].weight;
        } else {
            totalValue += ((double)capacity / items[i].weight) * items[i].value;
            break;
        }
    }

    return totalValue;
}

// Function to solve 0/1 Knapsack problem using dynamic programming
int knapSack(Item items[], int n, int capacity) {
    int dp[n + 1][capacity + 1];

    for (int i = 0; i <= n; ++i) {
        for (int w = 0; w <= capacity; ++w) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            } else if (items[i - 1].weight <= w) {
                dp[i][w] = max(items[i - 1].value + dp[i - 1][w - items[i - 1].weight], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][capacity];
}

int main() {
    int n;
    cout << "Enter the number of items: ";
    cin >> n;

    Item items[n];

    cout << "Enter weight and value for each item:\n";
    for (int i = 0; i < n; ++i) {
        cin >> items[i].weight >> items[i].value;
    }

    int capacity;
    cout << "Enter the capacity of knapsack: ";
    cin >> capacity;

    // Solve Fractional Knapsack problem
    double greedyResult = fractionalKnapsack(items, n, capacity);
    cout << "The maximum value using Greedy approach (Fractional Knapsack) is: " << greedyResult << endl;

    // Solve 0/1 Knapsack problem
    int dpResult = knapSack(items, n, capacity);
    cout << "The maximum value using Dynamic Programming approach (0/1 Knapsack) is: " << dpResult << endl;

    return 0;
}
