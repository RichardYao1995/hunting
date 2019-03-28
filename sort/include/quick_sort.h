#include <vector>

void sort(std::vector<int> &vec, int begin, int end);
int partition(std::vector<int> &vec, int begin, int end);

void quick_sort(std::vector<int> &vec)
{
    int length = vec.size();
    sort(vec, 0, length - 1);
}

void sort(std::vector<int> &vec, int begin, int end)
{
    if(end - begin == 0)
        return;
    if(end - begin == 1)
    {
        if(vec[end] < vec[begin])
        {
            int temp = vec[end];
            vec[end] = vec[begin];
            vec[begin] = temp;
        }
        return;
    }
    int i = partition(vec, begin, end);
    if(i > begin)
        sort(vec, begin, i - 1);
    if(i < end)
        sort(vec, i + 1, end);
}

int partition(std::vector<int> &vec, int begin, int end)
{
    int j = begin - 1;
    for(int i = begin;i < end;i++)
    {
        if(vec[i] < vec[end])
        {
            int temp;
            j++;
            temp = vec[j];
            vec[j] = vec[i];
            vec[i] = temp;
        }
    }
    int temp;
    temp = vec[j + 1];
    vec[j + 1] = vec[end];
    vec[end] = temp;
    return (j + 1);
}
