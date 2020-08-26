#include "entities/selector/selector.hpp"
#include "const.hpp"
#include "entities/shooter.hpp"
#include "entities/protector.hpp"
#include "entities/generator.hpp"
#include "scenes/battlefield.hpp"

uint8 fantom = 0;
LocalSelector::LocalSelector(uint8 (*field)[5][5]):
    m_current_cell(0,0),
    m_delay(0),
    m_selected(EntitiesList::GeneratorType),
    spawned(false),
    m_field(field)
{}

void LocalSelector::on_introduce(){
    set_tag("LocalSelector");
    Battlefield::local_selector = this;
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
            if(!(*m_field)[m_current_cell.x][m_current_cell.y]){
                switch (m_selected)
                {
                case EntitiesList::GeneratorType:
                    if(((Battlefield*)scene())->m_left_resources->m_resources_count-GeoPropeties::generator_price >= 0){
                        ((Battlefield*)scene())->m_left_resources->resources_decrease(GeoPropeties::generator_price);
                        object_introduce(new Generator((*m_field)[m_current_cell.x][m_current_cell.y],Side::Left,((Battlefield*)scene())->m_left_resources))->translate(GeoPropeties::offset_in_selector);
                        originator_event(OriginatorEvent(m_selected));
                    }
                    break;
                case EntitiesList::ShooterType:
                    if(((Battlefield*)scene())->m_left_resources->m_resources_count-GeoPropeties::shooter_price >= 0){
                        ((Battlefield*)scene())->m_left_resources->resources_decrease(GeoPropeties::shooter_price);
                        object_introduce(new Shooter((*m_field)[m_current_cell.x][m_current_cell.y],Side::Left))->translate(GeoPropeties::offset_in_selector);
                        originator_event(OriginatorEvent(m_selected));
                    }
                    break;
                case EntitiesList::ProtectorType:
                    if(((Battlefield*)scene())->m_left_resources->m_resources_count-GeoPropeties::protector_price>=0){
                        ((Battlefield*)scene())->m_left_resources->resources_decrease(GeoPropeties::protector_price);
                        object_introduce(new Protector((*m_field)[m_current_cell.x][m_current_cell.y], Side::Left))->translate(GeoPropeties::offset_in_selector);
                        originator_event(OriginatorEvent(m_selected));
                    }
                    break;
                default:
                    break;
                }
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
    //set_local_position(position);
}

void LocalSelector::on_destroy(){
    Battlefield::remote_selector = nullptr;
}   

void RemoteSelector::on_introduce(){
    set_tag("RemoteSelector");
    Battlefield::remote_selector = this;
    mp_body = component_add<Sprite2D>();
    mp_body->set_size(GeoPropeties::selector_size);
    mp_body->set_texture(&GeoPropeties::texture_pack->selector[Side::Right]);
}
void RemoteSelector::on_originator_event(const OriginatorEvent &event){
    switch ((EntitiesList)event.event_code)
    {
    case EntitiesList::GeneratorType:
        ((Battlefield*)scene())->m_right_resources->resources_decrease(GeoPropeties::generator_price);
        object_introduce(new Generator(fantom,Side::Right,((Battlefield*)scene())->m_right_resources))->translate(GeoPropeties::offset_in_selector);
        break;
    case EntitiesList::ShooterType:
        ((Battlefield*)scene())->m_right_resources->resources_decrease(GeoPropeties::shooter_price);
        object_introduce(new Shooter(fantom,Side::Right))->translate(GeoPropeties::offset_in_selector);
        break;
    case EntitiesList::ProtectorType:
        ((Battlefield*)scene())->m_right_resources->resources_decrease(GeoPropeties::protector_price);
        object_introduce(new Protector(fantom, Side::Right))->translate(GeoPropeties::offset_in_selector);
        break;
    default:
        break;
    }
}

void RemoteSelector::on_network_translate(const sf::Vector2f &position){
    //Info("RemoteSelector:OnTranslate: " + ARG_VEC("LocalPosition",position) + ARG_VEC("SetPosition",sf::Vector2f(DisplayServer::window_size().x-position.x-GeoPropeties::selector_size.x,position.y)));
    set_local_position(sf::Vector2f(DisplayServer::window_size().x-position.x-GeoPropeties::selector_size.x,position.y));
    //set_local_position(position);
}

void RemoteSelector::on_destroy(){
    //Info("RemoteEndGame");
    ((Battlefield*)scene())->end_game(Side::Right);
    Battlefield::remote_selector = nullptr;
}

