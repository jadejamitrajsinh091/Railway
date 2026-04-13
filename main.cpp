#include <iostream>
#include <vector>
using namespace std;

class Train
{
private:
    int trainNumber;
    string trainName;
    string source;
    string destination;
    string trainTime;

    static int trainCount;  

public:
    // Default Constructor
    Train()
    {
        trainNumber = 0;
        trainName = "xyz";
        source = "s1";
        destination = "d1";
        trainTime = "12:00";

        trainCount++;  
    }

    // Parameterized Constructor
    
    Train(int num, string name, string src, string dest, string time)
    {
        trainNumber = num;
        trainName = name;
        source = src;
        destination = dest;
        trainTime = time;

        trainCount++;  
    }

    // Copy Constructor
    
    Train(const Train &obj)
    {
        trainNumber = obj.trainNumber;
        trainName = obj.trainName;
        source = obj.source;
        destination = obj.destination;
        trainTime = obj.trainTime;

        trainCount++;   
    }

    // Destructor
    ~Train()
    {
        trainCount--;  
        cout << "Train Destructor Called\n";
    }

    void inputTrain()
    {
        cout << "Enter Train Number: ";
        cin >> trainNumber;

        cin.ignore();

        cout << "Enter Train Name: ";
        getline(cin, trainName);

        cout << "Enter Source: ";
        getline(cin, source);

        cout << "Enter Destination: ";
        getline(cin, destination);

        cout << "Enter Train Time: ";
        getline(cin, trainTime);
    }

    int getTrainNumber() const
    {
        return trainNumber;
    }

    void displayTrain() const
    {
        cout << "\nTrain Number: " << trainNumber << endl;
        cout << "Train Name: " << trainName << endl;
        cout << "Source: " << source << endl;
        cout << "Destination: " << destination << endl;
        cout << "Train Time: " << trainTime << endl;
    }

    static int getTrainCount()
    {
        return trainCount;
    }
};

int Train::trainCount = 0;


class RailwaySystem
{
private:
    vector<Train> trains;

public:
    void addTrain()
    {
        Train t;
        t.inputTrain();
        trains.push_back(t);
        cout << "Train Added Successfully\n";
    }

    void displayAll()
    {
        if (trains.empty())
        {
            cout << "No Train Data Found\n";
            return;
        }

        for (int i = 0; i < trains.size(); i++)
        {
            cout << "\n--- Train " << i + 1 << endl;
            trains[i].displayTrain();
        }

        cout << "\nTotal Trains: " << Train::getTrainCount() << endl;
    }

    void searchTrain(int num)
    {
        for (int i = 0; i < trains.size(); i++)
        {
            if (trains[i].getTrainNumber() == num)
            {
                cout << "Train Found\n";
                trains[i].displayTrain();
                return;
            }
        }

        cout << "Train Not Found\n";
    }
};


int main()
{
    RailwaySystem system;
    int choice = 0, number;

    while (choice != 4)
    {
        cout << "\n===== Railway Reservation System =====\n";
        cout << "1. Add Train\n";
        cout << "2. Display All Trains\n";
        cout << "3. Search Train\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            system.addTrain();
            break;

        case 2:
            system.displayAll();
            break;

        case 3:
            cout << "Enter Train Number: ";
            cin >> number;
            system.searchTrain(number);
            break;

        case 4:
            cout << "Exiting System...\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }
    }

    return 0;
}