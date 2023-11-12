#include <iostream>
#include <string>
#include <vector> 

extern std::string sortAlgName;

template<class T>
void sort(std::vector<T> &array, int l, int r);

template<class T>
void swap(T &a, T &b);

template<class T>
int partition(std::vector<T> &array, int l, int r);

template<class T>
void merge(std::vector<T> &array, int l, int m, int r);

template<class T>
void heapify(std::vector<T> &array, int n, int i);