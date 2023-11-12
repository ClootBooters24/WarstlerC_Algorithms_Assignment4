#include <sort.hpp>
#include <graph.hpp> 

//extern
std::string sortAlgName = "Quick Sort";

template<class T>
void sort(std::vector<T> &array, int l, int r) {
    // YOUR CODE HERE
    // Sorray array from l to r, i.e. sort array[l...r]

    if(l < r) {
        int pIndex = partition(array, l, r);
        sort(array, l, pIndex - 1);
        sort(array, pIndex + 1, r);
    }
}

template<class T>
void swap(T &a, T &b) {
    T tmp = a;
    a = b;
    b = tmp;
}

template<class T>
int partition(std::vector<T> &array, int l, int r) {
    T pivot = array[r];
    int i = l - 1;

    for (int j = l; j < r; ++j) {
        if (array[j] < pivot) {
            ++i;
            swap(array[i], array[j]);
        }
    }

    swap(array[i + 1], array[r]);
    return i + 1;
}

template void sort(std::vector<Edge> &array,  int l, int r);
template void sort(std::vector<int> &array,  int l, int r);