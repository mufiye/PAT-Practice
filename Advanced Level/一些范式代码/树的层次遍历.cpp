struct Node{
    // 其他字段
    vector<Node*> children;//子结点
}

queue<Node*> q;
Node *root; //=还要赋值
q.push(root);
Node* cur;
while (!q.empty()) {
    for(int i = 0, l = (int)q.size(); i < l; i++){
        cur = q.front();
        for(auto lt : cur->children){
             q.push(lt);
         }
        q.pop();
    }
}
