#include <iostream>
#include <string>
using namespace std;

struct Doctor{
    string name;
    int age;
    string dept;
};

struct Patient{
    string name;
    int age;
    string disease;
    Doctor dct;
};

struct Hospital{
    string name;
    Patient p;
};

void addPatient(Patient *p, int);
void displayAll(Patient *p, int);
void dischargePatient(Patient *&p, int &n);

int main() {
    int n, choice;
    cout<<"Enter number of patients: ";
    cin>>n;
    
    Patient *p = new Patient[n];
    
    do{
        cout<<"1: Add Patient Details"<<endl;
        cout<<"2: Display all Patients"<<endl;
        cout<<"3: Discharge Patient"<<endl;
        cout<<"4: Exit"<<endl;
        cin>>choice;
        
        switch(choice){
            case 1:
            addPatient(p, n);
            break;
            
            case 2:
            displayAll(p, n);
            break;
            
            case 3:
            dischargePatient(p, n);
            break;
            
            default:
            cout<<"Enter Valid Number ";
        }
    }
    while(choice != 4);
    
    delete[] p;
    
    return 0;
}

void addPatient(Patient *p, int n){
    
    for(int i = 0; i < n; i++){
        cout<<"Enter Patient Name "<<i+1<<" ";
        cin>>p[i].name;
        cout<<"Enter Age of Patient "<<i+1<<" ";
        cin>>p[i].age;
        cout<<"Enter disease of Patient "<<i+1<<" ";
        cin>>p[i].disease;
        
        cout<<"Enter Assigned Doctor Name of Patient "<<i+1<<" ";
        cin>>p[i].dct.name;
        cout<<"Enter Age of Assigned Doctor of Patient "<<i+1<<" ";
        cin>>p[i].dct.age;
        cout<<"Enter Department of Assigned Doctor of Patient"<<i+1<<" ";
        cin>>p[i].dct.dept;
        
    }
}

void displayAll(Patient *p, int n){
    if (n == 0) {
        cout << "No patients available!" << endl;
        return;
    }
    for(int i = 0; i < n; i++){
        
        cout<<"Patient Name: "<<p[i].name<<endl;
        
        cout<<"Patient Age: "<<p[i].age<<endl;
       
        cout<<"Patient Disease: "<<p[i].disease<<endl;
        
        cout<<"Doctor Name: "<<p[i].dct.name<<endl;
        
        cout<<"Doctor Age: "<<p[i].dct.age<<endl;
        
        cout<<"Doctor Department: "<<p[i].dct.dept<<endl;
        
    }
}

void dischargePatient(Patient *&p, int &n){
    if (n == 0) {
        cout << "No patients to discharge!" << endl;
        return;
    }
    string disName;
    int index = -1;
    cout<<"Enter name of Patient to discharge ";
    cin>>disName;
    
    for(int i = 0; i < n; i++){
        
        if(p[i].name == disName){
            index = i;
            break;
        }
   
    }
    
    if(index == -1){
        cout<<"Patient Not Found!";
        return;
    }
    
    Patient *temp = new Patient[n - 1];
    
    for(int i = 0, j = 0; i < n; i++){
        if(i != index){
            temp[j++] = p[i];
        }
    }
    
    delete[] p;
    p = temp;
    n--;
    
    cout << "Patient " << disName << " discharged successfully!" << endl;
    
    if (n == 0) {
        delete[] p;
        p = nullptr;
    }
    
}
