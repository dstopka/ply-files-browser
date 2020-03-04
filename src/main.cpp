#include <Toolpack.hpp>
#include <GLWindow.hpp>

int main(int argc, char** argv)
{
    auto window = GLWindow();
    for(auto i = 1; i < argc; ++i)
        window.addShape(readFile(argv[i]));
    window.initScene(argc, argv);
    return 0;
}
