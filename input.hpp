#include "common.hpp"
#ifndef NEURON_HPP
#define NEURON_HPP

class Input{

  float* value;

public:
  
  Input(){

  }

  void setInput(float* input){

    value = input;
  }
  float getValue(){
    return *value;
  }
  std::string serialize(){

    std::stringstream buf;
    buf <<  *value;
    return buf.str();
    
  }
  
  
};

#endif
