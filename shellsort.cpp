#include <iostream>
#include <vector>

using namespace std;

//希尔排序

void shell(vector<int>& nums, int gap, int i){
    int tmp = nums[i];
    int j;
    for(j = i - gap; j >= 0 && nums[j] > tmp; j -= gap){    //排序for循环
        nums[j + gap] = nums[j];    
    }
    nums[j + gap] = tmp;
}


void func(vector<int>& nums){
    int len = nums.size();
    for(int gap = len / 2; gap > 0; gap /= 2){      //初始gap为长度一半，以gap进行分组排序，最后gap为1.
        for(int i = gap; i < len; i++){
            shell(nums, gap, i);                //进行组内排序
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