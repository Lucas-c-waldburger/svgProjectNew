//
// Created by Lower School Music on 6/8/23.
//

#ifndef SVGPROJECTNEW_DOMAIN_H
#define SVGPROJECTNEW_DOMAIN_H

#include "Shape.h"
#include <iostream>
#include <vector>


const std::string HEADER =
        "<?xml version=\"1.0\" encoding=\"utf-8\" standalone=\"no\"?>\n"
        "<svg width=\"700\" height=\"600\"\n"
        "xmlns=\"http://www.w3.org/2000/svg\">\n"
        "<g transform=\"matrix(1,0,0,-1,50,550)\"\n"
        "fill=\"white\" fill-opacity=\"0.5\" stroke=\"black\" stroke-width=\"2\">\n"
        "<rect fill=\"lightgrey\" x=\"0\" y=\"0\" width=\"600\" height=\"500\"/>";

class Domain
{
public:
    Domain();
    ~Domain();
    void addShape(const Shape* p);
    void draw();
    std::stringstream drawToSVG();
private:
    int sizex, sizey;
    std::vector<const Shape*> s;
};

#endif //SVGPROJECTNEW_DOMAIN_H
