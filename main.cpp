#include <string>
#include <iostream>
#include <type_traits>

class Arduasm {
private:
    // Function that splits number (ex. splitNumber(2137, a, b) -> a = 2, b = 137)
    void splitNumber(int number, int& firstPart, int& secondPart) {
        std::string numberString = std::to_string(number);
        firstPart = numberString[0] - '0';
        secondPart = std::stoi(numberString.substr(1));
    }

    template<typename T>
    int getTypeCode() {
        if (std::is_same<T, int>::value) {
            return 0;
        } else if (std::is_same<T, std::string>::value) {
            return 1;
        } else if (std::is_same<T, bool>::value) {
            return 2;
        } else if (std::is_same<T, float>::value) {
            return 3;
        } else if (std::is_same<T, double>::value) {
            return 4;
        } else if (std::is_same<T, char>::value) {
            return 5;
        } else {
            return -1; // Unknown type
        }
    }

    int* ints;
    std::string* strings;
    bool* bools;

public:
    Arduasm(int allocint, int allocstring, int allocbool) {
        ints = new int[allocint];
        strings = new std::string[allocstring];
        bools = new bool[allocbool];
    }

    ~Arduasm() {
        delete[] ints;
        delete[] strings;
        delete[] bools;
    }

    // Write data to specified address
    template<typename T>
    void write_data(int addr, T data) {
        int first, rest;
        splitNumber(addr, first, rest);
        switch (first) {
            case 0:
                ints[rest] = data;
                break;
            case 1:
                strings[rest] = data;
                break;
            case 2:
                bools[rest] = data;
                break;
            default:
                break;
        }
    }

    // Read data from specified address
    template<typename T>
    void read_data(int addr, T& variable) {
        int first, rest;
        splitNumber(addr, first, rest);
        switch (first) {
            case 0:
                if (getTypeCode<T>() == 0) variable = ints[rest];
                break;
            case 1:
                if (getTypeCode<T>() == 1) variable = strings[rest];
                break;
            case 2:
                if (getTypeCode<T>() == 2) variable = bools[rest];
                break;
            default:
                break;
        }
    }

    // Specialized template function for reading data of type std::string
    void read_data(int addr, std::string& variable) {
        int first, rest;
        splitNumber(addr, first, rest);
        if (first == 1) {
            variable = strings[rest];
        }
    }
};

int main() {
    Arduasm aasm(10, 10, 10); // Adjust sizes as needed

    int dataToWrite = 2137;
    int dataRead;

    aasm.write_data(01, dataToWrite);
    aasm.read_data(01, dataRead);

    std::cout << dataRead << std::endl; // Should print 2137

    return 0;
}
