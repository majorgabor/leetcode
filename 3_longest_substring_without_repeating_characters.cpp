#include <string>
#include <iostream>

int lengthOfLongestSubstring(std::string s)
{
    std::string non_repeating;
    size_t max_so_far = 0;
    for (char c : s)
    {
        if (size_t pos = non_repeating.find(c); pos != std::string::npos)
        {
            if (max_so_far < non_repeating.length())
            {
                max_so_far = non_repeating.length();
            }
            non_repeating.erase(0, pos + 1);
        }
        non_repeating.push_back(c);
    }
    return std::max(max_so_far, non_repeating.length());
}

int main()
{
    std::string s{"abcabcbb"};
    std::cout << "s: " << s << " -> output: " << lengthOfLongestSubstring(s) << std::endl;

    s = "bbbbb";
    std::cout << "s: " << s << " -> output: " << lengthOfLongestSubstring(s) << std::endl;

    s = "pwwkew";
    std::cout << "s: " << s << " -> output: " << lengthOfLongestSubstring(s) << std::endl;
    return 0;
}