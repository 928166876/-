#include <iostream>
#include <vector>

using namespace std;

//选择排序
void func(vector<int>& nums){
    int len = nums.size();
    for(int i = 0; i < len - 1; i++){
        int minindex = i;
        for(int j = i + 1; j < len; j++){
            if(nums[j] < nums[minindex]){
                minindex = j;
            }
        }
        swap(nums[i], nums[minindex]);
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