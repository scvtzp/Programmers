#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <algorithm>
#include <unordered_set>
using namespace std;

//초기단계. 최대 계산 횟수 10억x10억x10만. unordered_set사용하여 처리 속도는 빠르지만 계산해야 하는 양이 너무 많음.

struct XY
{
    XY(long long _x, long long _y) : x(_x), y(_y) {}
    int x;
    int y;

    bool operator== (XY _Other) const
    {
        return (x == _Other.x && y == _Other.y);
    }

    size_t operator () (XY& Hash) const
    {
        return Hash.x;
    }
};

template<>
struct hash<XY>
{
    uint64_t operator () (XY Hash) const
    {
        return ((uint64_t)Hash.x) << 32 | (uint64_t)Hash.y;
    }
};

long long solution(vector<vector<int>> rectangles)
{
    unordered_set<XY> SaveSet;
    for (vector<int> iter : rectangles)
    {
        for (long long i = iter[0]; i < iter[2]; i++)
            for (long long j = iter[1]; j < iter[3]; j++)
                SaveSet.insert(XY(i, j));
    }
    return SaveSet.size();
}

int main()
{
    long long a = solution({ {1, 1, 6, 5}, {2, 0, 4, 2}, {2, 4, 5, 7}, {4, 3, 8, 6}, {7, 5, 9, 7} });
    cout << a;
}