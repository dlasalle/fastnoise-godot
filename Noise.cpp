/**
 * @file Noise.cpp
 * @brief Implmentation of the Noise class.
 * @author Dominique LaSalle <dominique@solidlake.com>
 * Copyright 2018
 * @version 1
 * @date 2018-06-24
 */


#include "Noise.hpp"

// import the c++ implementation
#include "FastNoise/FastNoise.cpp"

/******************************************************************************
* CONSTRUCTORS / DESTRUCTOR ***************************************************
******************************************************************************/

Noise::Noise() :
  Noise(0)
{
  // do nothing
}

Noise::Noise(const unsigned int seed) :
  m_noise(seed)
{
  //m_noise.SetNoiseType(FastNoise::Perlin);
}

/******************************************************************************
* PUBLIC METHODS **************************************************************
******************************************************************************/

void Noise::setSeed(
    const unsigned int seed)
{
  m_noise.SetSeed(seed);
}

double Noise::value(
    const double x,
    const double y) const
{
  return m_noise.GetNoise(x,y);
}

/******************************************************************************
* PROTECTED METHODS ***********************************************************
******************************************************************************/

void Noise::_bind_methods()
{
  ClassDB::bind_method(D_METHOD("value", "x", "y"),
      &Noise::value);
  ClassDB::bind_method(D_METHOD("set_seed", "seed"),
      &Noise::setSeed);
}

