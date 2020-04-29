#ifndef HAUSARBEITWEGSUCHE_CONFIG_HPP
#define HAUSARBEITWEGSUCHE_CONFIG_HPP

#include <iostream>

#ifdef __APPLE__
    #include "./libxd-0.3.2-Darwin/include/xd/xd.hpp"
    #include "./libxd-0.3.2-Darwin/include/glm/glm.hpp"
#endif

#ifdef _WIN32
    #include "./libxd-0.3.2-win32/include/xd/xd.hpp"
    #include "libxd-0.3.2-win32/include/glm/glm.hpp"
#endif

#ifdef _WIN64
    #include "./libxd-0.3.2-win32/include/xd/xd.hpp"
    #include "libxd-0.3.2-win32/include/glm/glm.hpp"
#endif

#define rows 50
#define columns 50
#define tileSize 15

using namespace std;


#endif
