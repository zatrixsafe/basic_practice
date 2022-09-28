#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<stack>
#include<set>
#include<queue>
using namespace std;

class Solution{


public:


static bool cmpl(int x, int y){
    return x > y;
}
static bool cmpab(vector<int>& x, vector<int>& y){
    if(x[1]!=y[1]) return x[1] < y[1]; // 小于号是顺序
    return x[0] < y[0];
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
    ans.insert(pair<int, int>(1, 2));
    ans.insert(pair<int, int>(4, 3));
    ans.insert(pair<int, int>(99, 2));

    // find
    auto it = ans.find(100);
    if(it != ans.end()){
        cout<<"find "<<it->first<<" "<<it->second<<endl;
    }else {
        ans[100] = 1;
    }

    // sort
    vector< vector<int> > sort_v;
    it = ans.begin();
    while(it != ans.end()){// auto& [key, value]
        vector<int> tmp;
        tmp.push_back(it->first);
        tmp.push_back(it->second);
        sort_v.push_back(tmp);
        it++;
    }
    sort(sort_v.begin(), sort_v.end(), cmpab);
    cout<<"sort -------------"<<endl;

    for(auto v: sort_v){
        cout<<v[0]<<" "<<v[1]<<" ";
    }
    cout<<endl<<"sort end"<<endl;

    return ans;
}

// stack
stack<int> stack_test(){
    stack<int> ans;
    ans.push(1);
    ans.push(2);
    cout<<"stack size"<<ans.size()<<endl;
    cout<<"pop "<<ans.top()<<endl;
    ans.pop();
    cout<<"pop "<<ans.top()<<endl;
    ans.pop();
    return ans;
}

// quque
queue<int> queue_test(){
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(3);
    while(!q.empty()){
        for(int i = 0; i < q.size(); i++){
            int a = q.front();
            cout<<"queue front = "<<a<<" ";
            q.pop();
        }
    }
    cout<<endl;
    return q;
}

// priority_queue
priority_queue<int> pr_queue_test(){
    // https://leetcode.cn/problems/top-k-frequent-elements/solution/c-xiao-bai-you-hao-you-xian-dui-lie-de-j-53ay/
    //小顶堆 priority_queue <int,vector<int>,greater<int> > q;
    //大顶堆 priority_queue <int,vector<int>,less<int> >q;
    //默认大顶堆
    priority_queue<int> a;
    a.push(1);
    a.push(9);
    a.push(100);
    while(!a.empty()){
        int tmp = a.top();
        cout<<"priority queue top = "<<tmp<<" ";
        a.pop();
    }
    cout<<endl;

    // 仿函数
    struct myComparison{
        bool operator()(pair<int,int>& p1, pair<int,int>& p2){
            return p1.second>p2.second;//小顶堆是大于号
        }
    };
    priority_queue<pair<int,int>,vector< pair<int,int> >, myComparison> q;
    q.push(pair<int, int>(1, 22));
    q.push(pair<int, int>(100, 2));
    q.push(pair<int, int>(99, 3));
    q.push(pair<int, int>(100, 1));

    while(!q.empty()){
        auto& [key, value] = q.top();
        cout<<"priority queue pair ="<<key<<" "<<value<<endl;
        q.pop();
    }
    return a;
}

// Node
struct Node {
	int freq;
	int val;
	Node(int _freq, int _val):freq(0), val(_val){}
};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int _val):val(_val), left(nullptr), right(nullptr){}
};

vector<Node*> node_test(){
    vector<Node*> n;
    Node* tmp = new Node(1, 1);
    n.push_back(tmp);
    cout<<tmp->freq<<" "<<tmp->val<<endl;
    return n;
}

// set
set<int> set_test(){
    set<int> s;
    s.insert(1);
    s.insert(66);
    auto it = s.find(1);
    if(it != s.end()){
        cout<<1<<endl;
    }
    cout<<"set size "<<s.size()<<endl;
    it = s.begin();
    while(it != s.end()){
        cout<<"set loop "<<*it<<endl;
        it++;
    }

    return s;
}

// array


// string

// 构造函数

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
        cout<<i.first<<" "<<i.second<<" ";
    }
    cout<<endl;
    for(auto& [key, value]: m){
        cout<<key<<" "<<value;
    }
    cout<<endl;

    // stack 
    auto sta = s->stack_test();
    auto q = s->queue_test();
    auto qq = s->pr_queue_test();
    auto n = s->node_test();
    auto ss = s->set_test();
}