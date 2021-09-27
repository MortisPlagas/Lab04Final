#pragma once
#include <vector>
using namespace std;
#ifndef HISTOGRAM_H_INCLUDED
#define HISTOGRAM_H_INCLUDED

struct Input {
    vector<double> numbers;
    size_t bin_count;
};
void find_minmax(vector<double> numbers, double& min, double& max);

vector<size_t> make_histogram(Input data);

void show_histogram_text(const vector<size_t>& bins);

#endif
