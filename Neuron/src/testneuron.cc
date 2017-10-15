#include<iostream>
#include<fstream>
#include "../include/neuron.h"
using namespace std;

int main()
{
  Neuron n;
  unsigned int tstop(1000); //=smth
  unsigned int simtime(0);
  double Iext(2.0);
  ofstream output;
  output.open("output/output.txt");
  if (output.fail())
  {
    cerr << "blop" << endl;
    return 3;
  }
  while (simtime < tstop)
  {
    n.update(Iext);
    output << n << endl;
    ++simtime;
  }
  output.close();
  return 0;
}
