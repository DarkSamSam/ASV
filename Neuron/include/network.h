#ifndef NETWORK_H
#define NETWORK_H
#include <vector>
#include "neuron.h"

class Network
{
private:
  std::vector<Neuron*> neurons;
  std::vector<std::vector<Neuron*> > connections;

public:
  Network();
  Network(unsigned int const& number);
  ~Network();
  void connect(unsigned int const& i, unsigned int const& j);
  bool update_i(unsigned int const& i, double const& Iext);
  void update_all(double const& Iext);
  std::ostream& print(std::ostream& out = std::cout) const;
};
#endif //NETWORK_H
