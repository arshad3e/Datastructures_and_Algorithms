#include <vector>
using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int total_gas = 0, total_cost = 0;
    int tank = 0, start_index = 0;

    for (int i = 0; i < gas.size(); i++) {
        total_gas += gas[i];
        total_cost += cost[i];
        tank += gas[i] - cost[i];

        // If tank becomes negative, reset start_index to next station
        if (tank < 0) {
            start_index = i + 1;
            tank = 0;  // Reset tank as we are starting fresh
        }
    }

    return (total_gas >= total_cost) ? start_index : -1;
}
