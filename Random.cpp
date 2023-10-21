#include "Random.h"
#include <random>


namespace Random_Engine {
	std::random_device rd;
	std::mt19937 gen(rd());
}

float Random::Randfloat(float min, float max)
{
	std::uniform_real_distribution<float>rdf(min, max);
	return rdf(Random_Engine::gen);
}

int Random::Randint(int min, int max)
{
	std::uniform_int_distribution<int>rdi(min, max);

	return rdi(Random_Engine::gen);
}

double Random::Randdouble(double min, double max)
{
	std::uniform_real_distribution<double>rdd(min, max);
	return rdd(Random_Engine::gen);
}

bool Random::Random_from_percentage(float per)
{
	std::uniform_int_distribution<>rdi(0, INT_MAX);


	int flag = INT_MAX * (per * 0.01f);


	if (rdi(Random_Engine::gen) <= flag) {
		return true;
	}
	return false;
}
