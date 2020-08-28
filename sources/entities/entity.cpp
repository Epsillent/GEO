#include "entities/entity.hpp"
#include "components/sprite_2d.hpp"
#include "components/trigger_2d.hpp"
#include "const.hpp"
#include "ui/ui.hpp"
#include "bullet.hpp"
#include "scenes/battlefield.hpp"

Entity::Entity():
      m_cell(nullptr)
{
      
}

void Entity::on_introduce(){
      if(type()==NetworkObject::Type::Originator){
            m_side = Side::Left;
      }else{
            m_side = Side::Right;
            m_cell = nullptr;
      }
      Trigger2DProperties pr_trigger_2d;
      pr_trigger_2d.callback = CALLBACK(&Entity::on_collided);
      pr_trigger_2d.size = Trigger2D::size(GeoPropeties::figure_edge, GeoPropeties::figure_edge);
      m_c_trigger_2d = component_add<Trigger2D>(pr_trigger_2d);
      std::cout << m_side;
}

void Entity::make_damage(int damage) {
      m_health-=damage;
      if(m_health<=0) { 
            destroy();
      }
}

void Entity::add_health_text_view(TextView *health_text_view) {
      m_health_text_view = health_text_view;
}

void Entity::on_collided(Trigger2D other) {
      if( other.owner()->tag() == "bullet" && m_side != static_cast<Bullet*>( other.owner() )->side() ) {
            make_damage(1);
      } 
}

void Entity::set_collider_size(sf::Vector2f size) {
      Trigger2DProperties props;
      props.size = Trigger2D::size(size.x, size.y);
      props.callback = CALLBACK(&Entity::on_collided);
      m_c_trigger_2d->set_properties(props);
}

void Entity::on_destroy(){
      if(m_cell)
            *m_cell=0;
}


void Entity::decrease_owner_resources(int resources){
     ((Battlefield*)scene())->m_resources[m_side]->resources_decrease(resources);
}
void Entity::increase_owner_resources(int resources){
     ((Battlefield*)scene())->m_resources[m_side]->resources_increase(resources);

}

Entity *Entity::bind_cell(uint8 *cell){
      m_cell = cell;
      *m_cell = 1;
      return this;
}