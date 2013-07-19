class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        map<int, int> mp;
        map<int, int>::iterator pt;
        vector<int> ans;
        for (int i = 0; i < numbers.size(); i++) {
            pt = mp.find(target - numbers[i]);
            if (pt != mp.end()) {
                ans.push_back(pt->second);
                ans.push_back(i + 1);
                return ans;
            }
            pt = mp.find(numbers[i]);
            if (pt == mp.end()) {
                mp[ numbers[i] ] = i + 1;
            }
        }
    }
};