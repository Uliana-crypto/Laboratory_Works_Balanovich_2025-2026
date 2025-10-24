#include "BooksLibrary.h"

BookList::BookList() : first(nullptr) {}

BookList::~BookList() {
    Erase();
}

BookList::BookList(const BookList& other) {
    Clone(other);
}

bool BookList::IsEmpty() const {
    return first == nullptr;
}

BookList::BookNode* BookList::FindByUDK(size_t UDK) const {
    BookNode* cur = first;
    while (cur) {
        if (cur->info.UDK == UDK) return cur;
        cur = cur->next;
    }
    return nullptr;
}

void BookList::AddBook(const Book& book) {
    if (book.UDK <= 0) {
        throw std::invalid_argument("��� ������ ���� ������������� ������");
    }
    if (book.Count < 0) {
        throw std::invalid_argument("���������� ����������� �� ����� ���� �������������");
    }
    if (book.Year <= 0) {
        throw std::invalid_argument("��� ������� ������ ���� �������������");
    }
    if (book.Author.empty() || book.Title.empty()) {
        throw std::invalid_argument("����� � �������� ����� �� ������ ���� �������");
    }
    if (!std::isupper(static_cast<unsigned char>(book.Author[0]))) {
        throw std::invalid_argument("��� ������ ������ ���������� � ��������� �����");
    }
    for (char ch : book.Author) {
        if (isdigit(ch)) {
            throw std::invalid_argument("��� ������ �� ������ ��������� �����");
        }
    }
    if (FindByUDK(book.UDK)) {
        throw std::runtime_error("����� � ����� ��� ��� ����������");
    }

    first = new BookNode(book, first);
}

void BookList::IssueBook(size_t UDK) {
    BookNode* node = FindByUDK(UDK);
    if (!node) {
        throw std::runtime_error("����� �� �������");
    }
    if (node->info.Count == 0) {
        throw std::runtime_error("��� ��������� �����������");
    }

    node->info.Count--;
    std::cout << "����� ������: " << node->info.Title << ". ��������: " << node->info.Count << "\n";
}

void BookList::ReturnBook(size_t UDK) {
    BookNode* node = FindByUDK(UDK);
    if (!node) {
        throw std::runtime_error("����� �� �������");
    }
    node->info.Count++;
    std::cout << "����� ����������: " << node->info.Title << ". ������ ��������: " << node->info.Count << "\n";
}

void BookList::ShowBooks() const {
    if (IsEmpty()) {
        std::cout << "���������� �����\n";
        return;
    }
    BookNode* current = first;
    std::cout << "������ ���� � ����������:\n";
    while (current) {
        this->PrintBook(current->info);
        current = current->next;
    }
}

void BookList::Erase() {
    BookNode* current = first;
    BookNode* nextNode;
    while (current != nullptr) {
        nextNode = current->next;
        delete current;
        current = nextNode;
    }
    first = nullptr;
}

void BookList::Clone(const BookList& other) {
    Erase();
    BookNode* source = other.first;
    BookNode* copy = nullptr;
    BookNode* tail = nullptr;
    while (source) {
        copy = new BookNode(source->info);
        if (!tail) {
            first = copy;
        }
        else {
            tail->next = copy;
        }
        tail = copy;
        source = source->next;
    }
}

BookList::BookList(BookList&& other) noexcept : first(other.first) {
    other.first = nullptr;
}

BookList& BookList::operator=(BookList&& other) noexcept {
    if (this != &other) {
        Erase();
        first = other.first;
        other.first = nullptr;
    }
    return *this;
}

BookList& BookList::operator=(const BookList& other) {
    if (this != &other) {
        Clone(other);
    }
    return *this;
}

void BookList::PrintBook(const Book& b) const {
    std::cout << "���: " << b.UDK
        << "  �����: " << b.Author
        << "  ��������: " << b.Title
        << "  ���: " << b.Year
        << "  ���-��: " << b.Count << "\n";
}

void BookList::CheckInputFile(std::ifstream& fin) {
    if (!fin.good()) {
        throw std::runtime_error("���� �� ���������� ��� ���������� ��� ������");
    }
    if (!fin) {
        throw std::runtime_error("������ �������� �������� �����");
    }
    if (fin.peek() == EOF) {
        throw std::runtime_error("���� ����");
    }
}

void BookList::CheckOutputFile(std::ofstream& fout) {
    if (!fout.good()) {
        throw std::runtime_error("���� �� ���������� ��� ���������� ��� ������");
    }
    if (!fout) {
        throw std::runtime_error("������ �������� ��������� �����");
    }
}

void BookList::AddBookFromConsoleAndSave(const std::string& filename) {
    Book b;
    std::cout << "������� ���: ";
    std::cin >> b.UDK;
    std::cin.ignore();

    std::cout << "������� ������: ";
    std::getline(std::cin, b.Author);

    std::cout << "������� ��������: ";
    std::getline(std::cin, b.Title);

    std::cout << "������� ��� �������: ";
    std::cin >> b.Year;

    std::cout << "������� ���������� �����������: ";
    std::cin >> b.Count;

    AddBook(b);

    std::ofstream fout(filename, std::ios::app);
    CheckOutputFile(fout);

    fout << b.UDK << "\n"
        << b.Author << "\n"
        << b.Title << "\n"
        << b.Year << "\n"
        << b.Count << "\n";

    fout.close();
}

void BookList::ReadAndDisplayFromFile(const std::string& filename) {
    std::ifstream fin(filename);
    CheckInputFile(fin);
    Book b;
    std::cout << "���������� �����:\n";
    while (fin >> b.UDK) {
        fin.ignore();
        std::getline(fin, b.Author);
        std::getline(fin, b.Title);
        fin >> b.Year >> b.Count;
        fin.ignore();

        PrintBook(b);
    }
    fin.close();
}
