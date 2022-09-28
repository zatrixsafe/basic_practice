#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution{
public:
static bool cmpl(int x, int y){
    return x > y;
}
vector<int> vector_test(int a, int b, int c){
    vector<int> ans;
    ans.push_back(a);
    ans.push_back(b);
    ans.push_back(c);

    int m[3] = {a, b, c};
    vector<int> ans_a(a, a+3);

    vector<int> ans_b(10, 1);
    vector<int> ans_c(10);

    int sort_array[8] = {1, 2, 3, 4, 0, 9, 8, 1111};
    vector<int> ans_d(sort_array, sort_array+8);
    for(auto v: ans_d){
        cout<<v<<" ";
    }
    cout<<endl;

    sort(ans_d.begin(), ans_d.end(), cmpl);
    // insert
    ans_d.insert(ans_d.begin()+1, 128);

    // split
    vector<int>::const_iterator it = ans_d.begin();
    vector<int> left(it, it+3);

    return left;
}

unordered_map<int, int> map_test(){
    unordered_map<int, int> ans;

    return ans;
}


};

int main(){
        cout<<"hello world"<<endl;
        cout<<INT_MAX<<" "<<INT_MIN<<endl;
        Solution* s =new Solution();

        // vector
        auto v = s->vector_test(1, 2, 3);
        for(auto i: v){
            cout<<i<<" ";
        }
        cout<<endl;

        auto m = s->map_test();
        // unordered_map
        for(auto i: m){
            cout<<i.first<<" "<<i.second;
        }
        cout<<endl;
        for(auto& [key, value]: m){
            cout<<key<<" "<<value;
        }
        cout<<endl;
}