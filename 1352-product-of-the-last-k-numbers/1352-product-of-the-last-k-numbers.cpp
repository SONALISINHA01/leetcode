class ProductOfNumbers {
public:
    vector<int> prefixproduct;
    int size = 0;
    ProductOfNumbers() {
        prefixproduct.push_back(1);
        size=0;
    }
    
    void add(int num) {
        if(num == 0){
            prefixproduct = {1};
            size = 0;
        }else{
           int m =num*prefixproduct[size];
            prefixproduct.push_back(m);
            size++;
        }
    }
    
    int getProduct(int k) {
        if(k>size){
            return 0;
        }else{
            return prefixproduct[size]/prefixproduct[size-k];
        }
        
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */