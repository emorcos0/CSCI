#include <iostream>
#include <string>
#include <fstream>
#include <exception>

using namespace std;

int main()
{
  // auto sum = [](int x, int y)
  // { return x + y; };
  // cout << sum(3, 5) << endl;

  // int input;
  // try
  // {

  //   cin >> input;

  //   if (input > 100)

  //     throw string("exit code 500");

  //   else if (input < 0)

  //     throw string("can't be negative");

  //   cout << input;
  // }

  //   catch (string str)
  // {
  //   cout << str;
  // }
  // fstream file;
  // file.open("bin.dat", ios::binary);
  // file.write(reinterpret_cast<char *>(30), sizeof(30));
  // file.close();

  // 29
  //    int input;
  //    cin >> input;

  //   while (!(input > 100 || input < 10 && input > 0))

  //   {

  //     cout << "Enter valid input: \n";

  //     cin >> input;
  //   }

  // 49
  //    int Arr[4]{2, 4, 6, 8};

  //   for (auto i : Arr)
  //   {
  //     cout << i << " ";
  //   }

  int input;

  try

  {

    cin >> input;

    if (input > 100)

      throw(int) 500;

    else if (input < 0)

      throw string("can't be negative");

    cout << input;
  }

  catch (string str)

  {

    cout << str;
  }
  catch (int i)
  {
    cout << "exit code " << i;
  }

  return 0;
}

// 38
void printLarger(int val1, int val2)
{
  cout << (val1 > val2) ? val1 : val2;
}

// 59
//  O(nlog(n)) while function execute logn times as j = n, and for lopp will execute n times.