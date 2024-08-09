#include <iostream>
#include <vector>

using namespace std;

//基本版冒泡法排序（不稳定，原地）重要！！！
void func(vector<int>& nums, int start, int end){
    if(start >= end) return ;
    int left = start;
    int right = end;
    int key = nums[start];
    while(left < right){
        while(left < right && nums[right] >= key) right--;
        if(left < right) nums[left++] = nums[right];

        while(left < right && nums[left] <= key) left++;
        if(left < right) nums[right--] = nums[left];

        nums[left] = key;

        func(nums, 0, left - 1);
        func(nums, left + 1, end);
    }

}


int main(void){

    vector<int> nums = {9, 5, 6, 8, 2, 7, 3, 4, 1};

    func(nums, 0, nums.size() - 1);         //调用 func 进行排序 左闭右闭区间

    for(auto a : nums){
        cout << a << " ";
    }
    cout  << endl;


    return 0;
}