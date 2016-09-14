//
//  main.cpp
//  Student Directory
//
//  Created by Rechee Jozil on 8/31/16.
//  Copyright © 2016 Rechee Jozil. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    
    bool fileIsOpen = false;
    int selection = 0;
    while (1)
    {
        cout << "Welcome to the Student Maintenance System\n1 = Open Student File\n";
        
        if (fileIsOpen)
        {
            cout << "2 = Add a Student\n3 = Delete a Student\n4 = Update a Student\n5 = View Student Records";
        }
        
        cin >> selection;
        
        switch (selection)
        {
            case 1:
                fileIsOpen = true;
                break;
                
            case 2:
               //code to add
                break;
                
            case 3:
                //code to delete
                break;
                
            case 4:
                //code to update
                break;
                
            case 5:
                //code to view records
                break;
        }
    }
    
    return 0;
}

void AddVoter ()
{
    string name;
    string email;
    string uid;
    string presentationGrade;
    string essay1Grade;
    string essay2Grade;
    string teamGrade;
    
    cout << "Enter Student Name";
    cin >> name;
    
    cout << "Enter Student Email";
    cin >> email;
    
    cout << "Enter Student UID";
    cin >> uid;
    
    cout << "Enter Student Presentation Grade";
    cin >> presentationGrade;
    
    cout << "Enter Student Essay 1 Grade";
    cin >> essay1Grade;
    
    cout << "Enter Student Essay 2 Grade";
    cin >> essay2Grade;
    
    cout << "Enter Student Team Grade";
    cin >> teamGrade;
}

void DeleteVoter ()
{
    cout << "Enter the UID of the student to be deleted";
}
