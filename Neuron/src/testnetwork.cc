#include <iostream>
#include <vector>
#include "../include/neuron.h"
#include "../include/network.h"
using namespace std;

int main()
{
  Network net;
  net.connect(0,1);
  net.connections[1].push_back(nullptr);
  unsigned int tstop(1000); //=smth
  unsigned int simclock(0);
  double Iext(2.0);
  while (simclock < tstop)
  {
    for(unsigned int i=0; i<2; ++i)
    {
      bool spike=net.neurons[i]->update(Iext);
      if (spike)
      {
        if (!(net.connections[i][0]==nullptr)){
        net.connections[i][0]->receive(2.0);}
      }
      cout << *net.neurons[i];
    }
    ++simclock;
    cout << endl;
  }
  return 0;
}
