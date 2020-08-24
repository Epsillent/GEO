#include "engine.hpp"
#include "scenes/battlefield.hpp"
#include "scenes/main_menu.hpp"
#include "entities/selector/selector.hpp"
#include "core/math/random.hpp"
int main() {
    NetworkObjectsDB::register_object_representation<LocalSelector,RemoteSelector>();
    

    Engine *engine = new Engine;
    EngineProperties props;
    props.show_fps = true;
    props.mode = sf::VideoMode(1280, 720);
    props.window_title = "Geo";
    props.frame_rate_limit = 60;
    //engine->init(props);
    engine->initialize(props);
    GeoPropeties::texture_pack = new TexturePack("resources/capitalist/");
    engine->set_entry_scene(new MainMenu, "MainMenu");
    Random::seed(time(0));
    engine->start();
    engine->finalize();
}