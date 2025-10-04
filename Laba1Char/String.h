#define _CRT_SECURE_NO_WARNINGS
#ifndef STRING_N
#define STRING_N

#include <iostream>
#include <string>

class MyString {
private:
    char* str;
    size_t size;
    static bool IsNullOrEmpty(const char* input);
public:
    MyString();
    MyString(const char* str);
    MyString(const MyString& other);
    MyString(MyString&& other) noexcept;
    ~MyString();

    const char* GetStr() const;
    void SetStr(const char* newStr);

    MyString& operator=(const MyString& other);

    MyString operator+(const MyString& other);
    bool operator==(const MyString& other) const;
    bool operator!=(const MyString& other) const;
    bool operator<(const MyString& other) const;
    bool operator>(const MyString& other) const;
    bool operator<=(const MyString& other) const;
    bool operator>=(const MyString& other) const;
    const char& operator[](size_t index) const;

    friend std::ostream& operator<<(std::ostream& out, const MyString& s);

    bool IsEmpty() const;
    size_t GetSize() const;
    void Clear();
    size_t Count(char ch) const;
    size_t Find(char ch) const;
    void Reverse();
    int32_t Compare(const MyString& other) const;
    void Insert(size_t pos, const MyString& other);
    void Replace(char oldChar, char newChar);
    bool IsAllDigits() const;
    int64_t ToInt() const;
    size_t CountDigits() const;
    size_t Find(const MyString& substr) const;
    static MyString ReadUserString(const std::string& prompt);
};
#endif