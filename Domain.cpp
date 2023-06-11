#include "Domain.h"




Domain::Domain() : sizex(600), sizey(500)
{}

Domain::~Domain()
{
    for (auto& sh : s)
        delete sh;
}


void Domain::addShape(const Shape *p)
{
    s.push_back(p);
}

void Domain::draw()
{
    Rectangle domainRect = Rectangle(Point(0, 0), sizex, sizey);
    std::string positionText = "ok";

    std::cout << HEADER << '\n';

    for (int i = 0; i < s.size(); i++)
    {
        if (positionText != "does not fit" && !s[i]->fits_in(domainRect))
            positionText = "does not fit";

        else if (positionText == "ok")
        {
            for (int j = i + 1; j < s.size(); j++)
            {
                if (s[i]->overlaps(*s[j]))
                {
                    positionText = "overlap";
                    break;
                }
            }
        }
        s[i]->draw();
        std::cout << '\n';
    }

    std::cout << "</g>\n"
              << "<g transform=\"matrix(1,0,0,1,50,590)\"\n"
              << "font-family=\"Arial\" font-size=\"32\">\n"
              << "<text x=\"0\"y=\"0\">" << positionText << "</text>\n"
              <<"</g>\n</svg>";
}

std::stringstream Domain::drawToSVG()
{
    std::stringstream svgOut;
    Rectangle domainRect = Rectangle(Point(0, 0), sizex, sizey);
    std::string positionText = "ok";

    svgOut << HEADER << '\n';

    for (int i = 0; i < s.size(); i++)
    {
        if (positionText != "does not fit" && !s[i]->fits_in(domainRect))
            positionText = "does not fit";

        else if (positionText == "ok")
        {
            for (int j = i + 1; j < s.size(); j++) {
                if (s[i]->overlaps(*s[j]))
                {
                    positionText = "overlap";
                    break;
                }
            }
        }
        svgOut << s[i]->drawToSVG().rdbuf() << '\n';
    }

    svgOut << "</g>\n"
              << "<g transform=\"matrix(1,0,0,1,50,590)\"\n"
              << "font-family=\"Arial\" font-size=\"32\">\n"
              << "<text x=\"0\" y=\"0\">" << positionText << "</text>\n"
              <<"</g>\n</svg>";

    return svgOut;
}



