#include "header.h"

void enterSize(int32_t& size)
{
	std::cout << "Введите размер массива\n";
	std::cin >> size;
	if (std::cin.fail() || size <= 0)
	{
		throw std::runtime_error("Ошибка ввода! Введите положительное целое число\n");
	}
}

void enterArray(int32_t* arr, int32_t& size)
{
	std::cout << "Введите элементы массива\n";
	for (size_t i = 0; i < size; ++i)
	{
		std::cin >> arr[i];
	}
}

void printArray(int32_t* arr, int32_t size)
{
	std::cout << "Вывод элементов массива\n";
	for (size_t i = 0; i < size; ++i)
	{
		std::cout << arr[i] << '\n';
	}
	std::cout << '\n';
}

void getDirection(char& direction)
{
	std::cout << "Введите +, если хотите ,чтобы сортировка была по возрастанию,и -, если наоборот\n";
	std::cin >> direction;
}

void bubleSort(int32_t* arr, int32_t size, char direction)
{

	for (size_t i = 0; i < size - 1; ++i)
	{
		bool swapped = false;
		for (size_t j = 0; j < size - i - 1; ++j)
		{
			if ((direction == '+' && arr[j] > arr[j + 1]) || (direction == '-' && arr[j] < arr[j + 1]))
			{
				std::swap(arr[j], arr[j+1]);
				swapped = true;
			}
		}
		if (!swapped)
		{
			break;
		}
	}
}

void insertionSort(int32_t* arr, int32_t size, char direction)
{
	for (size_t i = 1; i < size; ++i)
	{
		int32_t key = arr[i];
		int32_t j = i - 1;
			while ((direction == '+' && (j >= 0 && arr[j] > key)) || (direction == '-' && (j >= 0 && arr[j] < key)))
			{
				arr[j + 1] = arr[j];
				--j;
			}
			arr[j + 1] = key;
	}
}

void quickSort(int32_t* arr, int32_t left, int32_t right, char direction)
{
	int32_t i = left;
	int32_t j = right;

	int32_t pivot = arr[(left + right) / 2];

	while (i <= j)
	{
		while ((direction == '+' && arr[i] < pivot) || (direction =='-' && arr[i] > pivot))
		{
			i++;
		}
		while ((direction == '+' && arr[j] > pivot) || (direction == '-'&& arr[j] < pivot))
		{
			j--;
		}
		if (i <= j)
		{
			std::swap(arr[i], arr[j]);
			i++;
			j--;
		}
	}
	if (left < j)
	{
		quickSort(arr, left, j, direction);
	}
	if (i < right)
	{
		quickSort(arr, i, right, direction);
	}
}

void selectionSort(int32_t* arr, int32_t size, char direction)
{
	for (size_t i = 0; i < size - 1; ++i)
	{
		int32_t minIndex = i;
		for (size_t j = i + 1; j < size; ++j)
		{
			if ((direction == '+' && arr[j] < arr[minIndex]) || (direction == '-' && arr[j] > arr[minIndex]))
			{
				minIndex = j;
			}
		}
		std::swap(arr[i], arr[minIndex]);
		
	}
}

void mergeSort(int32_t* arr, int32_t left, int32_t right, char direction)
{
	if (left < right)
	{
		int32_t mid = left + (right - left) / 2;
		mergeSort(arr, left, mid, direction);
		mergeSort(arr, mid + 1, right, direction);
		merge(arr, left, mid, right, direction);
	}
}

void merge(int32_t* arr, int32_t left, int32_t mid, int32_t right, char direction)
{
	int32_t size1 = mid - left + 1;
	int32_t size2 = right - mid;

	int32_t* L = new int32_t [size1];
	int32_t* R = new int32_t[size2];

	for (size_t i = 0; i < size1; ++i)
	{
		L[i] = arr[left + i];
	}
	for(size_t j=0; j < size2; ++j)
	{
		R[j] = arr[mid + j + 1];
	}

	int32_t i = 0;
	int32_t j = 0;
	int32_t k = left;

	while (i < size1 && j < size2)
	{
		if ((direction == '+' && L[i] <= R[j]) || (direction == '-' && L[i] > R[j]))
		{
			arr[k++] = L[i++];
		}
		else
		{
			arr[k++] = R[j++];
		}
	}

	while(i < size1)
	{
		arr[k++] = L[i++];
	}
	while (j < size2)
	{
		arr[k++] = R[j++];
	}

	delete[] L;
	delete[] R;
}

void heapSort(int32_t* arr, int32_t size, char direction)
{
	for (int32_t i = size / 2 - 1; i >= 0; --i)
	{
		heapify(arr, size, i, direction);
	}

	for (int32_t i = size - 1; i > 0; --i)
	{
		std::swap(arr[0], arr[i]);
		heapify(arr, i, 0, direction);
	}
}

void heapify(int32_t* arr, int32_t size, int32_t i, char direction)
{
	int32_t largest = i;
	int32_t left = 2 * i + 1;
	int32_t right = 2 * i + 2;

	if (left < size && arr[left] > arr[largest])
		largest = left;

	if (right < size && arr[right] > arr[largest])
		largest = right;

	if (largest != i) {
		std::swap(arr[i], arr[largest]);
		heapify(arr, size, largest, direction);
	}
}

void combSort(int32_t* arr, int32_t size, char direction)
{
	int32_t gap = size;
	const double shrink = 1.3;
	bool swapped = true;

	while (gap > 1 || swapped)
	{
		gap = int32_t(floor(gap / shrink));
		if (gap < 1)
		{
			gap = 1;
		}
		swapped = false;
		for (int32_t i = 0; i + gap < size; ++i)
		{
			if ((direction == '+' && arr[i] > arr[i + gap]) || (direction == '-' && arr[i] < arr[i + gap]))
			{
				std::swap(arr[i], arr[i + gap]);
				swapped = true;
			}
		}
	}
}

void shellSort(int32_t* arr, int32_t size, char direction)
{
	for (int32_t gap = size / 2; gap > 0; gap /= 2)
	{
		for (int32_t i = gap; i < size; ++i) 
		{
			int32_t temp = arr[i];
			int32_t j = i;

			while ((direction == '+' && j >= gap && arr[j - gap] > temp) || (direction == '-' && j >= gap && arr[j - gap] < temp))
			{
				arr[j] = arr[j - gap];
				j -= gap;
			}

			arr[j] = temp;
		}
	}
}
