#include <algorithm> // copy
#include <iostream> // cin, cout, streamsize
#include <iterator> // back_inserter, istream_iterator
#include <limits> // numeric_limits
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector

int storage_optimization(int n, int m, std::vector<int> h, std::vector<int> v) {
    // WRITE YOUR BRILLIANT CODE HERE
    int xcur = 0; int xmax = 0; int ycur = 0; int ymax = 0; int volume = 0;
    std::vector<int>grid_x(n+2);
    std::vector<int>grid_y(m+2);
    for(int i = 0; i < grid_x.size(); i++)
        grid_x.at(i) = i;
    
    for(int j = 0; j < grid_y.size(); j++)
        grid_y.at(j) = j;
    
    for(int k = 0; k < grid_x.size(); k++)
        for(int l = 0; l < h.size(); l++)
            if(grid_x.at(k) == h.at(l))
                grid_x.erase(grid_x.begin()+k);
    
    for(int k = 0; k < grid_y.size(); k++)
        for(int l = 0; l < v.size(); l++)
            if(grid_y.at(k) == v.at(l))
                grid_y.erase(grid_y.begin()+k);
    
    for(int i = grid_x.size()-1; i > 0; i--){
        xcur = grid_x.at(i) - grid_x.at(i-1);
        if(xcur > xmax)xmax = xcur;
    } 
    for(int i = grid_y.size()-1; i > 0; i--){
        ycur = grid_y.at(i) - grid_y.at(i-1);
        if(ycur > ymax)ymax = ycur;
    }
    volume = xmax * ymax * 1;
    return volume;
}

void ignore_line() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

template<typename T>
std::vector<T> get_words() {
    std::string line;
    std::getline(std::cin, line);
    std::istringstream ss{line};
    std::vector<T> v;
    std::copy(std::istream_iterator<T>{ss}, std::istream_iterator<T>{}, std::back_inserter(v));
    return v;
}

int main() {
    int n;
    std::cin >> n;
    ignore_line();
    int m;
    std::cin >> m;
    ignore_line();
    std::vector<int> h = get_words<int>();
    std::vector<int> v = get_words<int>();
    int res = storage_optimization(n, m, h, v);
    std::cout << res << '\n';
}
