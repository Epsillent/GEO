#include "entities/selector/selector.hpp"
#include "const.hpp"
#include "entities/shooter.hpp"
#include "entities/protector.hpp"
#include "entities/generator.hpp"
#include "scenes/battlefield.hpp"
LocalSelector::LocalSelector():
    m_current_cell(0,0),
    m_delay(0),
    m_selected(EntitiesList::GeneratorType),
    spawned(false)
{}

void LocalSelector::on_introduce(){
    set_tag("LocalSelector");
    mp_body = component_add<Sprite2D>();
    mp_body->set_size(GeoPropeties::selector_size);
    mp_body->set_texture(&GeoPropeties::texture_pack->selector[Side::Left]);
}

void LocalSelector::on_update(float dt){
    m_time += dt;
    float delay = GeoPropeties::selector_move_delay;
    if(Input::key_pressed(KeyCode::W)){
        if(m_time > m_delay){
            move(0,-1);
            m_time -=m_delay;
            m_delay = delay;
        } 
    }
    else if(Input::key_pressed(KeyCode::S)){
        if(m_time > m_delay){
            move(0,1);
            m_time -=m_delay;
            m_delay = delay;
        } 
    }
    else if(Input::key_pressed(KeyCode::D)){
        if(m_time > m_delay){
            move(1,0);
            m_time -=m_delay;
            m_delay = delay;
        } 
    }
    else if(Input::key_pressed(KeyCode::A)){
        if(m_time > m_delay){
            move(-1,0);
            m_time -=m_delay;
            m_delay = delay;
        } 
    }else{
        m_time = 0;
        m_delay = 0;
    }
    if(Input::key_pressed(KeyCode::Space)){
        if(!spawned){
            spawned = true;
            originator_event(OriginatorEvent(m_selected));
            switch (m_selected)
            {
            case EntitiesList::GeneratorType:
                object_introduce(new Generator(1,((Battlefield*)scene())->m_left_resources,GeoPropeties::offset_in_selector,Side::Left));
                break;
            case EntitiesList::ShooterType:
                object_introduce(new Shooter(GeoPropeties::offset_in_selector,sf::Vector2f(1,0), Side::Left));
                break;
            case EntitiesList::ProtectorType:
                object_introduce(new Protector(GeoPropeties::offset_in_selector, Side::Left));
                break;
            default:
                break;
            }
        }

    } else{
        spawned = false;
    }

    if(Input::key_pressed(KeyCode::J))
        m_selected = EntitiesList::GeneratorType;
    if(Input::key_pressed(KeyCode::K))
        m_selected = EntitiesList::ShooterType;
    if(Input::key_pressed(KeyCode::L))
        m_selected = EntitiesList::ProtectorType;
    
}
void LocalSelector::move(int x, int y){
    sf::Vector2u new_cell = m_current_cell + sf::Vector2u(x,y);
    if(new_cell.x >= 0 && new_cell.y >= 0 && new_cell.x <= 4 && new_cell.y <= 4){
        m_current_cell = new_cell;
        network_translate(GeoPropeties::cell_size.x*x,GeoPropeties::cell_size.y*y);
        network_sync_transform();
    }
}
void LocalSelector::on_network_translate(const sf::Vector2f &position){
    //Info("RemoteSelector:OnTranslate: " + ARG_VEC("LocalPosition",position) + ARG_VEC("SetPosition",sf::Vector2f(DisplayServer::window_size().x-position.x-GeoPropeties::selector_size.x,position.y)));
    set_local_position(position);
    Info("---LocalSelector OnNetworkTranslate---" + std::string(guid()));
    //set_local_position(position);
}

void RemoteSelector::on_introduce(){
    set_tag("RemoteSelector");
    mp_body = component_add<Sprite2D>();
    mp_body->set_size(GeoPropeties::selector_size);
    mp_body->set_texture(&GeoPropeties::texture_pack->selector[Side::Right]);
}
void RemoteSelector::on_originator_event(const OriginatorEvent &event){
    switch ((EntitiesList)event.event_code)
    {
    case EntitiesList::GeneratorType:
        object_introduce(new Generator(1,((Battlefield*)scene())->m_right_resources,GeoPropeties::offset_in_selector,Side::Right));
        break;
    case EntitiesList::ShooterType:
        object_introduce(new Shooter(GeoPropeties::offset_in_selector,sf::Vector2f(-1,0), Side::Right));
        break;
    case EntitiesList::ProtectorType:
        object_introduce(new Protector(GeoPropeties::offset_in_selector, Side::Right));
        break;
    default:
        break;
    }
}

void RemoteSelector::on_network_translate(const sf::Vector2f &position){
    //Info("RemoteSelector:OnTranslate: " + ARG_VEC("LocalPosition",position) + ARG_VEC("SetPosition",sf::Vector2f(DisplayServer::window_size().x-position.x-GeoPropeties::selector_size.x,position.y)));
    set_local_position(sf::Vector2f(DisplayServer::window_size().x-position.x-GeoPropeties::selector_size.x,position.y));
    Info("RemoteSelector OnNetworkTranslate"  + std::string(guid()));
    //set_local_position(position);
}

