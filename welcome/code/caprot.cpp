#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cout << "Incorrect number of arguments." << endl;
        return 1;
    }
    
    int rotation = atoi(argv[1]);
    string input;
    getline(cin, input);
    int len = input.length();
    string input1;
    input1 = input;

    for (int i = 0; i < len; i++) {
        char c = input[i];
        if (isalpha(c)) {
            if (isupper(c)) { 
                input1[i] = tolower(c); 
                
                if (i + rotation < len && islower(input[i + rotation])) { 
                    input1[i + rotation] = toupper(input1[i + rotation]);}
                else if (i + rotation >= len){ 
                    input1[rotation - (len - i)] = toupper(input1[rotation - (len - i)]); }
                
                else if (i + rotation < 0){
                    int r1=rotation%len;
                    cout << i << " " << r1 << endl;
                    if (i + r1 >=0) { 
                        input1[i + r1] = toupper(input1[i + r1]);}
                    else if (i + r1 < 0){
                        input1[len + (i + r1)] = toupper(input1[len + (i + r1)]); }                        
                    }
                }
            }
        }

    
    cout << input << endl;
    return 0;
}