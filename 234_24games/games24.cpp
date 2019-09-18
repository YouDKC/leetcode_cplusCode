//
// Created by youkechaung on 2019/9/18.
//

#include "games24.h"
//
// Created by 尤科闯 on 2019/8/13.
//
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;
//https://blog.csdn.net/quyafeng2011/article/details/68921750
class Solution {
public:
    bool judgePoint24(vector<int> nums){
        for(int i=0 ;i<nums.size();i++){
            nums[i] = 9;
            cout<< nums[i] <<" ";}
        return judge24({nums.begin(), nums.end()}); }

    static bool judge24(vector<double> nums) {
//加了static后表示该函数失去了全局可见性，只在该函数所在的文件作用域内可见
//当函数声明为static以后,编译器在该目标编译单元内只含有该函数的入口地址,没有函数名,其它编译单元便不能通过该函数名来调用该函数
        auto n = nums.size();
        if(n == 1) return abs(nums[0] - 24) < 1e-10;

        sort(nums.begin(), nums.end());
        // For each permutation,
        do {
            // merge the last two numbers.
            vector<double> temp(nums.begin(), nums.end()-1);
            auto a = nums[n-1], b = nums[n-2];
            for(auto num: {a+b, a-b, a*b, a?b/a:0}){
                // For each merged number, combine with the rest and test it
                temp.back() = num;
                if(judge24(temp)) return true;
            }
        } while(next_permutation(nums.begin(), nums.end()));

        return false;
    }
};

int main(){
    bool a;
    vector<int> nums = {7, 1, 5, 3, 6, 4};

    for(int i=0 ;i<nums.size();i++)
        cout<<nums[i]<<" ";
    cout<<endl;
    Solution s;
    a = s.judgePoint24(nums);
    cout << "Box2 的体积：" << a <<endl;
    for(int j=0 ;j<nums.size();j++){
        cout << "修改后：" << nums[j] <<" ";}
    cout<<endl;

    return 0;
}

