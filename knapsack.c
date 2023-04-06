#include <stdio.h>

// Function to solve the fractional knapsack problem
void fractional_knapsack(int n, float value[], float weight[], float capacity) {
    // Calculate value-to-weight ratio for each item.
    float ratio[n];
    for (int i = 0; i < n; i++) {
        ratio[i] = value[i] / weight[i];
    }

    // Sort items by value-to-weight ratio in decreasing order using insertion sort.
    for (int i = 1; i < n; i++) {
        float key_ratio = ratio[i];
        float key_value = value[i];
        float key_weight = weight[i];
        int j = i - 1;
        while (j >= 0 && ratio[j] < key_ratio) {
            ratio[j + 1] = ratio[j];
            value[j + 1] = value[j];
            weight[j + 1] = weight[j];
            j--;
        }
        ratio[j + 1] = key_ratio;
        value[j + 1] = key_value;
        weight[j + 1] = key_weight;
    }

    float max_value = 0.0;
    float fractions[n];
    for (int i = 0; i < n; i++) {
        if (weight[i] <= capacity) {
            fractions[i] = 1.0;
            max_value += value[i];
            capacity -= weight[i];
        } else {
            fractions[i] = capacity / weight[i];
            max_value += value[i] * capacity / weight[i];
            break;
        }
    }

    // Print the maximum value and the fraction of each item that was included in the knapsack
    printf("Maximum value: %.2f\n", max_value);
    printf("Fractions: ");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", fractions[i]);
    }
}

// Driver program to test the above function
int main() {
    int n;
    float value[100], weight[100], capacity;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the values and weights of the items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%f %f", &value[i], &weight[i]);
    }

    printf("Enter the capacity of the knapsack: ");
    scanf("%f", &capacity);

    fractional_knapsack(n, value, weight, capacity);

    return 0;
}