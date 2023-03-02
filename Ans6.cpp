//  You are given a ladder array of n integers. You need to sort it using a Deque. You can use builtin Deque for this problem. Expected Time Complexity is O(n).
// A ladder array is an array that is increasing at first, then decreasing after that.
// For example: [1,3,5,7,2,0] is a ladder array because 1 < 3 < 5 < 7 > 2 > 0. It is increasing till value 7, then it is decreasing after that. 				      10

// Input
// Output
// 6
// 1 3 5 7 2 0
// 0 1 2 3 5 6
// 5
// 4 6 2 1 0
// 0 1 2 4 6

// Hint: You just need to compare the values at the front and back of the Deque.

#include<bits/stdc++.h>
using namespace std;
int main()
{
    deque<int> a;
    vector<int> A;
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        int o;
        cin>>o;
        a.push_front(o);
    }

    while(!a.empty())
    {
        if(a.front()<= a.back())
        {
            A.push_back(a.front());
            a.pop_front();
        }
        else
        {
            A.push_back(a.back());
            a.pop_back();

        }
    }
    for(int i=0; i<A.size(); i++)
    {
        a.push_back(A[i]);
    }

    for (auto it = a.begin(); it != a.end(); it++)
    {
        cout << *it << " ";
    }
    return 0;
}

