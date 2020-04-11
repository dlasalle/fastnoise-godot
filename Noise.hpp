/**
* @file Noise.hpp
* @brief The Noise class.
* @author Dominique LaSalle <dominique@solidlake.com>
* Copyright 2018
* @version 1
* @date 2018-06-23
*/



#ifndef GODOT_NOISE_HPP
#define GODOT_NOISE_HPP


#include "core/reference.h"

#define FN_USE_DOUBLES 1
#include "FastNoise/FastNoise.h"

class Noise : public Reference
{
  GDCLASS(Noise, Reference);

  public:
    Noise(); 
    Noise(unsigned int seed); 

    void setSeed(unsigned int seed);

    double value(double x, double y) const;
    
  protected:
    static void _bind_methods();

  private:
    FastNoise m_noise;
};

#endif
