#include <bits/stdc++.h>

using namespace std;

string timeConversion(string s) {
    // Complete this function
    if(s[8] == 'P'){
    	string n = s.substr(0,2);
    	int i = stoi(n,NULL);
        if(i == 12){
            return s.substr(0,8);
        }
    	i = i + 12;
        n = to_string(i);
        string t = s.substr(2,6);
        n = n + t;
        return n;
    }
    else {
        string n = s.substr(0,2);   
        int i = stoi(n,NULL);
        if(i==12){
            return "00"+s.substr(2,6);
        }
        return s.substr(0,8);
    }
}



int main() {
    string s;
    cin >> s;
    string result = timeConversion(s);
    cout << result << endl;
    return 0;
}
