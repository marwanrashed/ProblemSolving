#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the largestRectangle function below.
long largestRectangle(vector<int> h) {
// // stack<int> StackArea;
// std::sort(h.begin(),h.end());
// int k = h.size();
// int i =0;
// long max_area = k * h[0];
// int count = 0 ;
// while (i < h.size()) {
//     long area = 0;
//     if (h[i] < h[i+1]) {
//         k = k-1;
//         area = h[i+1] * (k-count);
//         max_area = max (area,max_area);
//         count = 0;
//     } 
//     else if (h[i] == h[i+1]) {
//       area = h[i] * k; 
//       max_area = max (area,max_area);
//       count ++;
//     }
//     i++;

stack<int> StackIndexHeight;
long area = 0;
int i = 0;
h.push_back(0);

while (i<h.size()){
    if ((StackIndexHeight.empty()) || (h[StackIndexHeight.top()] < h[i])) {
        StackIndexHeight.push(i);
        i++;
    }
    else {
        auto top = StackIndexHeight.top();
        StackIndexHeight.pop();
        if (!StackIndexHeight.empty()) {
            long val = h[top] * (i - StackIndexHeight.top() - 1);
            area = max (area, val);
        }
        else {
            long val = h[top] * i;
            area = max(area, val);
        }
    }
}
    return area;
}



int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string h_temp_temp;
    getline(cin, h_temp_temp);

    vector<string> h_temp = split_string(h_temp_temp);

    vector<int> h(n);

    for (int i = 0; i < n; i++) {
        int h_item = stoi(h_temp[i]);

        h[i] = h_item;
    }

    long result = largestRectangle(h);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
