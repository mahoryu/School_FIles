/***********************************************************************
* Program:
*    Assignment 02, Digital Forensics
*    Brother Alvey, CS165
* Author:
*    Ethan Holden
* Summary: 
*    This program prompts the user for a file and then searches the file
*    for all records within a user inserted time frame and displays those
*    records back to the user.
*
*    Estimated:  4.0 hrs   
*    Actual:     5.2 hrs
*      The most difficult part was easily trying to figure out how to
*      read the file into the AccessRecord structure. Once I figured that
*      out it went fairly smoothly.
************************************************************************/

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

struct AccessRecord
{
   string filename;
   string username;
   long timestamp;
};
 
void promptFile(char filename[]);
void readFile(char filename[], AccessRecord records[]);
void promptTimes(long times[]);
void search(long times[], AccessRecord records[], bool fDisplay[]);
void display(AccessRecord records[], bool fDisplay[]);


/**********************************************************************
 * Function: main
 * Prompts the user for a file name, reads that file into an array,
 * then prompts the user for a time frame to search within and then once
 * it finishes searching for those records, it then displays them for
 * the user to see.
 ***********************************************************************/
int main()
{
   AccessRecord records[500];
   char filename[256];
   promptFile(filename);
   readFile(filename, records);
   
   long times[2];
   promptTimes(times);

   bool fDisplay[500];
   search(times, records, fDisplay);

   display(records, fDisplay);

   return 0;
}

/**********************************************************************
 * Function: promptFile
 * Prompts the user for the file they want to be read.
 ***********************************************************************/
void promptFile(char filename[])
{
   cout << "Enter the access record file: ";
   cin  >> filename;
   cout << endl;
}

/**********************************************************************
 * Function: readFile
 * Reads the given file and saves it to records.
 ***********************************************************************/
void readFile(char filename[], AccessRecord records[])
{
   ifstream fin(filename);
   if (fin.fail())
   {
      cout << "ERROR! File Cannot be read.\n";
      fin.close();
      return;
   }
   else
   {
      for (int i = 0; i < 500; i++)
         fin >> records[i].filename
             >> records[i].username
             >> records[i].timestamp;
   }
   
   fin.close();
   return;
}


/**********************************************************************
 * Function: promptTimes
 * Prompts the user for the start and end times of the search criteria.
 ***********************************************************************/
void promptTimes(long times[])
{
   cout << "Enter the start time: ";
   cin  >> times[0];
   cout << "Enter the end time: ";
   cin  >> times[1];
   cout << endl;
}


/**********************************************************************
 * Function: search
 * Looks through the records and sets a marker (fDisplay) for each
 * record that falls within the search.
 ***********************************************************************/
void search(long times[], AccessRecord records[], bool fDisplay[])
{
   //reset the bool marker
   for (int i = 0; i < 500; i++)
      fDisplay[i] = false;
   //search for valid functions.
   for (int i = 0; i < 500; i++)
      if (records[i].timestamp >= times[0] &&
          records[i].timestamp <= times[1])
         fDisplay[i] = true;
}

/**********************************************************************
 * Function: display
 * Displays the files that fall within the search criteria.
 ***********************************************************************/
void display(AccessRecord records[], bool fDisplay[])
{
   cout << "The following records match your criteria:\n\n";
   cout << setw(15) << "Timestamp"
        << setw(20) << "File"
        << setw(21) << "User\n";
   cout << "--------------- ------------------- -------------------\n";

   for (int i = 0; i < 500; i++)
      if (fDisplay[i])
         cout << setw(15) << records[i].timestamp
              << setw(20) << records[i].filename
              << setw(20) << records[i].username
              << endl;
   
   cout << "End of records\n";
}
