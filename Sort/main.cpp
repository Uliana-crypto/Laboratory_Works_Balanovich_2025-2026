#include "header.h"

int main()
{
	int32_t size{};
	try
	{
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		setlocale(LC_ALL, "Russion");
		int32_t choice{};
		enterSize(size);
		int32_t* arr = new int32_t[size];
		enterArray(arr, size);
		char direction{};

		do
		{
			getDirection(direction);
			std::cout << "\nМеню:\n";
			std::cout << "1. Пузырьковая сортировка\n";
			std::cout << "2. Сортировка вставками\n";
			std::cout << "3. Быстрая сортировка\n";
			std::cout << "4. Сортировка выбором\n";
			std::cout << "5. Сортировка слиянием\n";
			std::cout << "6. HeapSort\n";
			std::cout << "7. Сортировка расчёской\n";
			std::cout << "8. Сортировка Шелла\n";
			std::cout << "9. Выход\n";
			std::cout << "Выберите действие: ";
			std::cin >> choice;
			switch (choice)
			{
			case 1: {
				bubleSort(arr, size, direction);
				printArray(arr, size);
				break;
			}
			case 2: {
				insertionSort(arr, size, direction);
				printArray(arr, size);
				break;
			}
			case 3: {
				quickSort(arr, 0, size - 1, direction);
				printArray(arr, size);
				break;
			}
			case 4: {
				selectionSort(arr, size, direction);
				printArray(arr, size);
				break;
			}
			case 5: {
				mergeSort(arr, 0, size - 1, direction);
				printArray(arr, size);
				break;
			}
			case 6: {
				heapSort(arr, size, direction);
				printArray(arr, size);
				break;
			}
			case 7: {
				combSort(arr, size, direction);
				printArray(arr, size);
				break;
			}
			case 8: {
				shellSort(arr, size, direction);
				printArray(arr, size);
				break;
			}
			case 9: {
				std::cout << "Выход из программы.\n";
				break;
			}
			default:
				std::cout << "Некорректный выбор.\n";
			}
		} while (choice != 9);



		delete[] arr;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() <<'\n';
		enterSize(size);
	}
}
