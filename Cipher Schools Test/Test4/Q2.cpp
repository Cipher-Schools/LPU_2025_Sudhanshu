/*
A string is good if there are no repeated characters.

Given a string s​​​​​, return the number of good substrings of length three in s​​​​​​.

Note that if there are multiple occurrences of the same substring, every occurrence should be counted.

A substring is a contiguous sequence of characters in a string.
*/

#include <iostream>
using namespace std;

int countGoodSubstrings(string s)
{
    if (s.size() < 3)
        return 0;
    int res = 0;

    for (int i = 0; i <= s.size() - 3; i++)
    {
        string sub = s.substr(i, 3);
        if (sub[0] != sub[1] && sub[1] != sub[2] && sub[0] != sub[2])
        {
            res++;
        }
    }
    return res;
}

int main()
{
    string s;
    cout << "Enter the string: ";
    cin >> s;

    int result = countGoodSubstrings(s);
    cout << "Number of good substrings of length three: " << result << endl;

    return 0;
}