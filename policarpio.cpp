#include <iostream>
#include <string>


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

        switch (choice) {
            case 1:
                int list_choice;
                std::cout << "\n1. List all files\n";
                std::cout << "2. List files by extension\n";
                std::cout << "3. List files by pattern\n";
                std::cout << "Enter your choice: ";
                std::cin >> list_choice;

 if (list_choice == 1) {
                } else if (list_choice == 2) {
                    std::string extension;
                    std::cout << "Enter file extension (e.g., .txt): ";
                    std::cin >> extension;                  
                } else if (list_choice == 3) {
                    std::string pattern;
                    std::cout << "Enter file pattern (e.g., moha*.*): ";
                    std::cin >> pattern;                  
                } else {
                    std::cout << "Invalid choice.\n";
                }
                break;
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
}

       
