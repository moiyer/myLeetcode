/*

Given an array of strings, return all groups of strings that are anagrams.

Note: All inputs will be in lower-case.

*/
//2013/6/30 15:57:18
//水题,注意map的用法
class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
    vector<string> cc;
    map<string, vector<string> > dict;
    vector<string>::iterator st;
    for(st = strs.begin(); st != strs.end(); st++) {
        string key = *st;
        sort(key.begin(), key.end());
        dict[key].push_back(*st);
    }
    map<string, vector<string> >::iterator it;
    for(it = dict.begin(); it != dict.end(); it++) {
        if(it->second.size() > 1)
            for(st = it->second.begin(); st != it->second.end(); st++)
                cc.push_back(*st);
    }
    return cc;
}
};