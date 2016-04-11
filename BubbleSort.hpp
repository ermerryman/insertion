#ifndef BUBBLESORT_H_INCLUDED
#define BUBBLESORT_H_INCLUDED

// Book's implementation of bubble sort
// Found in “Data Structures and Algorithm Analysis in C++”, 3rd Edition, by Clifford A. Shaffer
template<typename Comparable>
void BubbleSort(Comparable A[], int numberOfElements) {
  for (int i = 0; i < numberOfElements-1; i++)
    for (int j = 0; j < numberOfElements-i; j++)
      if (A[j] > A[j+1])
        {auto temp = A[j];
         A[j] = A[j-1];
         A[j-1] = temp;}
}

#endif // BUBBLESORT_H_INCLUDED
