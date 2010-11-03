#include "input.hpp"
#include "hidden.hpp"
#include "output.hpp"

int main(){
  srand(time(0));
  Input a,b,c;
  float aa,bb,cc;
  aa = 1;
  bb = 2;
  cc = 0;
  a.setInput(&aa);
  b.setInput(&bb);
  c.setInput(&cc);
  std::vector< Input * > inputs;
  inputs.push_back(&a);
  inputs.push_back(&b);
  inputs.push_back(&c);
  Hidden h1(inputs), h2(inputs), h3(inputs), h4(inputs), h5(inputs), h6(inputs);
  std::vector< Hidden * > hidden;
  hidden.push_back(&h1);
  hidden.push_back(&h2);
  hidden.push_back(&h3);
  hidden.push_back(&h4);
  hidden.push_back(&h6);
  hidden.push_back(&h5);
  Output oo(hidden);
  oo.learn();
  std::cout << oo.propagate() << std::endl;
  aa = 1;
  bb = 2;
  cc = 1;
  std::cout << oo.propagate() << std::endl;
  aa = 1;
  bb = 2;
  cc = 2;
  std::cout << oo.propagate() << std::endl;
  
  std::cout << oo.serialize()<< std::endl ;

  return 0;
}
