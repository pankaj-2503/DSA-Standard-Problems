class Solution {
public:
// TC: O(n), SC: O(1)
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total_gas = 0, total_cost = 0, start = 0, current_gas = 0;
        for (int i = 0; i < gas.size(); ++i) {
            total_gas += gas[i];
            total_cost += cost[i];
            current_gas += gas[i] - cost[i];
            if (current_gas < 0) {
                start = i + 1;
                current_gas = 0;
            }
        }
        return total_gas < total_cost ? -1 : start;
    }
};