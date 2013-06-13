/*

Implement strStr().

Returns a pointer to the first occurrence of needle in haystack, or null if needle is not part of haystack.

*/

//2013/6/11 20:30:00
//这是一道水题，注意写之前想好测试用例
//这种大数据会超时
class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(haystack == NULL || needle == NULL)
        	return NULL;
        if(*haystack == '\0' && *needle == '\0')//注意这种情况
        	return "";

        char* pHaystack, *pNeedle, *p;

        pHaystack = haystack;
        pNeedle = needle;

        while(*pHaystack != '\0')
        {
        	p = pHaystack;
        	pNeedle = needle;
        	while(*pNeedle != '\0')
        	{
        		if(*p != *pNeedle)
        			break;
        		p++;
        		pNeedle++;
        	}
        	if(*pNeedle == '\0')
        		return pHaystack;

        	pHaystack++;
        }

        if(*pHaystack == '\0')return NULL;
        else return pHaystack;
    }
};

//2013/6/11 22:05:12
//这种方法去除一些多余的比较
class Solution {
 public:
     char *strStr(char *haystack, char *needle) {
         // Start typing your C/C++ solution below
         // DO NOT write int main() function
         int hayLen = strlen(haystack);
         int needLen = strlen(needle);
         
         for(int i = 0; i <= hayLen - needLen; i++)
         {
             char *p = haystack + i;
             char *q = needle;
             while(*q != '\0')
             {
                 if (*p != *q)
                     break;
                 else
                 {
                     p++;
                     q++;
                 }
             }
             
             if (*q == '\0')
                 return haystack + i;            
         }
         
         return NULL;
     }
 };