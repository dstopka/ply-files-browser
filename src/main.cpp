#include <Toolpack.hpp>
#include <GLWindow.hpp>

int main(int argc, char** argv)
{
    Data data = readFile(argv[1]);
    auto window = GLWindow(data);
    window.initScene(argc, argv);
    return 0;
}
