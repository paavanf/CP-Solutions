class ProductOfNumbers {
    private:
        vector<int>pp{1};
        
public:
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        if(num==0)
        pp={1};
        else
        pp.push_back(num*pp.back());
    }
    
    int getProduct(int k) {
        int n=pp.size();
        if(n<=k)
        return 0;
        return pp[n-1]/pp[n-k-1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */