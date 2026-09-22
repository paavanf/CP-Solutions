class Segtree{
    private:
    static const int maxk = 6;
    int k;
    int n;
    vector <array<int, maxk>> tree;

    void makeLeaf(int node, int value){
        tree[node].fill(0);

        int r = value % k;
        tree[node][r] = 1;
        tree[node][k] = r;
    }

    void mergeNodes(const array<int, maxk> & left, const array <int, maxk>& right, array <int, maxk>& result){
        result.fill(0);

        int leftProduct = left[k];
        int rightProduct = right[k];

        result[k] = (leftProduct * rightProduct) % k;

        for(int x = 0; x < k; x ++){
            result[x] = left[x];
        }

        for(int x = 0; x < k; x ++){
            int r = (leftProduct * x) % k;
            result[r] += right[x];
        }
    }

    void maintain(int node){
        mergeNodes(tree[node * 2], tree[node * 2 + 1], tree[node]);
    }

    void build(const vector <int> & nums, int node, int tl, int tr){
        if(tl == tr){
            makeLeaf(node, nums[tl]);
            return;
        }

        int tm = (tl + tr) / 2;
        build(nums, node * 2, tl, tm);
        build(nums, node * 2 + 1, tm + 1, tr);
        maintain(node);
    }

public:
    Segtree(const vector <int>& nums, int k) : k(k), n(nums.size()){
        int size = 2 << (int)ceil(log2(n));
        tree.resize(size);
        build(nums, 1, 0, n - 1);
    }

    void update(int node, int tl, int tr, int index, int value){
        if(tl == tr){
            makeLeaf(node, value);
            return;
        }

        int tm = (tl + tr) / 2;
        if(index <= tm)
            update(node * 2, tl, tm, index, value);
        else 
            update(node * 2 + 1, tm + 1, tr, index, value);

        maintain(node);
    }

    array <int, maxk> query(int node, int tl, int tr, int l, int r){
        if(l <= tl && tr <= r){
            return tree[node];
        }

        int tm = (tl + tr) / 2;
        if(r <= tm){
            return query(node * 2, tl, tm, l, r);
        }
        if(l > tm){
            return query(node * 2 + 1, tm + 1, tr, l, r);
        }

        array <int, maxk> left = query(node * 2, tl, tm, l, r);
        array<int, maxk> right = query(node * 2 + 1, tm + 1, tr, l, r);
        array<int, maxk> result;
        mergeNodes(left, right, result);
        return result;
    }
};

class Solution {
public:
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        Segtree seg(nums, k);
        vector <int> ans;
        int n = nums.size();
        for(auto & q : queries){
            int idx = q[0], val = q[1], start = q[2], x = q[3];
            seg.update(1, 0, n - 1, idx, val);
            auto prefix = seg.query(1, 0, n -1, start, n - 1);
            ans.push_back(prefix[x]);
        }

        return ans;
    }
};