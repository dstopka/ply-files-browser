#include <Toolpack.hpp>
#include <GLWindow.hpp>
#include <iostream>

int main(int argc, char** argv)
{
    auto window = GLWindow();
    for(auto i = 1; i <= argc; ++i)
        window.addShape(readFile(argv[i]));
//        Data data = readFile(argv[1]);
    window.initScene(argc, argv);
    return 0;
}
