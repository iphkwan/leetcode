class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (gas.size() == 0)
            return -1;
        int count = 1, ret = 0, remind_gas = gas[0], tot = 0;
        while (count <= gas.size()) {
            if (remind_gas >= cost[(ret + count - 1) % gas.size()]) {
                remind_gas += (gas[(ret + count) % gas.size()] - cost[(ret + count - 1) % gas.size()]);
                count++;
            } else {
                remind_gas = gas[(ret + count) % gas.size()];
                ret = (ret + count) % gas.size();
                count = 1;
            }
            tot++;
            if (tot > 2 * gas.size()) {
                ret = -1;
                break;
            } 
        }
        return ret;
    }
};
