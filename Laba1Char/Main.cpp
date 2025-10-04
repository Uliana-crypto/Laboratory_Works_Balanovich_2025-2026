#include "String.h"

int main() {

    try {
        MyString input = MyString::ReadUserString("Enter a string: ");
        
        if (input.IsEmpty()) {
            std::cout << "The string is empty\n";
            return 0;
        }

        std::cout << "Enter a character to search for: ";
        char searchChar;
        std::cin >> searchChar;
        std::cin.ignore();
        size_t pos = input.Find(searchChar);
        if (pos == std::string::npos) {
            std::cout << "Character '" << searchChar << "' not found.\n";
        }
        else {
            std::cout << "Found at position: " << (pos + 1) << '\n';
        }

        try {
            std::cout << "First character: " << input[0] << '\n';
        }
        catch (const std::logic_error& e) {
            std::cerr << e.what() << '\n';
        }

        if (input.IsAllDigits()) {
            int64_t value = input.ToInt();
            size_t digitCount = input.CountDigits();

            std::cout << "The string consists of only a number" << std::endl;
            std::cout << "Number of digits: " << digitCount << std::endl;
        }
        MyString sub = MyString::ReadUserString("Enter a substring to search for: ");
        size_t subPos = input.Find(sub);
        if (subPos == std::string::npos) {
            std::cout << "Substring \"" << sub << "\" not found.\n";
        }
        else {
            std::cout << "Substring \"" << sub << "\" found at position: " << subPos << '\n';
        }
    
        std::cout << "Enter the character to replace: ";
        char oldChar;
        char newChar;
        std::cin >> oldChar >> newChar;
        std::cin.ignore();
        input.Replace(oldChar, newChar);
        std::cout << "After replacement: " << input << '\n';

        MyString other = MyString::ReadUserString("Enter a string to compare with: ");
        int32_t cmp = input.Compare(other);
        if (cmp == 0) {
            std::cout << "The strings are equal\n";
        }
        else if (cmp < 0) {
            std::cout << "The first string is lexicographically less than the second\n";
        }
        else {
            std::cout << "The first string is lexicographically greater than the second\n";
        }

        input.Reverse();
        std::cout << "After reversing: " << input << '\n';

        std::cout << "Enter a character to count: ";
        char countChar;
        std::cin >> countChar;
        std::cin.ignore();
        std::cout << "Occurrences of '" << countChar << "': " << input.Count(countChar) << '\n';
        MyString second = MyString::ReadUserString("Enter second string to concatenate: ");
        MyString combined = input + second;

        std::cout << "Concatenated result: " << combined << '\n';

        MyString insertStr = MyString::ReadUserString("Enter a string to insert: ");
        try {
            std::cout << "Enter the position to insert at: ";
            size_t insertPos;
            std::cin >> insertPos;
            std::cin.ignore();

            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                {
                    throw std::invalid_argument("Invalid position input. Must be a number");
                }
            }
            input.Insert(insertPos, insertStr);
            std::cout << "After insertion: " << input << '\n';
        }
        catch (const std::logic_error& e) {
            std::cout << e.what() << '\n';
        }
        input.Clear();
    }
    catch (const std::exception& e) {
        std::cout << e.what() << '\n';
    }

    return 0;
}
