class Node{
public:
    int cnt;
    vector <Node*> a;
    Node(){
        cnt=0;
        a = vector <Node*> (26, nullptr);
    }
};
Node* beg = new Node();
void add(string& s){
    Node* cur = beg;
    cur ->cnt++;
    for (int i=0; i<s.size(); i++){
        if (cur->a[s[i]-'a']==nullptr) cur->a[s[i]-'a'] = new Node();
        cur = cur->a[s[i]-'a'];
        cur->cnt++;
    }
}
