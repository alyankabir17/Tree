#include <iostream>
#include "BST.h" 

using namespace std;

void displayMenu() {
    cout << "Binary Search Tree Operations Menu:" << endl;
    cout << "1. Insert an element" << endl;
    cout << "2. Delete an element" << endl;
    cout << "3. Search for an element" << endl;
    cout << "4. Display tree (in-order)" << endl;
    cout << "5. Display tree (pre-order)" << endl;
    cout << "6. Display tree (post-order)" << endl;
    cout << "7. Count elements" << endl;
    cout << "8. Find parent of an element" << endl;
    cout << "9. Exit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    BST<int> bst;
    int choice, element;
    do {
        displayMenu();
        cin >> choice;
        
        switch(choice) {
            case 1:
                cout << "Enter element to insert: ";
                cin >> element;
                bst.insert(element);
                break;
            case 2:
                cout << "Enter element to delete: ";
                cin >> element;
                bst.deleteNode(element);
                break;
            case 3:
                cout << "Enter element to search: ";
                cin >> element;
                if (bst.recurSearch(element, bst.getRoot())) {
                    cout << "Element found in the tree." << endl;
                } else {
                    cout << "Element not found in the tree." << endl;
                }
                break;
            case 4:
                cout << "In-order traversal: ";
                bst.inorder(bst.getRoot());
                cout << endl;
                break;
            case 5:
                cout << "Pre-order traversal: ";
                bst.preorder(bst.getRoot());
                cout << endl;
                break;
            case 6:
                cout << "Post-order traversal: ";
                bst.postorder(bst.getRoot());
                cout << endl;
                break;
            case 7:
                cout << "Number of elements in the tree: " << bst.countElement(bst.getRoot()) << endl;
                break;
            case 8:
                cout << "Enter element to find its parent: ";
                cin >> element;
                try {
                    cout << "Parent of " << element << " is: " << bst.getParent(element) << endl;
                } catch (const exception& e) {
                    cerr << e.what() << endl;
                }
                break;
            case 9:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 9);
    
    return 0;
}
