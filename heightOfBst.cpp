#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'getBinarySearchTreeHeight' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY values
 *  2. INTEGER_ARRAY leftChild
 *  3. INTEGER_ARRAY rightChild
 */
int findHeight(int node, vector<int>& leftChild, vector<int>& rightChild){
    if(node == -1) return 0;
    int leftH = findHeight(leftChild[node], leftChild, rightChild);
    int rightH = findHeight(rightChild[node], leftChild,rightChild);
    
    return 1 + max(leftH, rightH); 
}

int getBinarySearchTreeHeight(vector<int> values, vector<int> leftChild, vector<int> rightChild) {
    int n = values.size();
    if(n == 0) return 0;
    return findHeight(0,leftChild, rightChild);
}

int main()
{
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

    string leftChild_count_temp;
    getline(cin, leftChild_count_temp);

    int leftChild_count = stoi(ltrim(rtrim(leftChild_count_temp)));

    vector<int> leftChild(leftChild_count);

    for (int i = 0; i < leftChild_count; i++) {
        string leftChild_item_temp;
        getline(cin, leftChild_item_temp);

        int leftChild_item = stoi(ltrim(rtrim(leftChild_item_temp)));

        leftChild[i] = leftChild_item;
    }

    string rightChild_count_temp;
    getline(cin, rightChild_count_temp);

    int rightChild_count = stoi(ltrim(rtrim(rightChild_count_temp)));

    vector<int> rightChild(rightChild_count);

    for (int i = 0; i < rightChild_count; i++) {
        string rightChild_item_temp;
        getline(cin, rightChild_item_temp);

        int rightChild_item = stoi(ltrim(rtrim(rightChild_item_temp)));

        rightChild[i] = rightChild_item;
    }

    int result = getBinarySearchTreeHeight(values, leftChild, rightChild);

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
