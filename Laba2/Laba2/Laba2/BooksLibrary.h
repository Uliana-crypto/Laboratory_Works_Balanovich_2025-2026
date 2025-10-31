#ifndef BOOKSLIBRARY_H
#define BOOKSLIBRARY_H

#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include "BookStruct.h"

class BookList {
private:
	struct BookNode {
		Book info;
		BookNode* next;

		BookNode(const Book& b, BookNode* n = nullptr) : info(b), next(n) {}
	};
	BookNode* first;
public:
	bool IsEmpty() const;
	void CheckInputFile(std::ifstream& fin);
	void CheckOutputFile(std::ofstream& fout);

	BookList();
	~BookList();
	BookList(const BookList& other);
	BookList(BookList&& other) noexcept;
	BookList& operator=(const BookList& other);
	BookList& operator=(BookList&& other) noexcept;

	void Erase();
	void ShowBooks() const;
	void AddBook(const Book& book);
	BookNode* FindByUDK(size_t UDK) const;
	void ReturnBook(size_t UDK);
	void IssueBook(size_t UDK);
	void PrintBook(const Book& b)const;
	void Clone(const BookList& other);

	void AddBookFromConsoleAndSave(const std::string& filename);
	void ReadAndDisplayFromFile(const std::string& filename);
};
#endif
