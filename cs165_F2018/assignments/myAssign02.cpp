/***********************************************************************
* Program:
*    Assignment 02, Digital Forensics
*    Brother Alvey, CS165
* Author:
*    Ethan Holden
* Summary: 
*    This program ask the user for a file name of the log of access
*    records and then reads that file into a usable array. The program
*    then prompts the user to enter a time frame by asking for a start
*    and end time. It then displays all records that fall within the
*    selected time frame back to the user.
*
*    Estimated:  3.0 hrs   
*    Actual:     1.8 hrs
*      The most difficult part was remembering how to read files into an
*      array and then remembering exactly how to search through that
*      array.
************************************************************************/

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

struct AccessRecord
{
   string username;
   string filename;
   long timestamp;
};

void promptFile(char filename[]);
bool readFile(char filename[], AccessRecord records[]);
void promptTimes(long times[]);
void search(AccessRecord records[], long times[], AccessRecord found[]);
void display(AccessRecord found[]);

/**********************************************************************
 * Function: main
 * This function prompts the user for a file, reads the file into an
 * array. Then prompts the user for a search time and then displays
 * those records that fall within the allotted time frame.
 ***********************************************************************/
int main()
{

   AccessRecord records[500];
   char filename[256];
   promptFile(filename);

   //end program if it fails
   bool fail = readFile(filename, records);
   if (fail)
      return 0;
   else
   {
      long times[2];
      promptTimes(times);

      AccessRecord found[500];
      search(records, times, found);
   
      display(found);
      return 0;
   }
}

/**********************************************************************
 * Function : promptFile
 * prompts the user for a file name and returns it to the program.
 ***********************************************************************/
void promptFile(char filename[])
{
   cout << "Enter the access record file: ";
   cin  >> filename;
   cout << endl;
}

/**********************************************************************
 * Function : readFile
 * calls on promptFile and then reads the file into an array.
 ***********************************************************************/
bool readFile(char filename[], AccessRecord records[])
{   
   //read file
   ifstream fin(filename);
   if (fin.fail())
   {
      //stop function if unable to open
      cout << "Unable to open file "
           << filename << endl;
      fin.close();
      return 1;
   }
   else
   {
      for (int i = 0; i < 500; i++)
      {
         fin >> records[i].filename
             >> records[i].username
             >> records[i].timestamp;
      }
      fin.close();
      return 0;
   }
}

/**********************************************************************
 * Function : promptTime
 * prompts the user for a start time and an end time for the display
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
 * Function : search
 * finds the records that fall within the set time period and sets them
 * to the found array.
 ***********************************************************************/
void search(AccessRecord records[], long times[], AccessRecord found[])
{
   int y = 0;
   for (int i = 0; i < 500; i++)
   {
      if (records[i].timestamp >= times[0] &&
          records[i].timestamp <= times[1])
      {
         found[y] = records[i];
         y++;
      }
   }
}


/**********************************************************************
 * Function : display
 * displays the records that fall within the time frame
 ***********************************************************************/
void display(AccessRecord found[])
{
   cout << "The following records match your criteria:\n\n";
   cout << setw(15) << "Timestamp"
        << setw(20) << "File"
        << setw(21) << "User\n";
   cout << "--------------- ------------------- -------------------\n";

   for (int i = 0; found[i].timestamp != 0; i++)
   {
      cout << setw(15) << found[i].timestamp
           << setw(20) << found[i].filename
           << setw(20) << found[i].username
           << endl;
   }
   cout << "End of records\n";
}
