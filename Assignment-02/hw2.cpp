#include <iostream>
#include <fstream>
#include <chrono>
#include <iomanip>

using namespace std;
using namespace std::chrono;
#pragma pack(push, 1)
struct DiabeticRecord {
int64_t encounter_id;
int64_t patient_nbr;
char gender[16];
char age[16];
int32_t admission_type_id;
int32_t discharge_disposition_id;
int32_t admission_source_id;
int32_t time_in_hospital;
int32_t num_lab_procedures;
int32_t num_procedures;
int32_t num_medications;
int32_t number_outpatient;
int32_t number_emergency;
int32_t number_inpatient;
int32_t number_diagnoses;
};
#pragma pack(pop)

struct Node
{
    DiabeticRecord data;
    Node* nextPtr;
};

DiabeticRecord staticArray[101766];

void printRecords(DiabeticRecord data, int i)
{
    
    cout << "Index [" << setw(2) << i << "] | " << "(Pos " << setw(2) << i+1 << ")" << " EncID: " << setw(8) << data.encounter_id << " | "
    << " PatNbr: " << setw(12) << data.patient_nbr << " | " << " Gender: "  << setw(9) << right << data.gender <<
    " | " << " Age: " << setw(8) << right << data.age  << endl;
}


int main() 
{

Node* head = nullptr;
Node* tail = nullptr;



ifstream file("batch2_remaining.bin", ios::in | ios::binary);
if (!file)
{
    cout << "Error!" << endl;
}

int i = 0;

while(file.read((char*)&staticArray[i], sizeof(staticArray[i])))
{
    i++;
}
file.close();


ifstream file2("batch2_remaining.bin", ios::in | ios::binary);
if (!file2)
{
    cout << "Error!" << endl;
}



while(true)
{
    Node* newNode = new Node;
    if(!file2.read((char*)&newNode->data, sizeof(newNode->data)))
    {
        delete newNode;
        break;

    }
    if (head == nullptr)
    {
        head = newNode;
        tail = newNode;
    } else 
    {
        tail->nextPtr = newNode;
        tail = newNode;
    }

}
file2.close();

auto start = high_resolution_clock::now();
for (int i = 101755; i >= 9; i--)
{
    staticArray[i+10] = staticArray[i];
}

ifstream file3("batch1_first10.bin", ios::in | ios::binary);

for(int j = 9; j <= 18; j++)
{
    file3.read((char*)&staticArray[j], sizeof(staticArray[j]));

}
file3.close();
auto end = high_resolution_clock::now();
auto duration = duration_cast<microseconds>(end - start);

auto start2 = high_resolution_clock::now();

Node* tempPtr = head;
for (int i = 0; i < 8; i++)
{
    tempPtr = tempPtr->nextPtr;

}
Node* tempPtr2 = tempPtr->nextPtr;

Node* head2 = nullptr;
Node* tail2 = nullptr;

for(int i = 0; i < 10; i++)
{
    Node* newNode = new Node;
    newNode->data = staticArray[i+9];
    if (head2 == nullptr)
    {
        head2 = newNode;
        tail2 = newNode;
    } else 
    {
        tail2->nextPtr = newNode;
        tail2 = newNode;
    }
    /*tempPtr->nextPtr = head2;
    tail2->nextPtr = tempPtr2;*/


}
tempPtr->nextPtr = head2;
    tail2->nextPtr = tempPtr2;

auto end2 = high_resolution_clock::now();
auto duration2 = duration_cast<microseconds>(end2 - start2);
Node* curr = head;
cout << setfill('=') << setw(16) << "=" << " FIRST 20 RECORDS (SINGLY LINKED LIST) " << setfill('=') << setw(16) << "=" << endl;
cout << setfill(' ');

for(int i = 0; i < 20; i++)
{
    
    printRecords(curr->data, i);
    curr = curr->nextPtr;


}
//
cout << setfill('=') << setw(16) << "=";
cout << " EXECUTION TIME COMPARISONS ";
cout << setfill('=') << setw(16) << "=";
cout << endl;
cout << "Static Array Insertion Time (at index 9): " << setfill(' ') << setw(6) << " " << fixed << setprecision(3) << static_cast<double>(duration.count()) << " microseconds" << endl;
cout << "Singly Linked List Insertion Time (at index 9): " << setfill(' ') << setw(3) << " " << fixed << setprecision(3) << static_cast<double>(duration2.count()) << " microseconds" << endl;
cout << setfill('=') << setw(60) << "=" << endl;
//cout << "In " << duration2.count() << " microseconds" << endl;
/**/
// cleans up memory
curr = head;
while(curr != nullptr)
{
    Node* nextNode = curr->nextPtr;
    delete curr;
    curr = nextNode;

}
}

