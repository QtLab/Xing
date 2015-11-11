#pragma once
class ModifiedPrice
{
public:
	ModifiedPrice();
	~ModifiedPrice();
	long operator()(long price);
	long operator()(long price, double rate);

private:
	double mRate;
};

