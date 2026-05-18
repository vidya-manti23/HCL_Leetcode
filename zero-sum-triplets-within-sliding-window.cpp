#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'findZeroSumTripletsInWindow' function below.
 *
 * The function is expected to return a 2D_INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY readings
 *  2. INTEGER windowSize
 */

vector<vector<int>> findZeroSumTripletsInWindow(vector<int> readings, int windowSize) {
    int n = readings.size();
    if (n < 3 || windowSize < 3) return {};

    set<vector<int>> uniqueTriplets;

    for (int i = 0; i < n; i++) {

        int windowEnd = min(i + windowSize, n);

        unordered_set<int> seen;

        for (int j = i + 1; j < windowEnd; j++) {

            int needed = -(readings[i] + readings[j]);

            if (seen.count(needed)) {
                vector<int> triplet;
                triplet.push_back(readings[i]);
                triplet.push_back(readings[j]);
                triplet.push_back(needed);

                sort(triplet.begin(), triplet.end());
                uniqueTriplets.insert(triplet);
            }

            seen.insert(readings[j]);
        }
    }

    return vector<vector<int>>(uniqueTriplets.begin(), uniqueTriplets.end());
}

int main()
{
    string readings_count_temp;
    getline(cin, readings_count_temp);

    int readings_count = stoi(ltrim(rtrim(readings_count_temp)));

    vector<int> readings(readings_count);

    for (int i = 0; i < readings_count; i++) {
        string readings_item_temp;
        getline(cin, readings_item_temp);

        int readings_item = stoi(ltrim(rtrim(readings_item_temp)));

        readings[i] = readings_item;
    }

    string windowSize_temp;
    getline(cin, windowSize_temp);

    int windowSize = stoi(ltrim(rtrim(windowSize_temp)));

    vector<vector<int>> result = findZeroSumTripletsInWindow(readings, windowSize);

    for (size_t i = 0; i < result.size(); i++) {
        for (size_t j = 0; j < result[i].size(); j++) {
            cout << result[i][j];

            if (j != result[i].size() - 1) {
                cout << " ";
            }
        }

        if (i != result.size() - 1) {
            cout << "\n";
        }
    }

    cout << "\n";

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
