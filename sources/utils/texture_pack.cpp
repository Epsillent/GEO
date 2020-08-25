#include "utils/texture_pack.hpp"
#include "entities/entity.hpp"

TexturePack::TexturePack(const std::string &path)
{
    
    if(  !(battlefield.loadFromFile(path+"Battlefield.png") &&
    selector[Side::Left].loadFromFile(path+"Left/Selector.png") &&
    selector[Side::Right].loadFromFile(path+"Right/Selector.png") &&
    protector[Side::Left].loadFromFile(path+"Left/Protector.png") &&
    protector[Side::Right].loadFromFile(path+"Right/Protector.png") &&
    generator[Side::Left].loadFromFile(path+"Left/Generator.png") &&
    generator[Side::Right].loadFromFile(path+"Right/Generator.png") &&
    shooter[Side::Left].loadFromFile(path+"Left/Shooter.png") &&
    shooter[Side::Right].loadFromFile(path+"Right/Shooter.png") && 
    base[Side::Left].loadFromFile(path+"Left/BaseUnit.png") &&
    base[Side::Right].loadFromFile(path+"Right/BaseUnit.png")&&
    main_menu_button.loadFromFile(path+"UI/MainMenuButton.png")&&
    local_btn.loadFromFile(path+"UI/LocalButton.png")&&
    remote_btn.loadFromFile(path+"UI/RemoteButton.png")&&
    main_menu_background.loadFromFile(path+"MainMenu.png"))) {
        Error("Loading TexturePack failed");
    }
}