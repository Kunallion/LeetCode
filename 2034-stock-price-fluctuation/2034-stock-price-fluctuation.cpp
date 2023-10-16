class StockPrice {
public:

    // Mp1 for storing the timestamp and their corrsesponding prices
    map<int,int> mp1;

    // Mp2 for storing the prices and how many times they have occured
    map<int,int> mp2;
    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
        if(mp1.find(timestamp)==mp1.end()){
            mp1[timestamp] = price;
            mp2[price]++;
        }
        else{
            mp2[mp1[timestamp]]--;
            if(mp2[mp1[timestamp]]==0)
                mp2.erase(mp1[timestamp]);
            mp2[price]++;
            mp1[timestamp] = price;
        }
    }
    
    int current() {

        // rbegin is the function to start traversing from end. Latest Timestamp will be at the end of the ordered_map
        return mp1.rbegin()->second;
    }
    
    int maximum() {

        // Since we are using ordered_map, so the maximum price will be at the end, hence we are using rbegin() to access the last element
        return mp2.rbegin()->first;
    }
    
    int minimum() {

        // Since we are using ordered_map, so the minimum price will be at the beginning, hence we are using begin() to access the first element
        return mp2.begin()->first;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */