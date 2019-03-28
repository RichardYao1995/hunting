#include <vector>

void build_heap(std::vector<int> &vec, int num)
{
    for(int i = num / 2 - 1;i >= 0;i--)
    {
        if(vec[i * 2 + 1] > vec[i])
        {
            int temp = vec[i];
            vec[i] = vec[i * 2 + 1];
            vec[i * 2 + 1] = temp;
        }
        if((i * 2 + 2) < num)
        {
            if(vec[i * 2 + 2] > vec[i])
            {
                int temp = vec[i];
                vec[i] = vec[i * 2 + 2];
                vec[i * 2 + 2] = temp;
            }
        }
    }
}

void heap_sort(std::vector<int> &vec)
{
    for(int i = 0;i < vec.size();i++)
    {
        build_heap(vec, vec.size() - i);
        int temp = vec[0];
        vec[0] = vec[vec.size() - 1 - i];
        vec[vec.size() - 1 - i] = temp;
    }
}
