#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    

    //1. make alphabet array
    //2. count alphabet frequency
            //if more than 1 --> initialize all number counting
    int lengthOfLongestSubstring(string s) {
        
        vector<int> substring_length;
        vector<int> ascii_code(127,0);
        int max = -1;
        int count = 1;
        
        if(s.length() == 0)
            return 0;
        else if(s.length() == 1)
            return 1;
        else
        {
            //1. check from the first letter
            for(int begin = 0; begin< s.length()-1; begin++)
            {
                ascii_code[s[begin]] += 1;

                for(int obj = begin+1; obj < s.length(); obj++)
                {
                    ascii_code[s[obj]] += 1;
                    if(ascii_code[s[obj]] > 1)
                    {

                        substring_length.push_back(count);
                        count = 1;

                        //initialize to 0.
                        for(auto j : ascii_code)
                            j = 0;
                    }
                    else
                    {
                        count++;
                        substring_length.push_back(count);
                    }
                }
            }
            
            for(auto i : substring_length)
            {
                if(max < i)
                    max = i;
            }

            return max;
        }
    }
};
