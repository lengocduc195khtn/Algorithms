#include <iostream>
#include <vector>
using namespace std;

void searchSpecial(vector<vector<int>> &res, vector<int> &subset, vector<int> arr, int pos)
{
    res.push_back(subset);
    for (int i = pos + 2; i < arr.size() - 1; i++)
    {
        subset.push_back(arr[i]);
        cout << "subset " << i << " ";
        for (int j = 0; j < subset.size(); j++)
            cout << subset[j] << " ";
        searchSpecial(res, subset, arr, i);

        cout << endl;

        subset.pop_back();
    }
}

void search(vector<vector<int>> &res, vector<int> &subset, vector<int> arr, int pos)
{
    res.push_back(subset);
    for (int i = pos + 2; i < arr.size(); i++)
    {
        subset.push_back(arr[i]);
        cout << "subset " << i << " ";
        for (int j = 0; j < subset.size(); j++)
            cout << subset[i] << " ";
        search(res, subset, arr, i);

        cout << endl;

        subset.pop_back();
    }
}

vector<vector<int>> subset(vector<int> arr)
{
    vector<int> subset;
    vector<vector<int>> res;

    subset.push_back(arr[0]);
    searchSpecial(res, subset, arr, 0);
    subset.pop_back();

    for (int i = 1; i < arr.size(); i++)
    {
        subset.push_back(arr[i]);
        search(res, subset, arr, i);
        subset.pop_back();
    }

    int max = 0;

    int *result = new int[res.size()];

    for (int i = 0; i < res.size(); i++)
    {
        result[i] = 0;
        for (int j = 0; j < res[i].size(); j++)
            result[i] = result[i] + res[i][j];
        if (max < result[i])
            max = result[i];
    }

    cout << max;

    return res;
}

int sum(vector<int> array)
{
    int temp = 0;
    for (int i = 0; i < array.size(); i++)
        temp = temp + array[i];
    return temp;
}

void searchSpecial_1(vector<vector<int>> &res, vector<int> &subset, vector<int> arr, int pos, int &max)
{
    int temp = arr.size();
    if (pos >= temp - 3)
    {
        int temp1 = sum(subset);
        if (max < temp1)
            max = temp1;
    }
    for (int i = pos + 2; i < arr.size() - 1; i++)
    {
        subset.push_back(arr[i]);
        searchSpecial_1(res, subset, arr, i, max);
        subset.pop_back();
    }
}

void search_1(vector<vector<int>> &res, vector<int> &subset, vector<int> arr, int pos, int &max)
{
    if (pos >= arr.size() - 2)
    {
        int temp = sum(subset);
        if (max < temp)
            max = temp;
    }
    for (int i = pos + 2; i < arr.size(); i++)
    {
        subset.push_back(arr[i]);
        search_1(res, subset, arr, i, max);
        subset.pop_back();
    }
}
vector<vector<int>> subset_1(vector<int> arr)
{
    vector<int> subset;
    vector<vector<int>> res;

    int max = 0;
    int temp;

    subset.push_back(arr[0]);
    searchSpecial_1(res, subset, arr, 0, max);
    subset.pop_back();

    for (int i = 1; i < 2; i++)
    {

        subset.push_back(arr[i]);
        search_1(res, subset, arr, i, max);
        subset.pop_back();
    }

    cout << res.size() << endl;
    for (int i = 0; i < res.size(); i++)
    {
        temp = 0;
        for (int j = 0; j < res[i].size(); j++)
            temp = temp + res[i][j];
        if (max < temp)
            max = temp;
    }

    cout << "max : " << max << endl;

    return res;
}

int robRec(vector<int> nums)
{
    int size = (int)nums.size();
    if (size == 0)
        return 0;
    else if (size == 1)
        return nums[0];
    else if (size == 2)
        return max(nums[0], nums[1]);
    vector<int> ret(size, 0);
    ret[0] = nums[0];
    ret[1] = nums[1];
    ret[2] = nums[0] + nums[2];
    if (size == 3)
        return max(ret[1], ret[2]);
    for (int i = 3; i < size; i++)
    {
        ret[i] = max(ret[i - 2] + nums[i], ret[i - 3] + nums[i]);
    }
    return max(ret[size - 1], ret[size - 2]);
}

int rob(vector<int> &nums)
{
    int size = (int)nums.size();
    if (size == 0)
        return 0;
    else if (size == 1)
        return nums[0];
    vector<int> ret1 = nums;
    ret1.pop_back();
    vector<int> ret2(size - 1);
    for (int i = 0; i < size - 1; i++)
    {
        ret2[i] = nums[i + 1];
    }
    int req1 = robRec(ret1);
    int req2 = robRec(ret2);
    return max(req1, req2);
}

int main()
{
    vector<int> array = {2, 3, 2};
    int n = array.size();
    int *value = new int[n];
    for (int i = 0; i < n; i++)
        value[i] = -1;
    cout << searching(array, 0, value, n);

    return 0;
}