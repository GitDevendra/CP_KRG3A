
#include <iostream>
#include <vector>
using namespace std;

int singleNumber(vector<int>& nums) {
    int ans = 0;
    for(int i = 0; i < 32; i++) {
        int sum = 0;
        for(int num : nums) {
            if(num & (1 << i)) {
                sum++;
            }
        }
        if(sum % 3 != 0) {
            ans |= (1 << i);
        }
    }
    return ans;
}
int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements: ";
    
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int result = singleNumber(nums);
    cout << "Element appearing once: " << result << endl;

    return 0;
}