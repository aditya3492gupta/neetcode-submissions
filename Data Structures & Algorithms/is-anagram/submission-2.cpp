class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> mp;
        if(s.size() != t.size())
            return false;
        for(auto i : s){
            mp[i]++;
        }
        for(int i = 0 ; i < t.size() ; i++){
            if(mp.find(t[i]) != mp.end()){
                mp[t[i]]--;
                if(mp[t[i]] == 0){
                    mp.erase(t[i]);
                }
            }
            else
                return false;
        }
        return true;
    }
};
