#include<iostream>
#include<vector>

int main(){
    using namespace std;
    vector<int> vec{1,2,1,5,3,8,0};
        cout<<"vec start!\n";

    for(auto i:vec){
        cout<<i<<endl;
    } 
        cout<<"vec end!\n";

   


    return 0;
}
