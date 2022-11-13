#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

void timeConversion(string s) {
    
    stringstream h(s) , t;
    int hr;
    
    h>>hr;
    
    if(s[8] == 'P'){
        hr += 12;
    }
    
    t<<hr;
    char ch;
    t>>ch;

    cout<<ch;
    

    
    
    

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

  //  string result = timeConversion(s);

    //fout << result << "\n";

    fout.close();

    return 0;
}
