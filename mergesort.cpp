#include <iostream>
#include <vector>

using namespace std;

//归并排序递归向量版（稳定，非原地）
void func(vector<int>& nums, vector<int>& tmp, int start, int end){
    if(start >= end) return;
    int len = end - start;
    int start1 = start; int mid = start + len / 2;
    int end1 = mid;
    int start2 = mid + 1; int end2 = end;
    func(nums, tmp, start1, end1);
    func(nums, tmp, start2, end2);

    int index = start;
    while(start1 <= end1 && start2 <= end2){
        tmp[index++] = nums[start1] < nums[start2] ? nums[start1++] : nums[start2++];
    }

    while(start1 <= end1){
        tmp[index++] = nums[start1++];
    }

    while(start2 <= end2){
        tmp[index++] = nums[start2++];
    }

    for(int i = start; i <= end; i++){
        nums[i] = tmp[i];
    }

}


int main(void){

    vector<int> nums = {9, 5, 6, 8, 2, 7, 3, 4, 1};

    vector<int> tmp(nums.size(), 0);
    func(nums, tmp, 0, nums.size() - 1);         //调用 func 进行排序 

    for(auto a : nums){
        cout << a << " ";
    }
    cout  << endl;


    return 0;
}