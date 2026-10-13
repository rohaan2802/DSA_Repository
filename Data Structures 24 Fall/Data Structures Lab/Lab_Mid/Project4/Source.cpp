#include <iostream>
#include <fstream> 
#include<windows.h>
#include <filesystem>
namespace fs = std::filesystem;


using namespace std;

void createDirectory(const char* dirName) {
    // Convert the character array to std::filesystem::path
    fs::path dirPath(dirName);

    // Create the directory if it doesn't exist
    if (!fs::exists(dirPath)) {
        fs::create_directory(dirPath);
        cout << "Directory created: " << dirName << endl;
    }
    else {
        cout << "Directory already exists: " << dirName << endl;
    }
}



void max_win_size()
{
    HWND console_window = GetConsoleWindow();
    ShowWindow(console_window, SW_MAXIMIZE);
}

void font(int fontSize)
{
    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(cfi);
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    GetCurrentConsoleFontEx(hConsole, FALSE, &cfi);

    wcscpy_s(cfi.FaceName, L"Consolas");
    cfi.dwFontSize.X = 0;
    cfi.dwFontSize.Y = fontSize;

    SetCurrentConsoleFontEx(hConsole, FALSE, &cfi);
}

int stringLength(const char* str) {   //function to calculate length of strinf 
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

void stringCopy(char* dest, const char* src) {  //function to copy one string into the other 
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

void showColumnHeaders(const char* file_name, int& count)
{
    ifstream file(file_name);
    char ch;
    bool flag = true;
    count = 0;
    int x = 0;
    cout << "\n\n\n\t\t=====================\t SELECT ONE OF THE FOLLOWING OPTIONS\t=======================\n\n\n";
    while (file.get(ch))
    {
        if (flag == true)
        {
            ++x;
            if (x < 10)
            {
                cout << "0" << x << ") ";
            }
            else
            {
                cout << x << ") ";
            }
            flag = false;
        }
        if (ch == '\n')
        {
            break;
        }
        if (ch == ',')
        {
            cout << endl;
            count++;
            flag = true;
        }
        else
        {
            cout << ch;
        }

    }
    count++;
    cout << "\n\n\n";

    file.close();
}


int getUserColumnChoice(int val)
{
    int choice;
    while (true)
    {
        cout << "\n\n\t\t\tENTER THE CHOICE BETWEEN 1 AND " << val << ": ";
        cin >> choice;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "\n\n\t\t\tINVALID INPUT. PLEASE ENTER A VALID INTEGER.\n";
            system("pause");
            system("cls");
            return choice;
        }

        if (choice >= 1 && choice <= val)
        {
            return choice;
        }
        else
        {
            cout << "\n\n\t\t\tINVALID INPUT. PLEASE ENTER A VALID INTEGER.\n";
            cout << "\t\t\t";
            system("pause");
            system("cls");
            return choice;
        }
    }
}

void splitString(const char* str, char**& outArray, int& size) { //split row into columns
    int len = stringLength(str);
    size = 0;
    for (int i = 0; i < len; ++i) {
        if (str[i] == ',') size++;
    }
    outArray = new char* [size + 1];
    int start = 0, index = 0;
    for (int i = 0; i <= len; ++i) {
        if (str[i] == ',' || str[i] == '\0') {
            int columnLength = i - start;
            outArray[index] = new char[i - start+1];
            for (int j = 0; j < i - start; ++j) {
                outArray[index][j] = str[start + j];
            }
            outArray[index][i - start] = '\0';
            start = i + 1;
            index++;
        }
    }
}

// Node structure for AVL Tree
struct Node {
    char* key; // Data of the selected column (key)
    Node* left;
    Node* right;
    Node* parent;
    int height;
    const char* fileName;

    Node(const char* data, const char* rowData) {
        key = new char[stringLength(data) + 1];
        stringCopy(key, data);
        left = right = parent = nullptr; // Initialize parent to nullptr
        height = 1;

        // Assuming dirName is defined somewhere as the directory name
        const char* dirName = "Original Name"; // Modify this if needed
        fileName = createNodeFile(dirName, key, rowData, nullptr, nullptr, nullptr);
    }




    // Destructor to free dynamically allocated memory
    ~Node() {
        delete[] key;
        if (fileName) {
            remove(fileName); // Clean up file if needed
        }
    }

    void stoi_funcion(char* file_name, int& i, int num)
    {
        char ch[10];
        int j = 0;
        while (num > 0)
        {
            ch[j++] = '0' + (num % 10);
            num /= 10;
        }
        while (j > 0)
        {
            file_name[i++] = ch[--j];
        }
    }


    const char* createNodeFile(const char* dirName, const char* values, const char* row,
        const Node* leftChild, const Node* rightChild, const Node* parentNode)
    {
        static int count_ = 1; // Counter for unique file names
        static char file_name[100] = { 0 }; // Buffer for the complete file path
        int i = 0;

        // Copy the directory name to the path
        while (dirName[i] != '\0') {
            file_name[i] = dirName[i];
            i++;
        }

        // Append a path separator
       file_name[i++] = '\\';

        // Append the 'values' string to the file name
        int j = 0;
        while (values[j] != '\0') {
            file_name[i++] = values[j++];
        }

        // Append an underscore and the counter
        file_name[i++] = '_';

        // Convert the counter to a string and append it
        int tempCount = count_;
        char countStr[10];
        int k = 0;
        while (tempCount > 0) {
            countStr[k++] = '0' + (tempCount % 10);
            tempCount /= 10;
        }
        // Reverse and append the counter string
        for (int m = k - 1; m >= 0; --m) {
            file_name[i++] = countStr[m];
        }

        // Append the file extension ".txt"
        file_name[i++] = '.';
        file_name[i++] = 't';
        file_name[i++] = 'x';
        file_name[i++] = 't';
        file_name[i] = '\0';

        // Create and write to the file
        ofstream file(file_name);
        if (file.is_open()) {
            file << "Row Data: " << row << "\n";
            file << "Left Child Key: " << (leftChild ? leftChild->key : "NULL") << "\n";
            file << "Right Child Key: " << (rightChild ? rightChild->key : "NULL") << "\n";
            file << "Parent Key: " << (parentNode ? parentNode->key : "NULL") << "\n";
            file.close();
        }

        count_++; // Increment the counter
        return file_name; // Return the file name as a constant pointer
    }

};

// AVL Tree class
class AVLTree {
public:
    Node* root;

    // Helper function to get the height of a node
    int height(Node* node) {
        return node ? node->height : 0;
    }

    // Function to update the node file with current data and child references
    void updateNodeFile(Node* node, const char* rowData) {
        if (!node) return; // Do nothing if the node is null

        // Open the file for writing
        ofstream file(node->fileName);
        if (file.is_open()) {
            // Write the row data
            file << "Row Data: " << rowData << "\n";

            // Write the left child key (if exists)
            if (node->left) {
                file << "Left Child Key: " << node->left->key << "\n";
            }
            else {
                file << "Left Child Key: NULL\n";
            }

            // Write the right child key (if exists)
            if (node->right) {
                file << "Right Child Key: " << node->right->key << "\n";
            }
            else {
                file << "Right Child Key: NULL\n";
            }

            file.close();
        }
    }


    // Helper function to update the height of a node
    void updateHeight(Node* node) {
        node->height = 1 + max(height(node->left), height(node->right));
    }

    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        x->right = y;
        y->left = T2;

        if (T2) T2->parent = y;
        x->parent = y->parent;
        y->parent = x;

        updateHeight(y);
        updateHeight(x);

        return x;
    }

    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        if (T2) T2->parent = x;
        y->parent = x->parent;
        x->parent = y;

        updateHeight(x);
        updateHeight(y);

        return y;
    }



    // Get balance factor of a node
    int getBalance(Node* node) {
        return node ? height(node->left) - height(node->right) : 0;
    }


    Node* insert(Node* node, const char* key, const char* rowData, Node* parent = nullptr) {
        if (!node) {
            Node* newNode = new Node(key, rowData);
            newNode->parent = parent; 
            return newNode;
        }

        if (compareStrings(key, node->key) < 0) {
            node->left = insert(node->left, key, rowData, node);
        }
        else if (compareStrings(key, node->key) > 0) {
            node->right = insert(node->right, key, rowData, node);
        }
        else {
            return node; // Duplicate keys not allowed
        }

        updateHeight(node);
        int balance = getBalance(node);

        // Handle rotations
        if (balance > 1 && compareStrings(key, node->left->key) < 0)
            return rightRotate(node);
        if (balance < -1 && compareStrings(key, node->right->key) > 0)
            return leftRotate(node);
        if (balance > 1 && compareStrings(key, node->left->key) > 0) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        if (balance < -1 && compareStrings(key, node->right->key) < 0) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        // Update node file
        updateNodeFile(node, rowData);

        return node;
    }



    // Function to compare two strings manually (lexicographically)
    int compareStrings(const char* str1, const char* str2) {
        int i = 0;
        while (str1[i] != '\0' && str2[i] != '\0') {
            if (str1[i] < str2[i]) return -1;
            if (str1[i] > str2[i]) return 1;
            i++;
        }
        if (str1[i] == '\0' && str2[i] == '\0') return 0; // Both are equal
        return (str1[i] == '\0') ? -1 : 1; // If one is shorter than the other
    }

public:
    AVLTree() : root(nullptr) {}

    void insert(const char* key, const char* rowData) {
        root = insert(root, key, rowData);
    }


    // Function to perform an in-order traversal of the tree
    void inOrder(Node* node) {
        if (node != nullptr) {
            inOrder(node->left);
            cout << node->key << " ";
            inOrder(node->right);
        }
    }

    // Start in-order traversal from the root
    void display() {
        inOrder(root);
        cout << endl;
    }
};


void copyDirectory(const char* srcDir, const char* destDir) 
 {
    fs::path srcPath(srcDir);
    fs::path destPath(destDir);

    // Ensure the source directory exists
    if (!fs::exists(srcPath)) {
        cout << "Source directory does not exist: " << srcDir << endl;
        return;
    }

    // Create the destination directory if it doesn't exist
    createDirectory(destDir);

    // Iterate through all files in the source directory
    for (const auto& entry : fs::directory_iterator(srcPath)) {
        if (entry.is_regular_file() && entry.path().extension() == ".txt") {
            // Construct the destination file path
            fs::path destFilePath = destPath / entry.path().filename();
            fs::copy(entry.path(), destFilePath, fs::copy_options::overwrite_existing);
            cout << "Copied: " << entry.path() << " to " << destFilePath << endl;
        }
    }
    cout << "All text files have been copied to the directory: " << destDir << endl;
}


void createFile(const char* dirName, const char* data, int fileIndex) {
    // Create file path: "Original Name/entity_XXXXX.txt"
    char filePath[256];
    snprintf(filePath, sizeof(filePath), "%s/entity_%05d.txt", dirName, fileIndex);

    ofstream outFile(filePath);
    if (outFile.is_open()) {
        outFile << data; // Write the data to the file
        outFile.close();
    }
    else {
        cerr << "Failed to create file: " << filePath << endl;
    }
}


int main()
{
    max_win_size();
    font(21);
    const char* filename = "Book1.csv";
    int columnCount = 0;
    showColumnHeaders(filename, columnCount);
    int selectedColumn = -1;
    while (selectedColumn <= 0 || selectedColumn > columnCount)
    {
        selectedColumn = getUserColumnChoice(columnCount);
        if (selectedColumn <= 0 || selectedColumn > columnCount)
        {
            showColumnHeaders(filename, columnCount);

        }
    }

    // Inside the main function
    const char* dirName = "Original Name";
    const char* fakeDir = "Fake Name";
    createDirectory(dirName); // Ensure the directory is created

    // Open the CSV file and process each row
    ifstream file(filename);
    char line[200]; // To hold each line of the CSV file

    // Skip the header line
    file.getline(line, sizeof(line));

    AVLTree tree;
    while (file.getline(line, sizeof(line)))
    {
        char** columns;
        int size = 0;
        splitString(line, columns, size);
   
        // Insert into AVL Tree based on the selected column
        tree.insert(columns[selectedColumn - 1], line); // Insert the key and row data into the AVL tree

        // Clean up dynamically allocated memory for column data
        for (int i = 0; i < size; ++i) {
            delete[] columns[i];
        }
        delete[] columns;
    }

    file.close();

    // Display the in-order traversal of the AVL tree
    cout << "In-Order Traversal of the AVL Tree:" << endl;
    tree.display();

    file.close();
    cout << "\nDo you want to copy the files from 'Original Name' to 'Fake Name'? (yes/no): ";
    string userResponse;
    cin >> userResponse;

    if (userResponse == "yes" || userResponse == "y") {
        copyDirectory(dirName, fakeDir);
    }
    else {
        cout << "No files were copied." << endl;
    }
    return 0;
}


//
//
//
//
//
//#include <iostream>
//#include <fstream>
//#include<string>
//
//
//struct TreeNode {
//    int data;
//    TreeNode* left;
//    TreeNode* right;
//    TreeNode* parent;
//
//    TreeNode(int val) : data(val), left(nullptr), right(nullptr), parent(nullptr) {}
//};
//
//class AVLTree {
//private:
//    TreeNode* root;
//
//    void writeNodeToFile(TreeNode* node) {
//        std::ofstream file(std::to_string(node->data) + ".txt", std::ios::out);
//        if (file.is_open())
//        {
//            std::cout << "Updating file for node: " << node->data << "\n"; // Debug log
//            if (node->parent) {
//                file << "Parent: " << node->parent->data << "\n";
//            }
//            else {
//                file << "Parent: nullptr\n";
//            }
//
//            if (node->left) {
//                file << "Left Child: " << node->left->data << "\n";
//            }
//            else {
//                file << "Left Child: nullptr\n";
//            }
//
//            if (node->right) {
//                file << "Right Child: " << node->right->data << "\n";
//            }
//            else {
//                file << "Right Child: nullptr\n";
//            }
//        }
//        file.close();
//    }
//
//
//    void updateFileForNode(TreeNode* node) {
//        if (!node) return;
//
//        // Write current node information
//        writeNodeToFile(node);
//
//        // Recursively update children's files
//        if (node->left) {
//            writeNodeToFile(node->left);
//        }
//        if (node->right) {
//            writeNodeToFile(node->right);
//        }
//
//        // Update parent's file to ensure correct child references
//        if (node->parent) {
//            writeNodeToFile(node->parent);
//        }
//    }
//
//    int height(TreeNode* node) {
//        if (!node) return 0;
//        return std::max(height(node->left), height(node->right)) + 1;
//    }
//
//    int balanceFactor(TreeNode* node) {
//        if (!node) return 0;
//        return height(node->left) - height(node->right);
//    }
//
//    TreeNode* rotateRight(TreeNode* y) {
//        TreeNode* x = y->left;
//        TreeNode* T2 = x->right;
//
//        // Perform rotation
//        x->right = y;
//        y->left = T2;
//
//        // Update parents
//        x->parent = y->parent;
//        y->parent = x;
//        if (T2) T2->parent = y;
//
//        // Update files for affected nodes
//        updateFileForNode(x);
//        updateFileForNode(y);
//        if (T2) updateFileForNode(T2);
//
//        return x;
//    }
//
//    TreeNode* rotateLeft(TreeNode* x) {
//        TreeNode* y = x->right;
//        TreeNode* T2 = y->left;
//
//        // Perform rotation
//        y->left = x;
//        x->right = T2;
//
//        // Update parents
//        y->parent = x->parent;
//        x->parent = y;
//        if (T2) T2->parent = x;
//
//        // Update files for affected nodes
//        updateFileForNode(y);
//        updateFileForNode(x);
//        if (T2) updateFileForNode(T2);
//
//        return y;
//    }
//
//
//    TreeNode* insertNode(TreeNode* node, int key, TreeNode* parent) {
//        if (!node) {
//            TreeNode* newNode = new TreeNode(key);
//            newNode->parent = parent;
//            writeNodeToFile(newNode); // Write the new node's relationship to its file
//            return newNode;
//        }
//
//        if (key < node->data)
//            node->left = insertNode(node->left, key, node);
//        else if (key > node->data)
//            node->right = insertNode(node->right, key, node);
//        else
//            return node; // Duplicate keys are not allowed
//
//        // Update balance and perform rotations if necessary
//        int balance = balanceFactor(node);
//
//        if (balance > 1 && key < node->left->data) { // Left Left
//            TreeNode* rotated = rotateRight(node);
//            updateFileForNode(rotated); // Update after rotation
//            return rotated;
//        }
//
//        if (balance < -1 && key > node->right->data) { // Right Right
//            TreeNode* rotated = rotateLeft(node);
//            updateFileForNode(rotated); // Update after rotation
//            return rotated;
//        }
//
//        if (balance > 1 && key > node->left->data) { // Left Right
//            node->left = rotateLeft(node->left);
//            TreeNode* rotated = rotateRight(node);
//            updateFileForNode(rotated); // Update after rotation
//            return rotated;
//        }
//
//        if (balance < -1 && key < node->right->data) { // Right Left
//            node->right = rotateRight(node->right);
//            TreeNode* rotated = rotateLeft(node);
//            updateFileForNode(rotated); // Update after rotation
//            return rotated;
//        }
//
//        // Update file for current node
//        updateFileForNode(node);
//
//        return node;
//    }
//
//public:
//    AVLTree() : root(nullptr) {}
//
//    void insert(int key) {
//        root = insertNode(root, key, nullptr);
//    }
//
//    void display(TreeNode* node, int level = 0) {
//        if (!node) return;
//        display(node->right, level + 1);
//        std::cout << std::string(4 * level, ' ') << node->data << "\n";
//
//        // Display Parent
//        if (node->parent) {
//            std::cout << std::string(4 * level, ' ') << "    Parent of " << node->data << ": " << node->parent->data << "\n";
//        }
//        else {
//            std::cout << std::string(4 * level, ' ') << "    Parent of " << node->data << ": nullptr\n";
//        }
//
//        // Display Left Child
//        if (node->left) {
//            std::cout << std::string(4 * level, ' ') << "    Left Child of " << node->data << ": " << node->left->data << "\n";
//        }
//        else {
//            std::cout << std::string(4 * level, ' ') << "    Left Child of " << node->data << ": nullptr\n";
//        }
//
//        // Display Right Child
//        if (node->right) {
//            std::cout << std::string(4 * level, ' ') << "    Right Child of " << node->data << ": " << node->right->data << "\n";
//        }
//        else {
//            std::cout << std::string(4 * level, ' ') << "    Right Child of " << node->data << ": nullptr\n";
//        }
//
//        display(node->left, level + 1);
//    }
//
//    void displayTree() {
//        display(root);
//    }
//};
//
//int main() {
//    AVLTree tree;
//   /* tree.insert(14);
//    tree.insert(17);
//    tree.insert(11);
//    tree.insert(7);
//    tree.insert(53);
//    tree.insert(4);
//    tree.insert(13);
//    tree.insert(12);
//    tree.insert(8);
//    tree.insert(60);
//    tree.insert(19);
//    tree.insert(16);
//    tree.insert(20);*/
//    tree.insert(85);
//    tree.insert(90);
//    tree.insert(78);
//    tree.insert(92);
//    tree.insert(65);
//    tree.insert(45);
//    tree.insert(97);
//    tree.insert(77);
//    tree.insert(81);
//    tree.insert(68);
//    tree.insert(88);
//    tree.insert(91);
//    tree.insert(72);
//    tree.insert(86);
//    tree.insert(55);
//    std::cout << "Tree structure:\n";
//    tree.displayTree();
//
//    std::cout << "Node relationships are stored in separate text files.\n";
//    return 0;
//}
//




