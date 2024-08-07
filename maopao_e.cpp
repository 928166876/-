#include <iostream>
#include <vector>

using namespace std;

//加强版冒泡法排序
void func(vector<int>& nums){
    int len = nums.size();
    for(int i = 0; i < len - 1; i++){
        bool flag = false;  //标记以后是否还需要交换

        for(int j = 0; j < len - i - 1; j++){
            if(nums[j] > nums[j + 1]){
                swap(nums[j], nums[j + 1]);
                flag = true;
            }
        }
        if(!flag) break;    //及时退出
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