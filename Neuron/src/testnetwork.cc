#include <iostream>
#include <vector>
#include <fstream>
#include "../include/neuron.h"
#include "../include/network.h"
using namespace std;

int main()
{
  Network net(10);
  unsigned int tstop(1000); //=smth
  unsigned int simclock(0);
  double Iext(2.0);
  ofstream output;
  output.open("output/output.txt");
  if(output.fail())
  {
    cerr << "perdu!" << endl;
    return 42;
  }
  while (simclock < tstop)
  {
    net.update_all(Iext);
    net.print(output);
    ++simclock;
    output << endl;
  }
  output.close();
  return 0;
}
