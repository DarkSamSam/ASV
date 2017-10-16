#include "../include/network.h"
#include <vector>
using namespace std;

Network::Network()
{
  neurons.push_back(new Neuron);
  connections.push_back(vector<Neuron*>());
  neurons.push_back(new Neuron);
  connections.push_back(vector<Neuron*>());
}

Network::Network(unsigned int const& number)
{
  for(unsigned int i = 0; i<number; ++i)
  {
    neurons.push_back(new Neuron);
    connections.push_back(vector<Neuron*>());
  }
}

Network::~Network()
{
  for(unsigned int i = 0; i<neurons.size(); ++i)
  {
    delete neurons[i];
  }
}

void Network::connect(unsigned int const& i, unsigned int const& j)
{
  connections[i].push_back(neurons[j]);
}
