#include <sort.hpp>
#include <graph.hpp> 

//extern
std::string sortAlgName = "Heap Sort";

template<class T>
void sort(std::vector<T> &array, int l, int r) {
    // YOUR CODE HERE
    // Sorray array from l to r, i.e. sort array[l...r]
    int n = r - l + 1;

    for(int i = n / 2 - 1; i >= 0; --i)
        heapify(array, r, i);

    for(int i = n - 1; i >= 0; --i) {
        swap(array[0], array[i]);
        heapify(array, i, 0);
    }
}

template<class T>
void heapify(std::vector<T> &array, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < n && array[left] > array[largest])
        largest = left;

    if(right < n && array[right] > array[largest])
        largest = right;

    if(largest != i) {
        swap(array[i], array[largest]);
        heapify(array, n, largest);
    }
}

template<class T>
void swap(T &a, T &b) {
    T tmp = a;
    a = b;
    b = tmp;
}


template void sort(std::vector<Edge> &array,  int l, int r);
template void sort(std::vector<int> &array,  int l, int r);
