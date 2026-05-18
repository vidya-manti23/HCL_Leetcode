#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'processRequestQueueOperations' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. STRING_ARRAY operations
 *  2. INTEGER_ARRAY values
 */

vector<int> processRequestQueueOperations(vector<string> operations, vector<int> values) {
    
    stack<int> inStack;
    stack<int> outStack;
    vector<int> result;

    int n = operations.size();

    for (int i = 0; i < n; i++) {
        
        if (operations[i] == "enqueue") {
            inStack.push(values[i]);
        }

        else if (operations[i] == "dequeue") {
            if (outStack.empty()) {
                while (!inStack.empty()) {
                    outStack.push(inStack.top());
                    inStack.pop();
                }
            }
            result.push_back(outStack.top());
            outStack.pop();
        }

        else if (operations[i] == "peek") {
            if (outStack.empty()) {
                while (!inStack.empty()) {
                    outStack.push(inStack.top());
                    inStack.pop();
                }
            }
            result.push_back(outStack.top());
        }

        else if (operations[i] == "size") {
            int sz = inStack.size() + outStack.size();
            result.push_back(sz);
        }
    }

    return result;
}

int main()
{
    string operations_count_temp;
    getline(cin, operations_count_temp);

    int operations_count = stoi(ltrim(rtrim(operations_count_temp)));

    vector<string> operations(operations_count);

    for (int i = 0; i < operations_count; i++) {
        string operations_item;
        getline(cin, operations_item);

        operations[i] = operations_item;
    }

    string values_count_temp;
    getline(cin, values_count_temp);

    int values_count = stoi(ltrim(rtrim(values_count_temp)));

    vector<int> values(values_count);

    for (int i = 0; i < values_count; i++) {
        string values_item_temp;
        getline(cin, values_item_temp);

        int values_item = stoi(ltrim(rtrim(values_item_temp)));

        values[i] = values_item;
    }

    vector<int> result = processRequestQueueOperations(operations, values);

    for (size_t i = 0; i < result.size(); i++) {
        cout << result[i];

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
