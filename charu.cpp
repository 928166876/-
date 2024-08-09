#include <iostream>
#include <vector>

using namespace std;

//插入排序（稳定，原地）
void func(vector<int>& nums){
    int len = nums.size();
    for(int i = 1; i < len; i++){   //从1开始
        if(nums[i] < nums[i - 1]){  //大于等于直接跳过，执行下一轮循环
            int j = i - 1;      //取序列最后下标，为后面移动做准备
            int x = nums[i];    //记录要插入的值 nums[i] 要被覆盖

            while(j >= 0 && nums[j] > x){
                nums[j + 1] = nums[j];
                j--;
            }
            nums[j + 1] = x;
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