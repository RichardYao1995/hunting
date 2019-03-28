#include <vector>

std::vector<int> merge(std::vector<int> vec1, std::vector<int> vec2);
std::vector<int> do_divide(std::vector<int> vec, int begin, int end);

void merge_sort(std::vector<int> &vec)
{
    int begin = 0;
    int end = vec.size() - 1;
    vec = do_divide(vec, begin, end);
}

std::vector<int> do_divide(std::vector<int> vec, int begin, int end)
{
    if(end - begin == 0)
    {
        std::vector<int> vec11;
        vec11.push_back(vec[begin]);
        return vec11;
    }
    if(end - begin == 1)
    {
        std::vector<int> vec11;
        int temp1, temp2;
        temp1 = (vec[begin] < vec[end])? vec[begin] : vec[end];
        temp2 = (vec[begin] > vec[end])? vec[begin] : vec[end];
        vec11.push_back(temp1);
        vec11.push_back(temp2);
        return vec11;
    }
    int mid = (begin + end) / 2;
    std::vector<int> vec1, vec2;

    vec1 = do_divide(vec, begin, mid);
    vec2 = do_divide(vec, mid + 1, end);
    vec = merge(vec1, vec2);

    return vec;
}

std::vector<int> merge(std::vector<int> vec1, std::vector<int> vec2)
{
    std::vector<int> result;
    std::vector<int>::iterator it1 = vec1.begin();
    std::vector<int>::iterator it2 = vec2.begin();
    while(it1 < vec1.end() && it2 < vec2.end())
    {
        if((*it1) > (*it2))
        {
            result.push_back(*it2);
            it2++;
        }
        else
        {
            result.push_back(*it1);
            it1++;
        }
    }
    if(it1 == vec1.end())
    {
        while(it2 < vec2.end())
        {
            result.push_back(*it2);
            it2++;
        }
    }
    else
    {
        while(it1 < vec1.end())
        {
            result.push_back(*it1);
            it1++;
        }
    }
    return result;
}
