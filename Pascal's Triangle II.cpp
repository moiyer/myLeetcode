/*

Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space?

*/
//2013/8/27 20:05:45
//水题
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        std::vector<int> ret;
        if(rowIndex < 0)return ret;

        int *data = new int[rowIndex + 1]();

        for(int i = 0; i <= rowIndex; ++i)
        	data[i] = 1;

        for(int i = 2; i <= rowIndex; ++i)
        {
        	for(int j = i - 1; j >= 1; --j)
        		data[j] = data[j - 1] + data[j];
        }

        std::vector<int> rr(data, data + rowIndex + 1);
        delete [] data;
        return rr;
    }
};