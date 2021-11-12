#include <iostream>
#include <vector>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// ** 2.1-1 Insertion Sort
void insertionSort(int *arr, int n)
{
    int key;
    int j;
    for (int i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while ((j > -1) && (arr[j] > arr[j + 1]))
            swap(&arr[j--], &arr[j + 1]);
        //swap(&arr[j+1], &arr[j--]);
    }
}

// ** Insertion Sort Nonincreaseing

void insertionSortNonincreasing(int *arr, int n)
{
    int key;
    int j;
    for (int i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while ((j > -1) && (arr[j] < arr[j + 1]))
            swap(&arr[j--], &arr[j + 1]);
    }
}

// ** 2.1-3 Linear search

int linearSearch(int *arr, int n, int x)
{
    for (int i = 0; i < n; i++)
        if (arr[i] == x)
            return i;
    return -1;
}

// ** 2.1-4 Add Binary Array

int *addBinary(int *binaryOne, int *binaryTwo, int n)
{
    int *c = new int[n + 1];
    int *res = new int[n + 1];
    c[n] = 0;
    int temp;

    for (int i = n - 1; i > -1; i--)
    {
        temp = binaryOne[i] + binaryTwo[i] + c[i];
        if (temp > 1)
        {
            c[i - 1] = 1;
            res[i + 1] = temp - 2;
        }
        else
        {
            c[i - 1] = 0;
            res[i + 1] = temp;
        }
    }
    res[0] = c[0];

    return res;
}

// ** Sentinel Linear Search

int SentinelLinearSearch(int *arr, int n, int x)
{
    int key = arr[n - 1];
    arr[n - 1] = x;

    int i = 0;
    while (arr[i] != x)
        i++;

    if (i != n - 1 || key == x)
        return i;
    return -1;
}

// ** Combination

void combination(vector<vector<int>> &result, vector<int> &subset, int *arr, int n, int pos)
{
    result.push_back(subset);
    for (int i = pos; i < n; i++)
    {
        subset.push_back(arr[i]);
        combination(result, subset, arr, n, i + 1);
        subset.pop_back();
    }
}

void subsetCombination(int *arr, int n)
{
    vector<int> subset;
    vector<vector<int>> result;
    combination(result, subset, arr, n, 0);

    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}

// ** Permutation

void pemutation(int **array, int *arr, int nArray, int n, int &index, int pos)
{
    array[index] = arr;
    index++;
    for (int i = n - 1; i > -1; i--)
    {
        swap(&arr[pos], &arr[i]);
        pemutation(array, arr, nArray, n, index, i + 1);
        swap(&arr[pos], &arr[i]);
    }
}

int giaiThua(int n)
{
    if (n == 1)
        return 1;
    return n * giaiThua(n - 1);
}

void subsetPemutation(int *arr, int n)
{
    int nArray = giaiThua(n);
    int **array = new int *[nArray];
    int i = 0;
    pemutation(array, arr, nArray, n, i, 0);
    //for (int i = 0; i < nArray; i++)
    //{
    //    for (int j = 0; j < n; j++)
    //        cout << array[i][j] << " ";
    //    cout << endl;
    //}
}

// ** 2.3-1 Merge Sort Array

void merge(int *arr, int left, int mid, int right)
{
    int *array = new int[right - left + 1];
    int i = 0;
    int key = mid;
    int n = left;
    while (left < mid && key < (right + 1))
    {
        if (arr[left] > arr[key])
            array[i++] = arr[key++];
        else
            array[i++] = arr[left++];
    }

    while (left < mid)
        array[i++] = arr[left++];
    while (key < (right + 1))
        array[i++] = arr[key++];

    while (i > 0)
    {
        i--;
        arr[i + n] = array[i];
    }
}

// ** 2.3-2 Non sentinel

void mergeNonSentinel(int *arr, int left, int mid, int right)
{
    int nArrayLeft = mid - left + 1;
    int nArrayRight = right - mid;

    int *arrayLeft = new int[nArrayLeft];
    int *arrayRight = new int[nArrayRight];

    for (int i = 0; i < nArrayLeft; i++)
        arrayLeft[i] = arr[left + i];

    for (int i = 0; i < nArrayRight; i++)
        arrayRight[i] = arr[mid + i + 1];

    int i = 0, j = 0;

    while (i < nArrayLeft && j < nArrayRight)
    {
        if (arrayLeft[i] > arrayRight[j])
            arr[left++] = arrayRight[j++];
        else
            arr[left++] = arrayLeft[i++];
    }

    while (i < nArrayLeft)
        arr[left++] = arrayLeft[i++];
    while (j < nArrayRight)
        arr[left++] = arrayRight[j++];

    delete[] arrayLeft, arrayRight;
}

void mergeSort(int *arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        mergeNonSentinel(arr, left, mid, right);
    }
}

// ** 2.3-4 Insertion Sort Recursive

void insertionSortRecursive(int *arr, int n)
{
    if (n == 0)
        return;

    insertionSortRecursive(arr, n - 1);
    int temp = arr[n];
    int i = n - 1;

    while (arr[i] > temp)
        swap(&arr[i--], &arr[i + 1]);
    arr[i + 1] = temp;
}

int main()
{
    int n = 4;
    //int *arr = new int[n]{3, 41, 52, 26, 38, 57, 9, 49};
    //cout << SentinelLinearSearch(arr, n, 3);

    //for (int i = 0; i < n; i++)
    //    cout << arr[i] << " ";
    //cout << endl;
    int *arr = new int[n]{1, 3, 4, 8};
    subsetPemutation(arr, n);
    return 0;
}
