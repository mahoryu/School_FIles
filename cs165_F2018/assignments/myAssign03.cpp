/***********************************************************************
* Program:
*    Assignment 03, Digital Forensics with Corrupt Files
*    Brother Alvey, CS165
* Author:
*    Ethan Holden
* Summary: 
*    The program first prompts the user for a file, then reads through
*    the file to see if any records are corrupt. If there are any then
*    it displays an error message of which ones and then prompts the user
*    for a start and end time frame to search for. The program then
*    displays all non-corrupt files within the time frame for the user to
*    see.
*
*    Estimated:  3.0 hrs   
*    Actual:     1.5 hrs
*      The most difficult part was figuring out how to get the parseFile
*      function to stop iterating once there was no more data to read.
************************************************************************/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

struct AccessRecord
{
   string username;
   string filename;
   long timestamp;
};

#define SIZE 500

/**********************************************************************
 * Function : promptFile
 * prompts the user for a file name and returns it to the program.
 ***********************************************************************/
void promptFile(char filename[])
{
   cout << "Enter the access record file: ";
   cin  >> filename;
}

/**********************************************************************
 * Function : parseLine
 * takes each line and checks if that line is corrupt or not and throws
 * an exception if it is.
 ***********************************************************************/
AccessRecord parseLine(string line)throw (const char *)
{
   AccessRecord newRec;
   stringstream buffer(line);
   buffer >> newRec.filename;
   buffer >> newRec.username;
   buffer >> newRec.timestamp;
   if (buffer.fail() ||
       newRec.timestamp < 1000000000 ||
       newRec.timestamp > 10000000000)
      throw "Error parsing line: ";

   return newRec;
}

/**********************************************************************
 * Function : parseFile
 * takes the filename and reads each line. It then runs each line through
 * parseLine before adding it to the array.
 ***********************************************************************/
bool parseFile(char filename[], AccessRecord records[])
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
      string line;
      int i = 0;
      //add each non corrupt line to records[]
      while (getline(fin, line))
      {
         try
         {
            //checks each line if it's corrupt
            records[i] = parseLine(line);
            i++;
         }
         catch (const char * message)
         {
            //displays each corrupted line as an error.
            cout << message << line << endl;
         }
      }
      fin.close();
      cout << endl;
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
 * Calls on the other functions to gather the information and displays
 * the records that fall within the time frame
 ***********************************************************************/
void display()
{
   AccessRecord records[SIZE];
   char filename[256];
   promptFile(filename);
   
   
   //end program if it fails
   bool fail = parseFile(filename, records);
   if (fail)
      return;
   else
   {
      long times[2];
      promptTimes(times);

      AccessRecord found[500];
      search(records, times, found);
      
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

      return;
   }
}

/**********************************************************************
 * function : main
 * calls on the display to execute the program.
 ***********************************************************************/
int main()
{
   display();

   return 0;
}
