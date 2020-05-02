#ifndef HAUSARBEITWEGSUCHE_CONFIG_HPP
#define HAUSARBEITWEGSUCHE_CONFIG_HPP

#include <iostream>
#ifdef makeGUI
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
#endif

#ifndef makeGUI
    namespace glm{
        class vec4{
        public:
            vec4(float, float, float, float){

            }
        };
    }

    using namespace glm;

    namespace xd {

        extern int width, height, frameCount;

        int displayDensity(){return 0.0;};
        float millis(){return 0.0;};
        void size(int w, int h){};

        float random(float min, float max){return 0.0;};
        void randomSeed(unsigned int seed){};

        void loop(){};
        void noLoop(){};
        void pop(){};
        void push(){};
        void redraw(){};

        void background(vec4 color){};
        void clear(){};
        void fill(vec4 color){};
        void noFill(){};
        void noStroke(){};
        void stroke(vec4 color){};
        void strokeWeight(float weight){};

        void applyMatrix(float a, float b, float c, float d, float e, float f){};
        void resetMatrix(){};
        void rotate(float angle){};
        void scale(float x, float y){};
        void translate(float x, float y){};

        void ellipse(float x, float y, float w, float h){};
        void tint(vec4 color){};
        void noTint(){};
        void text(const std::string& str, float x, float y){};
        void line(float x1, float y1, float x2, float y2){};
        void point(float x, float y){};
        void rect(float x, float y, float w, float h, bool useImageMode = false){};
        void triangle(float x1, float y1, float x2, float y2, float x3, float y3){};
    }

    void setup();
    void draw();
    void destroy();


#endif

#define tileSize 15

using namespace std;


#endif
