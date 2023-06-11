#include "Domain.h"
#include <iostream>
#include <fstream>

using namespace std;


std::stringstream getTestIn(std::string filename)
{
    std::stringstream testIn;
    std::string testStr;
    std::fstream fin; fin.open(filename);

    if (fin.is_open())
    {
        while (getline(fin, testStr))
            testIn << testStr;

        fin.close();
    }

    return testIn;
}

void makeSVG(std::stringstream& svgOut, std::string& svgFilename)
{
    std::ofstream fout(svgFilename);

    if (fout.is_open())
    {
        fout << svgOut.rdbuf();
        std::cout << "Created New SVG File: " << svgFilename << '\n';
        fout.close();
    }

}


int main()
{
    for (int i = 1; i <= 11; ++i)
    {
        Domain d;
        char type;
        int x, y, w, h, r;

        std::string testFilename, svgFilename;
        std::stringstream testIn, svgOut;

        testFilename = "/Users/lowerschoolmusic/svgProjectNew/test" + std::to_string(i) + ".in";
        testIn = getTestIn(testFilename);
        testIn >> type;

        while (testIn) {
            if (type == 'C')
            {
                testIn >> x >> y >> r;

                Shape *p = new Circle(Point(x, y), r);
                d.addShape(p);
            }
            else if (type == 'R')
            {
                testIn >> x >> y >> w >> h;
                Shape *p = new Rectangle(Point(x, y), w, h);
                d.addShape(p);
            }
            testIn >> type;
        }
        svgOut << d.drawToSVG().rdbuf();

        svgFilename = "myAnswerTest" + std::to_string(i) + ".svg";
        makeSVG(svgOut, svgFilename);

    }
    return 0;
}
