#include "../include/neuron.h"
#include<cmath>
using namespace std;

Neuron::Neuron()
:V(0.0), spikes(0), step(0.1), nclock(0), tau(20.0), res(20.0), delay(15), PSP(0.1), Vth(20.0), Vreset(0.0), tref(10), incoming(0.0), buffer(16, 0)
{}

Neuron::Neuron(double const& pot, double const& h)
:V(pot), spikes(0), step(h), nclock(0), tau(20.0), res(20000.0), delay(15), PSP(0.1), Vth(20.0), Vreset(0.0), tref(10), incoming(0.0), buffer(16, 0)
{
  delay = 1.5/h;
  tref = 1/h;
}

double Neuron::getV() const
{
  return V;
}

unsigned int Neuron::getSpikes() const
{
  return spikes;
}

vector<unsigned int> Neuron::getTimes() const
{
  return times;
}

void Neuron::setV(double const& newV)
{
  V = newV;
}

void Neuron::addspike(unsigned int const& t)
{
  ++spikes;
  times.push_back(t);
}

double Neuron::newpot(double const& Iext) const
{
  double pot = exp(-step/tau)*V + Iext*res*(1-exp(-step/tau));
  return pot;
}

bool Neuron::update(double const& Iext)
{
  bool spike(false);
  if (V > Vth)
  {
    addspike(nclock);
    spike = true;
  }

  if (!times.empty() && (nclock-times.back()) < tref)
  {
    setV(0.0);
  }
  else
  {
    incoming = buffer[idx(nclock)];
    setV(newpot(Iext) + incoming);
    incoming = 0.0;
  }
  ++nclock;
  return spike;
}

ostream& Neuron::print(ostream& out) const
{
  out << nclock * step << " ms; " << V << " mV;";
  return out;
}

ostream& operator<<(ostream& out, Neuron const& n)
{
  return n.print(out);
}

void Neuron::receive(double const& J)
{
  incoming = J;
  buffer[idx(nclock+delay)] += J;
}

unsigned int Neuron::idx(unsigned int const& t)
{
  return t % (delay+1);
}
