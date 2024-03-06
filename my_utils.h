#include <iostream>
#include <vector>

template <typename T>
std::ostream &operator<<(std::ostream &out, const std::vector<T> &v)
{
    out << '[';
    for (size_t i = 0; i < v.size(); i++)
    {
        if (i == v.size() - 1)
        {
            out << v[i] << ']';    
        }
        else
        {
            out << v[i] << ", ";
        }
    }
    return out;
}