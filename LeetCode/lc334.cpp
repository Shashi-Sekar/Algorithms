#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    vector<int> vec = {15, 3, 4, 6, 23, 67, 6, 8, 9, 10, 11, 43};
    vector<int> dc;

    for(auto n : vec){
        auto it = lower_bound(dc.begin(), dc.end(), n);

        if(it == dc.end()){
            dc.push_back(n);
            continue;
        }

        if(*it > n){
            *it = n;
        }
    }

    for(auto n: dc){
        cout << n << " ";
    }

    /*
    int value = 7;
    auto it = lower_bound(vec.begin(), vec.end(), value);    

    if(it != vec.end()){
        cout << "The first element not less than " << value << " is at position: "<<(it - vec.begin()) << endl;
        cout << "The element is: " << *it << endl;
    }
    else{
        cout << "No element not less than " << value << " found in the vector " << endl;
    }
    */

   return 0;
}