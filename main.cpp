#include <iostream>
#include <map>
#include <vector>
#define TARGET 9
int findLevel(const int & target){
    int counter{0};
    int current{0};
    while (current < target){
        ++counter;
        current += counter;
    }
    return counter;
}

std::map<int, std::vector<int>> makeTriangle(int levels){
    std::map<int, std::vector<int>> triangle{{1, {0, 1, 0}}};
    for (int i = 2; i <= levels; ++i){
        std::vector<int> vec = {0};
        for (int j = 1; j <= i; ++j){
            vec.push_back(triangle.at(i-1).at(j-1) + triangle.at(i-1).at(j));
        }
        vec.push_back(0);
        triangle.insert({i, vec});
    }
    for (int i = 1; i <= levels; ++i){
        triangle.at(i).erase(std::remove(triangle.at(i).begin(), triangle.at(i).end(), 0), triangle.at(i).end());
    }
    return triangle;
}

int getValue(const std::map<int, std::vector<int>> & triangle, int target){
    int val{};
    int level{1};
    int inLevel{0};
    while (target > 0){
        while (inLevel < level) {
            val = triangle.at(level).at(inLevel);
            --target;
            if (target == 0)
                return val;
            ++inLevel;
        }
        ++level;
        inLevel=0;
    }
    return val;
}

int main() {
    std::cout<<getValue(makeTriangle(findLevel(TARGET)), TARGET);
    return 0;
}
