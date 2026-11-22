class Solution {
public:
    void backtracking(int index,unordered_map<int,string>& mapping,string& digits,string&current,vector<string>& result ){
        if(index==digits.size()){
            result.push_back(current);
            return;
        }
        int key=digits[index]-'0';
        string chars=mapping[key];
        for(int i=0;i<chars.size();i++){
            current.push_back(chars[i]);
            backtracking(index+1,mapping,digits,current,result);
            current.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>result;string current;
        unordered_map<int,string> mapping;
        if(digits.size()==0) return result;
        mapping[2]="abc";
        mapping[3]="def";
        mapping[4]="ghi";
        mapping[5]="jkl";
        mapping[6]="mno";
        mapping[7]="pqrs";
        mapping[8]="tuv";
        mapping[9]="wxyz";
        backtracking(0,mapping,digits,current,result);
        return result;

    }
};
