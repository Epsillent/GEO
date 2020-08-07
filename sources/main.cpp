#include "engine.hpp"
#include "scenes/battlefield.hpp"

int main() {
    Engine *engine = new Engine;
    EngineProperties props;
    props.show_fps = true;
    props.window_heigth = 1280;
    props.window_heigth = 720;
    props.window_title = "Geo";
    props.frame_rate_limit = 60;
    engine->init(props);
    engine->set_entry_scene(new Battlefield, "Battlefield");
    engine->start();
}