// #include "../GlobalDef.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <boost/lexical_cast.hpp>
using namespace std;

//Seperation of concerns

struct Journal
{
  string title;
  vector<string> entries;

  // explicit Journal(const string&& _title) : title(_title)
  // {

  // }

  explicit Journal(const string& _title) : title(_title)
  {

  }

  void add(const string& entry);

  // persistence is a separate concern
  void save(const string& filename);
  void show();
};

void Journal::add(const string& entry)
{
  static int count = 1;
  entries.push_back(boost::lexical_cast<string>(count++)
    + ": " + entry);
}

void Journal::save(const string& filename)
{
  ofstream ofs(filename);
  for (auto& s : entries)
    ofs << s << endl;
}

void Journal::show()
{
    cout << "\t" << this->title << "\n\n";
    for(auto &e : entries)
    {
        cout << e << endl;
    }
}

struct PersistenceManager
{
  static void save(const Journal& j, const string& filename)
  {
    ofstream ofs(filename);
    for (auto& s : j.entries)
      ofs << s << endl;
  }
};

int main()
{
    Journal journal{"Dear Diary"};
    journal.add("I ate a bug");
    journal.add("I cried today");

    //journal.save("diary.txt");

    PersistenceManager::save(journal, "diary.txt");
    journal.show();

  return 0;
}