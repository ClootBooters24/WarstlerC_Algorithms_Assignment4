#include <sort.hpp>
#include <graph.hpp> 

//extern
std::string sortAlgName = "Merge Sort";

template<class T>
void sort(std::vector<T> &array, int l, int r) {
    // YOUR CODE HERE
    // Sorray array from l to r, i.e. sort array[l...r]
    
    if(l < r) {
        int m = l + (r - l) / 2;

        sort(array, l, m);
        sort(array, m + 1, r);

        merge(array, l, m, r);
    }
}

template<class T>
void merge(std::vector<T> &array, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    std::vector<T> L(n1);
    std::vector<T> R(n2);

    for(int i = 0; i < n1; ++i)
        L[i] = array[l + i];

    for(int j = 0; j < n2; ++j)
        R[j] = array[m + 1 + j];

    int i = 0;
    int j = 0;
    int k = l;

    while(i < n1 && j < n2) {
        if(L[i] <= R[j]) {
            array[k] = L[i];
            ++i;
        }
        else {
            array[k] = R[j];
            ++j;
        }
        ++k;
    }

    while(i < n1) {
        array[k] = L[i];
        ++i;
        ++k;
    }
}

template void sort(std::vector<Edge> &array,  int l, int r);
template void sort(std::vector<int> &array,  int l, int r);