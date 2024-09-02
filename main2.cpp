#include <iostream>
#include <string>
#ifdef _WIN32
#include <windows.h>
#else
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#endif



#ifdef _WIN32
void listFiles(const std::string& pattern) {
    WIN32_FIND_DATA findFileData;
    HANDLE hFind = FindFirstFile(pattern.c_str(), &findFileData);

    if (hFind == INVALID_HANDLE_VALUE) {
        std::cout << "No files found." << std::endl;
        return;
    }

    do {
        if (!(findFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
            std::cout << findFileData.cFileName << std::endl;
        }
    } while (FindNextFile(hFind, &findFileData) != 0);

    FindClose(hFind);
}

void createDirectory() {
    std::string dirname;
    std::cout << "Enter the name of the directory: ";
    std::cin >> dirname;

    if (CreateDirectory(dirname.c_str(), NULL) || GetLastError() == ERROR_ALREADY_EXISTS) {
        std::cout << "Directory created successfully or already exists." << std::endl;
    } else {
        std::cout << "Error creating directory." << std::endl;
    }
}

void changeDirectory() {
    int choice;
    std::cout << "1. Move one step back (to parent directory)" << std::endl;
    std::cout << "2. Move to the root directory" << std::endl;
    std::cout << "3. Move to a specific directory" << std::endl;
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    switch (choice) {
        case 1:
            SetCurrentDirectory("..");
            break;
        case 2:
            SetCurrentDirectory("C:\\");
            break;
        case 3:
            {
                std::string dir;
                std::cout << "Enter the path to the directory: ";
                std::cin >> dir;
                if (!SetCurrentDirectory(dir.c_str())) {
                    std::cout << "Error changing directory." << std::endl;
                }
            }
            break;
        default:
            std::cout << "Invalid choice." << std::endl;
            break;
    }
}
#else
void listFiles(const std::string& pattern) {
    DIR *dir;
    struct dirent *entry;

    dir = opendir(".");
    if (dir == NULL) {
        std::cerr << "Could not open directory." << std::endl;
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) { // Regular file
            std::cout << entry->d_name << std::endl;
        }
    }

    closedir(dir);
}

void createDirectory() {
    std::string dirname;
    std::cout << "Enter the name of the directory: ";
    std::cin >> dirname;

    if (mkdir(dirname.c_str(), 0755) == 0 || errno == EEXIST) {
        std::cout << "Directory created successfully or already exists." << std::endl;
    } else {
        std::cout << "Error creating directory." << std::endl;
    }
}
int main() {
    int choice;

 {
        std::cout << "\nDirectory Management System\n";
        std::cout << "1. List Files\n";
        std::cout << "2. Create Directory\n";
        std::cout << "3. Change Directory\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

if (list_choice == 1) {
                } else if (list_choice == 2) {
                    std::string extension;
                    std::cout << "Enter file extension : ";
                    std::cin >> extension;                  
                } else if (list_choice == 3) {
                    std::string pattern;
                    std::cout << "Enter file pattern : ";
                    std::cin >> pattern;                  
                } else {
                    std::cout << "Invalid choice.\n";
                }
                break;
}
 case 2: {
                std::string dir_name;
                std::cout << "Enter directory name: ";
                std::cin >> dir_name;               
                break;
            }       
            case 3:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
       
