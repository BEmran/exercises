#include "circle.hpp"
#include "shape.hpp"
#include "square.hpp"

struct Draw {
    void operator()(const Circle& c){c.draw();}
    void operator()(const Square& s){s.draw();}
};

void draw_all(const Shapes& shapes) {
    for (const auto& shape : shapes) {
        std::visit(Draw(), shape);
    }
}
