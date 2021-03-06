#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>

#include "InsertionSort.h"
#include "BubbleSort.h"

//For research use to calculate run times
#include "Complexity_Recorder.hpp"
#include "Complexity_Timer.hpp"

int main(int argc, char* argv[])
{
    int numberOfElements = 100;

    const int number_of_algorithms = 3;

    std::vector<recorder<timer>> stats(number_of_algorithms);

	for(int i=0;i<number_of_algorithms;i++) stats[i].reset();

    //timer
	timer timer1;
	timer timer2;
	timer timer3;

	//Get the number of elements to be tested
	if(argc==1)
	{
		cout << "Error: Not enough arguments, please use: " << argv[0] << " <# of elements>\n";
		return 0;
	}
	else if(argc>2)
	{
		cout << "Error: Too many arguments, please use: " << argv[0] << " <# of elements>\n";
	}
	else
	{
		numberOfElements = atoi(argv[1]);
	}

    int Array[numberOfElements];

    for(int i=0; i < numberOfElements; i++)
    {
        Array[i] = rand() % 100000;
    }

    timer1.restart();

    InsertionSort(Array,numberOfElements);

	timer1.stop();

	stats[0].record(timer1);

    std::cout<<"Our insertion sort: ";
	stats[0].report(cout,numberOfElements);
	std::cout<<std::endl;

    for(int i=0; i < numberOfElements; i++)
    {
        Array[i] = rand() % 100000;
    }

    timer2.restart();

    std::sort(Array, Array + numberOfElements);

	timer2.stop();

	stats[1].record(timer2);

    std::cout<<"STL's std::sort(): ";
	stats[1].report(cout,numberOfElements);
	std::cout<<std::endl;

    for(int i=0; i < numberOfElements; i++)
    {
        Array[i] = rand() % 100000;
    }

    timer3.restart();

    BubbleSort(Array,numberOfElements);

	timer3.stop();

	stats[2].record(timer3);

    std::cout<<"Book's BubbleSort(): ";
	stats[2].report(cout,numberOfElements);
	std::cout<<std::endl;

    return 0;
}
