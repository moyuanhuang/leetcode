//
//  main.cpp
//  ontology
//
//  Created by daHuang on 17/1/7.
//  Copyright © 2017年 daHuang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;

template <int Size>
struct TrieNode{
    bool is_leaf;
    int num_node;
    int num_question;
    TrieNode *children[Size];
    
    TrieNode(): is_leaf(false), num_node(0), num_question(0)
    { memset(children, 0, sizeof(children));}
};

// Trie Implementation
template <int Size, typename Map>
class Trie{
public:
    typedef TrieNode<Size> node_type;
    typedef TrieNode<Size>* node_ptr;
    
    Trie(node_type r = node_type(), Map m = Map()) : root_(r), map_(m){}
//    Trie(): root_(node_type()), map_(Map()){}
    
    void Insert(string str){
        node_ptr cur = &root_;
        for(char key: str){
            if(!cur->children[map_[key]]){
                cur->children[map_[key]] = new node_type;
                ++cur->num_node;
            }
            cur = cur->children[map_[key]];
            ++cur->num_question;
        }
        cur->is_leaf = true;
        return;
    }
    // overload version
    void Insert(const char* c_str){
        string str(c_str);
        Insert(str);
    }
    
    int Find(string str){
        node_ptr cur = &root_;
        for(char key : str){
            if(cur->is_leaf or !cur->children[map_[key]])
                return 0;
            cur = cur->children[map_[key]];
        }
        return cur->num_question;
    }
    
    void Traverse(){
        cout << "Questions under this topic:" << endl;
        string question("");
        TraverseHelper(&root_, question);
    }

private:
    void TraverseHelper(node_ptr root, string &question){
        if(root->is_leaf){
            cout << question << endl;
            return;
        }
        for(int i = 0; i < Size; ++i){
            if(root->children[i]){
                question += map_.Back(i);
                TraverseHelper(root->children[i], question);
                question.erase(question.end()-1);
            }
        }
        return;
    }
    node_type root_;
    Map map_;
};

class Alphabet_Map{
public:
    int operator[](const char key){
        if(key == ' ')  return 0;
        else if(key == '?') return 1;
        else if(key <= 'Z' and key >= 'A')  return key - 'A' + 2;
        else if(key <= 'z' and key >= 'a')  return key - 'a' + 28;
        else{
            cout << "unrecognized character:" << key << ". Exit..."<< endl;
        }
        return -1;
    }
    
    string Back(int key){
        char *c = new char[2];
        if(key == 0)    *c = ' ';
        else if(key == 1)   *c = '?';
        else if(key >= 2 and key <= 27) *c = key - 2 + 'A';
        else if(key >= 28 and key <= 53)    *c = key - 28 + 'a';
        else{
            cout << "unrecognized character:" << key << ". Exit..."<< endl;
        }
        return string(c);
    }
};

template <typename Trie>
struct TreeNode{
    Trie trie;
    vector<string> children;
    
    TreeNode(Trie t = Trie()) : trie(t) { }
};

// Tree Implementation
template <typename Trie>
class Tree{
public:
    typedef TreeNode<Trie> node_type;
    typedef TreeNode<Trie>* node_ptr;
    
//    Tree() {}
    
    void AddNode(string father, vector<string> children){
        if(treemap_.count(father) == 0)
            treemap_[father] = new node_type;
        for(string child : children)
            treemap_[father]->children.push_back(child);
        return;
    }
    // overload version
    void AddNode(const char* str, vector<string> children){
        string father(str);
        AddNode(father, children);
    }
    void AddNode(char* str, vector<string> children){
        string father(str);
        AddNode(father, children);
    }
    void AddQuestion(string topic, string sentence){
        if(treemap_.count(topic) == 0)
            cerr << "Topic " << topic << " has never been added to the tree. Exit..." << endl;
        else
            treemap_[topic]->trie.Insert(sentence);
        return;
    }
    //overload version
    void AddQuestion(const char* topic_c_str, const char* sentence_c_str){
        string topic(topic_c_str);
        string sentence(sentence_c_str);
        AddQuestion(topic, sentence);
    }
    void AddQuestion(char* topic_c_str, char* sentence_c_str){
        string topic(topic_c_str);
        string sentence(sentence_c_str);
        AddQuestion(topic, sentence);
    }
    
    void Query(string topic, string prefix, int &count){
        if(treemap_.count(topic) == 0)
            return;
        count += treemap_[topic]->trie.Find(prefix);
        for(string child : treemap_[topic]->children){
            Query(child, prefix, count);
        }
        return;
    }
    // overload version
    int Query(const char* topic_c_str, const char* prefix_c_str){
        string topic(topic_c_str);
        string prefix(prefix_c_str);
        return Query(topic, prefix);
    }
    int Query(char* topic_c_str, char* prefix_c_str){
        string topic(topic_c_str);
        string prefix(prefix_c_str);
        return Query(topic, prefix);
    }
    
    void Traverse(){
        for(auto it = treemap_.begin(); it != treemap_.end(); ++it){
            if(it->second->children.empty())
                cout << it->first << " is a leaf node";
            else{
                cout << it->first << " has child: ";
                for(size_t i = 0; i < it->second->children.size(); ++i)
                    cout << " " << it->second->children[i];
            }
            cout << endl;
            Trie trie = it->second->trie;
            trie.Traverse();
        }
        return;
    }
    
private:
    unordered_map<string, node_ptr> treemap_;
};

template <typename Tree>
class Ontology{
public:
    Ontology(Tree t = Tree()) : tree_(t) { }
    
    Ontology(string flat_tree){
        tree_ = FlatTreeHelper(flat_tree);
    }
    
    void SaveQuestion(string question){
        //split topic and question
        size_t pos = question.find_first_of(":", 0);
        string topic = question.substr(0, pos);
        question = question.substr(pos+1);
        if(question[0] == ' ')  question.erase(0, 1);
        tree_.AddQuestion(topic, question);
        return;
    }
    
    int FindQueryCount(string query){
        size_t pos = query.find_first_of(" ", 0);
        string topic = query.substr(0, pos);
        string prefix = query.substr(pos+1);
        int count = 0;
        tree_.Query(topic, prefix, count);
        return count;
    }
    
    void ShowTree(){
        tree_.Traverse();
    }
    
private:
    Tree FlatTreeHelper(string str){
        Tree tree;
        stack<string> st;
        string pattern(" ");
        str += pattern;  // add delimeter into string, otherwise will loop infinitely.
        for(size_t i = 0; i < str.length(); i++){
            size_t pos = str.find(pattern, i);
            if(pos < str.length()){
                string cur_topic = str.substr(i, pos - i);
                if(cur_topic == ")"){
                    vector<string> children;
                    string tmp = st.top();
                    st.pop();
                    while(tmp != "("){
                        tree.AddNode(tmp, vector<string>());
                        children.push_back(tmp);
                        tmp = st.top();
                        st.pop();
                    }
                    tree.AddNode(st.top(), children);
                }
                else
                    st.push(cur_topic);
            }
            i = pos + pattern.length() - 1;
        }
        return tree;
    }
    
    Tree tree_;
    
};


int main(int argc, const char * argv[]) {
    // insert code here...
    string input;
    int x;
    cin >> x;
    cin.get();
    getline(cin, input);
    Ontology<Tree<Trie<56, Alphabet_Map> > > o(input);
//    cout << "flatten Tree: " << input << endl;
//    cout << "Insert M:" << endl;
    cin >> x;
    cin.get();
    for(int i = 0; i < x; ++i)
    {
        getline(cin, input);
        o.SaveQuestion(input);
    }
    vector<int> ans;
    cin >> x;
    cin.get();
    for(int i = 0; i < x; ++i)
    {
        getline(cin, input);
        ans.push_back(o.FindQueryCount(input));
    }
    for(int a : ans)
        cout << a << endl;
    return 0;
    
    
    
}
