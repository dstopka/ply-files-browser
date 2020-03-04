#ifndef OOP_GL_MESH_HPP
#define OOP_GL_MESH_HPP

#include <Toolpack.hpp>
#include <Polygon.hpp>
#include <memory>

class Mesh
{
public:
    explicit Mesh(Data data);
    void draw();
    void createPolygons();

private:
    void generateVerticesBuffer();

private:
    std::shared_ptr<unsigned int> VBO;
    const Data data;
    std::shared_ptr<Polygon> quads;
    std::shared_ptr<Polygon> triangles;
};

#endif //OOP_GL_MESH_HPP
