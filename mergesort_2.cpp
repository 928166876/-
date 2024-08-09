#include <iostream>
#include <vector>

using namespace std;

//归并排序迭代实现
void func(vector<int>& nums){
    int len = nums.size();
    vector<int> tmp(len, 0);
    for(int i = 1; i < len; i += i){    //模仿递归层数
        for(int start = 0; start < len; start += i + i){
            int s1 = start;
            int mid = min(start + i, len);
            int end = min(start + i + i, len);
            int e1 = mid, s2 = mid, e2 = end;
            int index = start;
            while(s1 < e1 && s2 < e2){
                tmp[index++] = nums[s1] < nums[s2] ? nums[s1++] : nums[s2++];
            }

            while(s1 < e1){
                tmp[index++] = nums[s1++];
            }

            while(s2 < e2){
                tmp[index++] = nums[s2++];
            } 
        }
        swap(nums, tmp);
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