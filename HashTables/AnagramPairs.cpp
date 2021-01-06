#include <bits/stdc++.h>

using namespace std;

// Complete the sherlockAndAnagrams function below.
int sherlockAndAnagrams(string s) {
    unordered_map<string, int> SubstringsFreq;
    // Pick starting point in outer loop
    // and lengths of different strings for
    // a given starting point
    int n = s.size();
    for (int i = 0; i < n; i++){ 
        for (int len = 1; len <= n - i; len++){
            auto stringTemp =  s.substr(i, len); 
            sort (stringTemp.begin(),stringTemp.end());
            SubstringsFreq[stringTemp]++;
            }
    }
    unordered_map<string, int>::iterator itr;
    int anagramPairs = 0;
    for (itr = SubstringsFreq.begin(); itr != SubstringsFreq.end();itr++) {
        int v = itr->second;
        anagramPairs += (v*(v-1))/2; 
    }
    return anagramPairs;
    

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = sherlockAndAnagrams(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
