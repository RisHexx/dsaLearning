#include <bits/stdc++.h>
using namespace std;
#define ll long long


bool isPalidrome(string text){
    int i = 0 ;
    int j = text.size() - 1;

    while( i <= j){
        if(text[i] == text[j]){
            i++;
            j--;
        }else{
            return false;
        }
    }
    return true;
}

string removeDuplicates(string text){
    string unique = "";
    unique.push_back(text[0]);
    for(int i = 1 ; i < text.size() ; i++){
        bool flag = true;
        for(int j = 0 ; j < i ; j++){
            if(text[j] == text[i]){
                flag = false;
                break;
            }
        }
        if(flag){
            unique.push_back(text[i]);
        }
    }
    return unique;
}

vector<string> splitByDelimiter(string text , char delim){
    vector<string>arr;
    string temp = "";
    for(int i= 0 ; i <text.size() ; i++){
        if(text[i] != delim){
            temp+=text[i];
        }else{
            arr.push_back(temp);
            temp = "";
        }
    }
    return arr;
}

int main() {
    std::ios_base::sync_with_stdio(false);

    // character array
    char a[4] = {'r','i','s','\0'};
    // if we write in "" c/c++ automatically adds the \0 the end
    char b[] = "ball";

    //string -> more optimized
    string c = "rishabh";
    
    // cout<<isPalidrome("malylam")<<endl;

    // vector<string>result;
    // result = splitByDelimiter("ri$sh$abh$" , '$');
    // for(int i = 0 ; i < result.size() ; i++){
    //     cout<<result[i]<<" ";
    // }
    cout<<removeDuplicates("banana");
    


    
    return 0;
}