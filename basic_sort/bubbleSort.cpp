/*****************************************
    > File Name: bubbleSort.cpp
    > Author: ZLM
    > Mail: xxxxx@live.com 
    > Created Time: 2019/01/31/ 10:09:38
 *****************************************/

#include <iostream>
#include <vector>
using namespace std;

/**
 * 2-bubble sort
 * time and space complexity: O(n2), O(1)
 */
void bubbleSort(vector<int> &num)
{
    int len = num.size();
    for (int i = len-1; i>= 1; i--) {
        for(int j = 0; j < i; j++) {
            if (num[j] > num[j+1]) {
                int tmp = num[j];
                num[j] = num[j+1];
                num[j+1] = tmp;
            }
        }
    }
}

/**
 * 2-bubble sort improve
 */
void bubbleSortImprove(vector<int> &num)
{
    int len = num.size();
    bool flag = true; 
    for (int i = len - 1; i >= 1; i--) {
        flag = false;
        for (int j = 0; j < i; j++) {
            if (num[j] > num[j+1]) {
                int tmp = num[j];
                num[j] = num[j+1];
                num[j+1] = tmp;
                flag = true;
            }
        } 
        // flag == false: no exchanges in this loop
        if (!flag) 
            break;
    }
}

// test codes
int main()
{
    vector<int> a = {20,40,30,10,60,50};

    cout << "---Test bubble sort---" << endl;
    bubbleSort(a);
    cout << "After sort:" << endl;
    for (auto v : a)
        cout << v << " ";
    cout << endl;

    return 0;
}
