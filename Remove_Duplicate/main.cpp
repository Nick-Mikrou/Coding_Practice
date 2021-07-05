#include <iostream>

template <typename T>
T* RemoveDuplicate(T Array[], const size_t N);

int main()
{
	const int N = 15;
	const int D = N - 3;

	size_t Array[N] = { 1,2,2,3,4,5,6,7,8,9,11,12,12,15,15 };	

	size_t* RD = RemoveDuplicate(Array, N);

	for (int i = 0; i < D; ++i)
		std::cout << "RD[" << i << "] : " << RD[i] << std::endl;

	return 0;
}

template <typename T>
T* RemoveDuplicate(T Array[], const size_t N)
{
	size_t CurrentPosition, NewPosition = 1;

	for (CurrentPosition = 1; CurrentPosition <= N; ++CurrentPosition)
	{
		if (CurrentPosition != NewPosition) Array[NewPosition] = Array[CurrentPosition];
		if (Array[CurrentPosition] != Array[CurrentPosition + 1]) NewPosition++;
	}

	return Array;
}