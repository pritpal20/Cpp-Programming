#include <iostream>
#include "designPatterns.h"

int main()
{
  Journal *journal = new Journal{"Dear Diary"};
  (*journal).add("I ate a bug");
  (*journal).add("I cried today");

  //journal.save("diary.txt");

  PersistenceManager pm;
  pm.save(*(journal), "diary.txt");

  return SUCCESS;
}