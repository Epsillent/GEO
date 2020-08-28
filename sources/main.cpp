#include "engine.hpp"
#include "scenes/battlefield.hpp"
#include "scenes/main_menu.hpp"
#include "entities/selector/selector.hpp"
#include "core/math/random.hpp"
#include "entities/base.hpp"
#include "entities/generator.hpp"
#include "entities/shooter.hpp"
#include "entities/protector.hpp"
int main() {
    NetworkObjectsDB::register_object_representation<LocalSelector,RemoteSelector>();
    NetworkObjectsDB::register_object<Base>();
    NetworkObjectsDB::register_object<Entity>();
    NetworkObjectsDB::register_object<Shooter>();
    NetworkObjectsDB::register_object<Protector>();
    NetworkObjectsDB::register_object<Generator>();
    

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