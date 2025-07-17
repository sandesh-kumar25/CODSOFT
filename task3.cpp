#include<iostream>
#include<vector>
#include<string>

using namespace std;

struct Task {
    string name;
    bool completed;
};

vector<Task> tasks;

void addTask(string taskName) {
    Task newTask = {taskName, false};
    tasks.push_back(newTask);
    cout << "Task added!\n";
}

void viewTasks() {
    if (tasks.empty()) {
        cout << "No tasks in your list.\n";
        return;
    }

    cout << "\nYour Tasks:\n";
    for (int i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". " << tasks[i].name
             << " [" << (tasks[i].completed ? "Completed" : "Pending") << "]\n";
    }
}

void markCompleted(int taskNumber) {
    if (taskNumber < 1 || taskNumber > tasks.size()) {
        cout << "Invalid task number.\n";
        return;
    }
    tasks[taskNumber - 1].completed = true;
    cout << "Task marked as completed!\n";
}

void removeTask(int taskNumber) {
    if (taskNumber < 1 || taskNumber > tasks.size()) {
        cout << "Invalid task number.\n";
        return;
    }
    tasks.erase(tasks.begin() + taskNumber - 1);
    cout << "Task removed!\n";
}

int main() {
    int choice;
    string taskName;
    int taskNumber;

    do {
        cout << "\n--- TO-DO LIST MANAGER ---\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;
        cin.ignore(); // To ignore newline after integer input

        switch (choice) {
            case 1:
                cout << "Enter task name: ";
                getline(cin, taskName);
                addTask(taskName);
                break;
            case 2:
                viewTasks();
                break;
            case 3:
                cout << "Enter task number to mark completed: ";
                cin >> taskNumber;
                markCompleted(taskNumber);
                break;
            case 4:
                cout << "Enter task number to remove: ";
                cin >> taskNumber;
                removeTask(taskNumber);
                break;
            case 5:
                cout << "Exiting To-Do List. Goodbye!\n";
                break;
            default:
                cout << "Invalid option. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}

