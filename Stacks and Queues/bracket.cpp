#include <bits/stdc++.h>

using namespace std;

char GetReversedBracket (char a){
    switch (a){
    case '(' : return ')';
    case '{' : return '}';
    case '[' : return ']';
    case ')' : return '(';
    case '}' : return '{';
    case ']' : return '[';
    }
    return a;
}

bool isRightBracket (char a){
    vector<char> v{']',')','}'};
    if (std::find(v.begin(),v.end(),a) != v.end()){
        return true;
    }
    return false;
}

bool isLeftBracket (char a){
    vector<char> v{'[','(','{'};
    if (std::find(v.begin(),v.end(),a) != v.end()){
        return true;
    }
    return false;
}

// Complete the isBalanced function below.
string isBalanced(string s) {
stack<char> BracketStack; 
for (auto i : s){
    auto rev = GetReversedBracket(i);
    if (isLeftBracket(i)){
        BracketStack.push(i);
    }    
    if (BracketStack.empty()){
        return "NO"; 
    }
    if (isRightBracket(i)) {
        if (BracketStack.top() == rev) {
            BracketStack.pop();
        }
        else if (BracketStack.top() != rev){
            return "NO";  

    }
        
    }
    
}
    
    if (BracketStack.empty()) {
        return "YES";}
    return "NO";

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string s;
        getline(cin, s);

        string result = isBalanced(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
