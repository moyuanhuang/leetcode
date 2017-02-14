#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>
#if defined(__unix__) || defined(__APPLE__)
#include <sys/resource.h>
#endif

using namespace std;

class Node;

class Node {
public:
    int key;
    Node *parent;
    std::vector<Node *> children;
    
    Node() {
        this->parent = NULL;
    }
    
    void setParent(Node *theParent) {
        parent = theParent;
        parent->children.push_back(this);
    }
};

void helper(Node root, int &height, int tmp){
    if(root.children.empty()){
        height = max(height, tmp);
        return;
    }
    for(auto child : root.children)
        helper(*child, height, tmp+1);
    return;
}

int main_with_large_stack_space() {
    std::ios_base::sync_with_stdio(0);
    int n;
    std::cin >> n;
    
    std::vector<Node> nodes;
    nodes.resize(n);
    int root_index = -1;
    for (int child_index = 0; child_index < n; child_index++) {
        int parent_index;
        std::cin >> parent_index;
        if (parent_index >= 0)
            nodes[child_index].setParent(&nodes[parent_index]);
        else
            root_index = child_index;
        nodes[child_index].key = child_index;
    }
    
    // Replace this code with a faster implementation
    int ans = INT_MIN;
    helper(nodes[root_index], ans, 1);
    cout << ans << endl;
    return ans;
}

int main (int argc, char **argv)
{
#if defined(__unix__) || defined(__APPLE__)
    // Allow larger stack space
    const rlim_t kStackSize = 16 * 1024 * 1024;   // min stack size = 16 MB
    struct rlimit rl;
    int result;
    
    result = getrlimit(RLIMIT_STACK, &rl);
    if (result == 0)
    {
        if (rl.rlim_cur < kStackSize)
        {
            rl.rlim_cur = kStackSize;
            result = setrlimit(RLIMIT_STACK, &rl);
            if (result != 0)
            {
                std::cerr << "setrlimit returned result = " << result << std::endl;
            }
        }
    }
    
#endif
    return main_with_large_stack_space();
}
