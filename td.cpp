#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void addTask() {
    string task;
    cout << "Enter task: ";
    cin.ignore();
    getline(cin, task);
    
    ofstream file("tasks.txt", ios::app);
    if (file.is_open()) {
        file << task << endl;
        file.close();
        cout << "Task added!\n";
    } else {
        cout << "Error opening file!\n";
    }
}

void viewTasks() {
    ifstream file("tasks.txt");
    string task;
    int count = 1;
    
    if (file.is_open()) {
        while (getline(file, task)) {
            cout << count++ << ". " << task << endl;
        }
        file.close();
    } else {
        cout << "No tasks found!\n";
    }
}

int main() {
    int choice;
    do {
        cout << "\n1. Add Task\n2. View Tasks\n3. Exit\nEnter choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1: addTask(); break;
            case 2: viewTasks(); break;
            case 3: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 3);
    
    return 0;
}
