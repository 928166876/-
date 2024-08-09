#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 堆排序
void heapify(vector<int>& nums, int n, int i){      //构建大顶堆的重要函数
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int max = i;
    if(l < n && nums[l] > nums[max]){
        max = l;
    }
    if(r < n && nums[r] > nums[max]){
        max = r;
    }
    if(max != i){
        swap(nums[i], nums[max]);       //交换当前节点和左右子节点中最大的节点
        heapify(nums, n, max);          //交换后要继续验证新max节点
    }
}


void heapify_build(vector<int>& nums, int n){   //构建大顶堆从倒数第二行的第一个元素开始
    int index = n / 2 - 1;              //重要公式
    for(int i = n; i >= 0; i--){
        heapify(nums, n, i);            //调用上浮交换函数
    }

    for(int i = 0; i < n; i++){         //打印输出构建好的大顶堆
        cout << nums[i] << " ";
    }
    cout << endl;
}


void func(vector<int>& nums, int n){
    heapify_build(nums, n);
    for(int i = 0; i < n; i++){
        swap(nums.front(), nums[n - i - 1]);        //弹出堆顶最大元素
        heapify(nums, n - i - 1, 0);                //交换弹出后需要进行重新构建
    }
}


int main(void){

    vector<int> nums = {9, 5, 6, 8, 2, 7, 3, 4, 1};

    func(nums, nums.size());         //调用 func 进行排序 

    for(auto a : nums){
        cout << a << " ";
    }
    cout  << endl;


    return 0;
}