#include "Folder.hpp"
#include <array>

int main()
{
    int *icon1 = new int[256];
    int *icon2 = new int[256];

    File new_file = File(".env", "hi", icon1);
    std::cout << new_file.getName() << "\n";
    File example = File(".");
    std::cout << example.getName() << "\n";
    File mydoc = File("mydoc.pdf", "Document content", icon2);
    std::cout << mydoc.getName() << "\n";
    std::cout << mydoc.getContents() << "\n";
    std::cout << mydoc.getIcon() << "\n\n\n";
    // File errordoc = File("mydoc@.pdf");
    // std::cout << errordoc.getName();

    // example.operator=(std::move(mydoc));
    File example1 = File(std::move(mydoc));
    std::cout << example1.getName() << "\n";
    std::cout << example1.getContents() << "\n";
    std::cout << example1.getIcon() << "\n";
    // std::cout << mydoc.getName() << "\n";
    // std::cout << mydoc.getContents() << "\n";
    // std::cout << mydoc.getIcon() << "\n";

    Folder folder1 = Folder("folderOne");
    folder1.addFile(example1);
    folder1.display();

    Folder folder2 = Folder("folderTwo");
    folder2.addFile(new_file);

    // folder1.copyFileTo("mydoc.pdf", folder2);
    folder2.display();
    folder1.display();

    std::cout << "\n\n";
    folder2.moveFileTo("NewFile.txt", folder1);
    folder2.display();
    folder1.display();

    return 0;
}