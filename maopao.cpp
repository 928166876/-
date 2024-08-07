#include <iostream>
#include <vector>

using namespace std;

//基本版冒泡法排序
void func(vector<int>& nums){
    int len = nums.size();
    for(int i = 0; i < len - 1; i++){
        for(int j = 0; j < len - i - 1; j++){
            if(nums[j] > nums[j + 1]){
                swap(nums[j], nums[j + 1]);
            }
        }
    }

}


int main(void){

    vector<int> nums = {9, 5, 6, 8, 2, 7, 3, 4, 1};

    func(nums);         //调用 func 进行排序 

    for(auto a : nums){
        cout << a << " ";
    }
    cout  << endl;


    return 0;
}