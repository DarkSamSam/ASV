#include "../include/network.h"
#include <vector>
#include <random>
using namespace std;

Network::Network()
{
  neurons.push_back(new Neuron);
  connections.push_back(vector<Neuron*>(1,nullptr));
  neurons.push_back(new Neuron);
  connections.push_back(vector<Neuron*>(1,nullptr));
  connect(0,1);
}

Network::Network(unsigned int const& number)
{
  for(unsigned int i = 0; i<number; ++i)
  {
    neurons.push_back(new Neuron);
    connections.push_back(vector<Neuron*>(1,nullptr));
  }
  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<int> distrib(0,number-1);
  for(unsigned int i=0; i<neurons.size(); ++i)
  {
    for(unsigned int j=0; j<number/10; ++j)
    {
      connections[i].push_back(neurons[distrib(gen)]);
    }
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

bool Network::update_i(unsigned int const& i, double const& Iext)
{
  return neurons[i]->update(Iext);
}

void Network::update_all(double const& Iext)
{
  for(unsigned int i=0; i<neurons.size(); ++i)
  {
    bool spike = update_i(i, Iext);
    if (spike)
    {
      for(unsigned int j=0; j<connections[i].size(); ++j)
      {
        if (connections[i][j]!=nullptr)
        {
          connections[i][j]->receive(2.0);
        }
      }
    }
  }
}

ostream& Network::print(ostream& out) const
{
  for(unsigned int i=0; i<neurons.size(); ++i)
  {
    out << *neurons[i];
  }
  return out;
}
