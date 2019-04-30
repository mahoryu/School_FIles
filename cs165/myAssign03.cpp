/***********************************************************************
* Program:
*    Assignment 03, Digital Forensics With Corrupted Files
*    Brother Alvey, CS165
* Author:
*    Ethan Holden
* Summary:
*    This program prompts the user for a file and then reads that file
*    and displays all corrupted records within the file. Then it prompts
*    the user to enter a search range and then displays all valid
*    records within the search criteria.
*
*    Estimated:  4.0 hrs   
*    Actual:     6.3 hrs
*      The most difficult part was first getting the throw and catch to
*      work properly. I kept trying to throw a (string *) when I needed
*      to just throw a (string), then I had trouble getting the
*      functions to nest properly.        
************************************************************************/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

struct AccessRecord
{
   string filename;
   string username;
   long timestamp;
};

#define SIZE 500

/**********************************************************************
 * Function: promptFile
 * Prompts the user for the file they want to be read.
 ***********************************************************************/
string promptFile()
{
   string filename;
   cout << "Enter the access record file: ";
   cin  >> filename;
   
   return filename;
}

/**********************************************************************
 * Function: parseLine
 * Takes the string line and divides it up into the different parts of
 * the declared structure.
 ***********************************************************************/
AccessRecord parseLine(const string line) throw (string)
{
   AccessRecord newRecord;
   stringstream buffer(line);

   buffer >> newRecord.filename;
   buffer >> newRecord.username;
   buffer >> newRecord.timestamp;
   if (buffer.fail())
      throw line;
   if (newRecord.timestamp < 1000000000
       || newRecord.timestamp > 10000000000)
      throw line;
         
   
   return newRecord;
}

/**********************************************************************
 * Function: parseFile
 * Takes the filename given by the user and reads it. Then it gets
 * each line of the file, and calls on parseLine to to place the
 * information into the structure records.
 ***********************************************************************/
int parseFile(AccessRecord records[])
{
   string filename = promptFile();

   ifstream fin(filename.c_str());
   if (fin.fail())
   {
      cout << "ERROR! File cannot be read.";
      fin.close();
      return 0;
   }
         
   string line;
   int numRecords = 0;
   int i = 0;


   while (getline(fin, line))
   {
      try
      {
         records[i] = parseLine(line);
         numRecords++;
         i++;
      }
            
      catch (string message)
      {
         cout << "Error parsing line: " << message << endl;
         continue;
      }
   }
      
      
   fin.close();
           
   return numRecords;
}

/**********************************************************************
 * Function: promptTimes
 * Prompts the user for the start and end times of the search criteria.
 ***********************************************************************/
void promptTimes(long times[])
{
   cout << endl;
   cout << "Enter the start time: ";
   cin  >> times[0];
   cout << "Enter the end time: ";
   cin  >> times[1];
   cout << endl;
}

/**********************************************************************
 * Function: displayLine
 * Displays a line of the records.
 ***********************************************************************/
void displayLine(const AccessRecord records[], const long times[], int i)
{
   if (records[i].timestamp >= times[0] &&
       records[i].timestamp <= times[1])
      cout << setw(15) << records[i].timestamp
           << setw(20) << records[i].filename
           << setw(20) << records[i].username
           << endl;
}


/**********************************************************************
 * Function: display
 * Calls on all other functions and displays the files that fall within
 * the search criteria.
 ***********************************************************************/
void display()
{
   AccessRecord records[SIZE];
   int numRecords = parseFile(records);
   
   long times[2];
   promptTimes(times);
   
   cout << "The following records match your criteria:\n\n";
   cout << setw(15) << "Timestamp"
        << setw(20) << "File"
        << setw(21) << "User\n";
   cout << "--------------- ------------------- -------------------\n";

   for (int i = 0; i < numRecords; i++)
      displayLine(records, times, i);
      
   cout << "End of records\n";
}


/**********************************************************************
 * Function: main
 * Asks the user for a filename, reads the file. Displays the corrupted
 * records. And then parses the file into a structure and then prompts
 * the user for search times. It then displays all valid records that
 * fall within the search criteria.
 ***********************************************************************/
int main()
{
   display();
         
   return 0;
}
