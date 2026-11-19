#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

double averageCalc(int64_t sum, int counter)
{
    
    double avg = 0;
    avg = (double)sum/(double)counter;
    return avg;
}



int main () {
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

DiabeticRecord records;
int counter = 0;
int64_t max_encounterid = 0;
int64_t max_patientNbr = 0;
int32_t sum_admission_type_id = 0;
int32_t sum_discharge_disposition_id = 0;
int32_t sum_admission_source_id = 0;
int32_t sum_time_in_hospital = 0;
int32_t sum_num_lab_procedures = 0;
int32_t sum_num_procedures = 0;
int32_t sum_num_medications = 0;
int32_t sum_number_outpatient = 0;
int32_t sum_number_emergency = 0;
int32_t sum_number_inpatient = 0;
int32_t sum_number_diagnoses = 0;

double avg_admission_type_id = 0;
double avg_discharge_diposition_id = 0;
double avg_admission_source_id = 0;
double avg_time_in_hospital = 0;
double avg_num_lab_procedures = 0;
double avg_num_procedures = 0;
double avg_num_medications = 0;
double avg_number_outpatient = 0;
double avg_number_emergency = 0;
double avg_number_inpatient = 0;
double avg_number_diagnoses = 0;


// open
ifstream file("diabetic_data.bin", ios::in | ios::binary);
if (!file)
{
    cout << "Error!" << endl;
}

while (file.read((char*)&records, sizeof(records)))
{
    counter++;

    sum_admission_type_id += records.admission_type_id;
    sum_discharge_disposition_id += records.discharge_disposition_id;
    sum_admission_source_id += records.admission_source_id;
    sum_time_in_hospital += records.time_in_hospital;
    sum_num_lab_procedures += records.num_lab_procedures;
    sum_num_procedures += records.num_procedures;
    sum_num_medications += records.num_medications;
    sum_number_outpatient += records.number_outpatient;
    sum_number_emergency += records.number_emergency;
    sum_number_inpatient += records.number_inpatient;
    sum_number_diagnoses += records.number_diagnoses;




    if(records.encounter_id > max_encounterid)
    {
        max_encounterid = records.encounter_id;
    }
    if(records.patient_nbr > max_patientNbr) 
    {
        max_patientNbr = records.patient_nbr;
    }
    

}
file.close();
cout << counter << endl;

avg_admission_type_id = averageCalc(sum_admission_type_id, counter);
avg_discharge_diposition_id = averageCalc(sum_discharge_disposition_id, counter);
avg_admission_source_id = averageCalc(sum_admission_source_id, counter);
avg_time_in_hospital = averageCalc(sum_time_in_hospital, counter);
avg_num_lab_procedures = averageCalc(sum_num_lab_procedures, counter);
avg_num_procedures = averageCalc(sum_num_procedures, counter);
avg_num_medications = averageCalc(sum_num_medications, counter);
avg_number_outpatient = averageCalc(sum_number_outpatient, counter);
avg_number_emergency = averageCalc(sum_number_emergency, counter);
avg_number_inpatient = averageCalc(sum_number_inpatient, counter);
avg_number_diagnoses = averageCalc(sum_number_diagnoses, counter);

cout << "================ DATA SUMMARY ================" << endl;
cout << "Total Records Processed: " << counter << endl;
cout << endl;
cout << "Maximum Identifiers: " << endl;
cout << "-- Max Encounter ID: " << max_encounterid << endl;
cout << "-- Max Patient Nbr: " << max_patientNbr << endl;
cout << endl;
cout << "Field Averages: " << endl;
cout << "-- Admission Type ID" << setw(5) << ": " <<  setw(1) << fixed << setprecision(2) << avg_admission_type_id << endl;
cout << "-- Discharge Disp. ID" << setw(5) << ": " <<  setw(1) << fixed << setprecision(2) << avg_discharge_diposition_id << endl;
cout << "-- Admission Source ID" << setw(5) << ": " <<  setw(1) << fixed << setprecision(2) << avg_admission_source_id << endl;
cout << "-- Time In Hospital" << setw(5) << ": " <<  setw(1) << fixed << setprecision(2) << avg_time_in_hospital << " days" << endl;
cout << "-- Num Lab Procedures" << setw(5) << ": " <<  setw(1) << fixed << setprecision(2) << avg_num_lab_procedures << endl;
cout << "-- Num Procedures" << setw(5) << ": " <<  setw(1) << fixed << setprecision(2) << avg_num_procedures << endl;
cout << "-- Num Medications" << setw(5) << ": " << setw(1) << fixed << setprecision(2) << avg_num_medications << endl;
cout << "-- Outpatient Visits" << setw(5) << ": " << setw(1) << fixed << setprecision(2) << avg_number_outpatient << endl;
cout << "-- Emergency Visits" << setw(5) << ": " << setw(1) << fixed << setprecision(2) << avg_number_emergency << endl;
cout << "-- Inpatient Visits" << setw(5) << ": " << setw(1) << fixed << setprecision(2) << avg_number_inpatient << endl;
cout << "-- Number Diagnosis" << setw(5) << ": " << setw(1) << fixed << setprecision(2) << avg_number_diagnoses << endl;
cout << setw(46) << setfill('=') << endl; 
}