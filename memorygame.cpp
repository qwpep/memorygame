#include <iostream>
#include <string>
#include <algorithm>
#include <random>

using namespace std;

int main()
{
   int size;

   do
   {
      cout << "Welcome to Memory Game!" << endl
           << "Enter the size of array (6-20):";
      cin >> size;
   } while (size < 6 || size > 20 || size % 2 != 0);

   int *arr = new int[size];
   string *strArr = new string[size];

   int n = 0;

   for (int i = 0; i < size; i += 2)
   {
      arr[i] = n;
      arr[i + 1] = n;
      ++n;
   }

   for (int i = 0; i < size; ++i)
   {
      strArr[i] = "?";
   }

   random_device rd;
   mt19937 gen(rd());
   shuffle(arr, arr + size, gen);

   int match = 0;

   do
   {
      cout << endl << "Here is the array: " ;
      for (int i = 0; i < size; ++i)
      {
         cout << strArr[i] << " ";
      }
      
      cout << endl << endl << "Enter the index to show: ";
      int first;
      cin >> first;
      cout << "The card at index " << first << " is: " << arr[first] << endl << endl;

      cout << "Enter the second index to show: ";
      int second;
      cin >> second;

      if (first == second)
      {
         do
         {
            cout << "This index is already selected! Choose another!" << endl;
            cout << "Enter the second index to show: ";
            cin >> second;
         } while (first == second);
      }
      cout << "The card at index " << second << " is: " << arr[second] << endl << endl;

      if (arr[first] == arr[second])
      {
         cout << "Great! The cards are matched. Continue..." << endl;
         match++;
         strArr[first] = to_string(arr[first]);
         strArr[second] = to_string(arr[second]);
         cout << "Press Enter to continue...";
         getchar();
         getchar();
      }

      else
      {
         cout << "The cards do not match. Try again!" << endl;
         cout << "Press Enter to continue...";
         getchar();
         getchar();
      }
      system("cls");
   } while (match != size / 2);

   cout << "Congratulations! You win!";

   return 0;
}
