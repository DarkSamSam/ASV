#ifndef NEURON_H
#define NEURON_H
#include<vector>
#include<iostream>

class Neuron
{
public:
	Neuron();
	Neuron(double const& pot, double const& h);
	double getV() const;
	unsigned int getSpikes() const;
	std::vector<unsigned int> getTimes() const;
	void setV(double const& newV);
	void addspike(unsigned int const& t);
	bool update(double const& Iext); //return true if spike occurs
	double newpot(double const& Iext) const; //solves membrane equation
	std::ostream& print(std::ostream& out = std::cout) const;
	void receive(double const& J);
private:
	double incoming;
	unsigned int tref; // refractory time
	double tau; //membrane time constant
	double res; //membrane resistance
	unsigned int delay; //synaptic delay
	double PSP; //post synaptic potential amplitude
	double Vth; //spike threshold
	double Vreset; //resting potential
	double step; //time step
	unsigned int nclock; //neuron clock
	double V;//V membrane potential
	unsigned int spikes;
	std::vector<unsigned int> times;//spike times, gonna be a vector of smth, maybe ints
};

std::ostream& operator<<(std::ostream& out, Neuron const& n);

#endif //NEURON_H
