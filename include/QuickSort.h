/* Copyright 2016 Almudena García Jurado-Centurión, pepstein
    This file is part of Practica2_AMC, based in pepstein work (http://www.cplusplus.com/forum/beginner/119660/)

    Practica2_AMC is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Practica2_AMC is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Practica2_AMC.  If not, see <http://www.gnu.org/licenses/>.
*/


#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <algorithm>    // std::swap
#include <vector>
#include <utility>

using namespace std;

class QuickSort
{
    public:
        void quickSort(vector<pair<float, float> >, int, int);

        int partition(vector<pair<float, float> >, int, int);

};

#endif // QUICKSORT_H
