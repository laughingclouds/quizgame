#include <random>

#include <drogon/drogon.h>

#include "models/Category.h"
#include "models/User.h"

auto randomEngine = std::default_random_engine();

int main() {  
  std::cout << "Server started!\n";
  
  drogon::app().loadConfigFile("../config.json");

  // Run HTTP framework,the method will block in the internal event loop
  drogon::app().run();
  return 0;
}
