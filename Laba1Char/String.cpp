#include "String.h"

MyString::MyString() : str(new char[1]), size(0) {
    this->str[0] = '\0';
}

bool MyString::IsNullOrEmpty(const char* input) {
    return input == nullptr || input[0] == '\0';
}

const char* MyString::GetStr() const {
    return this->str;
}

void MyString::SetStr(const char* newStr) {
    delete[] this->str;
    if (IsNullOrEmpty(newStr)) {
        this->str = new char[1];
        this->str[0] = '\0';
        this->size = 0;
    }
    else {
        this->size = std::strlen(newStr);
        this->str = new char[this->size + 1];
        std::strcpy(this->str, newStr);
    }
}

MyString MyString::ReadUserString(const std::string& prompt) {
    std::cout << prompt;
    std::string buffer;
    std::getline(std::cin, buffer);
    return MyString(buffer.c_str());
}

MyString::~MyString() {
    delete[] this->str;
}

bool MyString::IsEmpty() const {
    return this->size == 0 || this->str[0] == '\0';
}

MyString::MyString(const MyString& other) {
    this->size = other.size;
    this->str = new char[this->size + 1];
    std::strcpy(this->str, other.str);
}

MyString::MyString(const char* str) {
    this->str = nullptr;
    this->size = 0;
    this->SetStr(str); 
}

MyString& MyString::operator=(const MyString& other) {
    if (this != &other) {
        delete[] this->str;
        this->size = other.size;
        this->str = new char[this->size + 1];
        std::strcpy(this->str, other.str);
    }
    return *this;
}

MyString::MyString(MyString&& other) noexcept {
    this->str = other.str;
    this->size = other.size;
    other.str = new char[1];
    other.str[0] = '\0';
    other.size = 0;
}

MyString MyString::operator+(const MyString& other) {
    MyString result;
    result.size = this->GetSize() + other.GetSize();
    result.str = new char[result.size + 1];
    std::strcpy(result.str, this->str);
    std::strcat(result.str, other.str);
    return result;
}

bool MyString::operator==(const MyString& other) const {
    return std::strcmp(this->str, other.str) == 0;
}

bool MyString::operator!=(const MyString& other) const {
    return !(*this == other);
}

bool MyString::operator<(const MyString& other) const {
    return std::strcmp(this->str, other.str) < 0;
}

bool MyString::operator>(const MyString& other) const {
    return std::strcmp(this->str, other.str) > 0;
}

bool MyString::operator<=(const MyString& other) const {
    return !(*this > other);
}

bool MyString::operator>=(const MyString& other) const {
    return !(*this < other);
}

const char& MyString::operator[](size_t index) const {
    if (index >= this->GetSize()) {
        throw std::logic_error("Index out of range in MyString::operator[]");
    }
    return this->str[index];
}

std::ostream& operator<<(std::ostream& out, const MyString& s) {
    out << s.str;
    return out;
}

size_t MyString::GetSize() const {
    return this->size;
}

void MyString::Clear() {
    delete[] this->str;
    this->str = new char[1];
    this->str[0] = '\0';
    this->size = 0;
}

size_t MyString::Find(char ch) const {
    if (this->IsEmpty()) {
        return std::string::npos;
    }
    for (size_t i = 0; i < this->GetSize(); ++i) {
        if (this->str[i] == ch) {
            return i;
        }
    }
    return std::string::npos;
}

void MyString::Reverse() {
    if (this->IsEmpty()) {
        return;
    }
    for (size_t i = 0; i < this->GetSize() / 2; ++i) {
        std::swap(this->str[i], this->str[this->GetSize() - i - 1]);
    }
}

int32_t MyString::Compare(const MyString& other) const {
    if (this->IsEmpty() && other.IsEmpty()) {
        return 0;
    }
    if (this->IsEmpty()) {
        return -1;
    }
    if (other.IsEmpty()) {
        return 1;
    }
    return std::strcmp(this->str, other.str);
}

void MyString::Insert(size_t pos, const MyString& other) {
    if (other.IsEmpty()) {
        return;
    }
    if (pos > this->GetSize()) {
        throw std::logic_error("Insert position out of range");
    }
    char* newStr = new char[this->GetSize() + other.GetSize() + 1];
    std::strncpy(newStr, this->str, pos);
    std::strcpy(newStr + pos, other.str);
    std::strcpy(newStr + pos + other.GetSize(), this->str + pos);
    delete[] this->str;
    this->str = newStr;
    this->size = this->GetSize() + other.GetSize();
}

void MyString::Replace(char oldChar, char newChar) {
    if (this->IsEmpty()) {
        return;
    }
    for (size_t i = 0; i < this->GetSize(); ++i) {
        if (this->str[i] == oldChar) {
            this->str[i] = newChar;
        }
    }
}

size_t MyString::Find(const MyString& substr) const {
    if (this->IsEmpty() || substr.IsEmpty()) {
        return std::string::npos;
    }
    const char* pos = std::strstr(this->str, substr.str);
    if (pos) {
        return static_cast<size_t>(pos - this->str);
    }
    else {
        return std::string::npos;
    }
}

size_t MyString::CountDigits() const {
    if (this->IsEmpty()) {
        return 0;
    }
    size_t count = 0;
    for (size_t i = 0; i < this->GetSize(); ++i) {
        if (std::isdigit(this->str[i])) {
            ++count;
        }
    }
    return count;
}

bool MyString::IsAllDigits() const {
    if (this->IsEmpty()) {
        return false;
    }
    for (size_t i = 0; i < this->GetSize(); ++i) {
        if (!std::isdigit(this->str[i])) {
            return false;
        }
    }
    return true;
}

int64_t MyString::ToInt() const {
    if (this->IsEmpty()) {
        throw std::invalid_argument("Cannot convert empty string to integer");
    }
    return std::stoll(this->str);
}

size_t MyString::Count(char ch) const {
    if (this->IsEmpty()) {
        return 0;
    }
    size_t counter = 0;
    for (size_t i = 0; i < this->GetSize(); ++i) {
        if (this->str[i] == ch) {
            ++counter;
        }
    }
    return counter;
}
