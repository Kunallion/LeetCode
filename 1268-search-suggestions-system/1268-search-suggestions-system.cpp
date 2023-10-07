class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        
        string str="";
        vector<vector<string>> ans;
        int flag=0;

        //Sort the products arr so that we don't need to traverse the whole arr again and again
        sort(products.begin(), products.end());

        // Traverse all characters one by one
        for(int i=0 ; i<searchWord.length() ; i++)
        {
            str += searchWord[i];

            //For each next char,we will be inserting an array in our ans of top three searches
            vector<string> temp;
            flag=1;

            for(int j=0 ; j<products.size() ; j++)
            {
                int l=0, k;

                // Matching the words
                for(k=0 ; k<str.length() ; k++){
                    if(products[j][l]!=str[k])
                        break;
                    l++;
                }

                // If all chars matched, then push the product in our temp arr
                if(k==str.length()){
                    temp.push_back(products[j]);
                }

                // If we already got three seraches, then we can stop here
                if(temp.size()==3){
                    ans.push_back(temp);
                    temp.clear();
                    flag=0;
                    break;
                }
            }

            // If we didn't get three searches, but still we need to append this arr
            if(flag==1)
                ans.push_back(temp);
        }
        return ans;
    }
};