#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'findMinimumPlansForBandwidth' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY planSizes
 *  2. INTEGER targetBandwidth
 */

int findMinimumPlansForBandwidth(vector<int> planSizes, int targetBandwidth) {
    vector<int> dp(targetBandwidth + 1, INT_MAX);

    dp[0] = 0;

    for (int i = 1; i <= targetBandwidth; i++) {
        for (int plan : planSizes) {
            if (i - plan >= 0 && dp[i - plan] != INT_MAX) {
                dp[i] = min(dp[i], dp[i - plan] + 1);
            }
        }
    }

    return (dp[targetBandwidth] == INT_MAX) ? -1 : dp[targetBandwidth];
}
int main()
{
    string planSizes_count_temp;
    getline(cin, planSizes_count_temp);

    int planSizes_count = stoi(ltrim(rtrim(planSizes_count_temp)));

    vector<int> planSizes(planSizes_count);

    for (int i = 0; i < planSizes_count; i++) {
        string planSizes_item_temp;
        getline(cin, planSizes_item_temp);

        int planSizes_item = stoi(ltrim(rtrim(planSizes_item_temp)));

        planSizes[i] = planSizes_item;
    }

    string targetBandwidth_temp;
    getline(cin, targetBandwidth_temp);

    int targetBandwidth = stoi(ltrim(rtrim(targetBandwidth_temp)));

    int result = findMinimumPlansForBandwidth(planSizes, targetBandwidth);

    cout << result << "\n";

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
