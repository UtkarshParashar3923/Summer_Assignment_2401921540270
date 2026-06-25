class Codec {
public:

    void serializeHelper(TreeNode* root, string& s) {

        if(root == nullptr){
            s += "N,";
            return;
        }

        s += to_string(root->val) + ",";

        serializeHelper(root->left, s);
        serializeHelper(root->right, s);
    }

    string serialize(TreeNode* root) {

        string s = "";

        serializeHelper(root, s);

        return s;
    }

    TreeNode* deserializeHelper(stringstream& ss) {

        string str;
        getline(ss, str, ',');

        if(str == "N")
            return nullptr;

        TreeNode* root = new TreeNode(stoi(str));

        root->left = deserializeHelper(ss);
        root->right = deserializeHelper(ss);

        return root;
    }

    TreeNode* deserialize(string data) {

        stringstream ss(data);

        return deserializeHelper(ss);
    }
};
