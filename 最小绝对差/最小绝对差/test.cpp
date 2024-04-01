#include<iostream>
#include<vector>
#include<Algorithm>
using namespace std;

vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
    vector<vector<int>>ans;
    int min = INT_MAX;
    int n = arr.size();
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n - 1; i++)
    {
        int num = arr[i + 1] - arr[i];
        if (num < min)
        {
            min = num;
            ans.clear();
            ans.push_back({ arr[i],arr[i + 1] });
        }
        else if (min == num)
        {
            ans.push_back({ arr[i],arr[i + 1] });
        }
    }


    return ans;

}