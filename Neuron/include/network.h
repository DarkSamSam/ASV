#ifndef NETWORK_H
#define NETWORK_H
#include <vector>
#include "neuron.h"

class Network
{
private:


public:
  Network();
  Network(unsigned int const& number);
  ~Network();
  void connect(unsigned int const& i, unsigned int const& j);
  std::vector<Neuron*> neurons;
  std::vector<std::vector<Neuron*> > connections;
};
#endif //NETWORK_H
