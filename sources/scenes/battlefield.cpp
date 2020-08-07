#include "scenes/battlefield.hpp"
#include "entities/generator.hpp"

void Battlefield::on_init() {
    object_introduce(new Generator(5));
    
}

void Battlefield::on_update(float dt) {
    
}