
#include "hash.h"
using namespace std;

int main()
{
   Hash obj;




   obj.insert(17,"TEST");
   obj.insert(27,"ABC");
   obj.insert(28,"ALG");
   obj.insert(38,"LANCUCH");


   obj.print();



  cout<<  obj.find(238);




    return 0;
}
