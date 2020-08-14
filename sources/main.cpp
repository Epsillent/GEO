#include "engine.hpp"
#include "scenes/battlefield.hpp"
#include "scenes/main_menu.hpp"

int main() {
    Engine *engine = new Engine;
    EngineProperties props;
    props.show_fps = true;
    props.mode = sf::VideoMode(1480, 820);
    props.window_title = "Geo";
    props.frame_rate_limit = 60;
    engine->init(props);
    engine->set_entry_scene(new Battlefield, "Battlefield");
    engine->start();
}