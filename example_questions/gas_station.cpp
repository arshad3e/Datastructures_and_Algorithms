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
/*Step-by-Step Execution
Station	Gas	Cost	Net Gas (gas[i] - cost[i])	Tank Balance	Start Index
0	1	3	-2	-2 (Reset)	1
1	2	4	-2	-2 (Reset)	2
2	3	5	-2	-2 (Reset)	3
3	4	1	+3	3	3
4	5	2	+3	6	3
0	1	3	-2	4	3
1	2	4	-2	2	3
2	3	5	-2	0	3
3	4	1	+3	3	3 (Complete!)
Since we successfully complete the circuit starting at index 3, we return 3.*/
