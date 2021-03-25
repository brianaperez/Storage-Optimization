#include <algorithm> // copy
#include <iostream> // cin, cout, streamsize
#include <iterator> // back_inserter, istream_iterator
#include <limits> // numeric_limits
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector

int storage_optimization(int n, int m, std::vector<int> h, std::vector<int> v) {
    // WRITE YOUR BRILLIANT CODE HERE
	  std::vector<int> gridx(n+2);
    std::vector<int> gridy(m+2);
    for(int i = 0; i < gridx.size(); i++)gridx.at(i) = i; //create x-grid from 0 to n+1
    for(int j = 0; j < gridy.size(); j++)gridy.at(j) = j; //same as above for y-grid

    for(int i = 0; i < gridx.size(); i++){
        for(int j = 0; j < h.size(); j++){
            if(gridx.at(i) == h.at(j))gridx.erase(gridx.begin() + i); //for loop to remove all dividers from gridx
        }
    }

    for(int i = 0; i < gridy.size(); i++){
        for(int j = 0; j < v.size(); j++){
            if(gridy.at(i) == v.at(j))gridy.erase(gridy.begin() + i); //same loop as above for gridy
        }
    }

    std::vector<int> newx;
    std::vector<int> newy;
    for(int i = gridx.size()-1; i > 0; i--)newx.push_back(gridx.at(i) - gridx.at(i-1));
    for(int i = gridy.size()-1; i > 0; i--)newy.push_back(gridy.at(i) - gridy.at(i-1));
    

    int max_X = *max_element(newx.begin(), newx.end());
    int max_Y = *max_element(newy.begin(), newy.end());
    int volume = max_X * max_Y;

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
