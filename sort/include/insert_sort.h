#include <vector>

void insert_sort(std::vector<int> &vec)
{
    for(int i = 1;i < vec.size();i++)
    {
        for(int j = i;j > 0;j--)
        {
            if(vec[j] >= vec[j - 1])
                break;
            int temp = vec[j];
            vec[j] = vec[j - 1];
            vec[j - 1] = temp;
        }
    }
}
