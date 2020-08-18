#include "entities/entity.hpp"
#include "components/sprite_2d.hpp"
#include "components/trigger_2d.hpp"
#include "const.hpp"
#include "ui/ui.hpp"
#include "bullet.hpp"

Entity::Entity(int health) {
      m_health = health;
      Trigger2DProperties pr_trigger_2d;
      pr_trigger_2d.callback = CALLBACK(&Entity::on_collided);
      pr_trigger_2d.size = Trigger2D::size(GeoPropeties::figure_edge, GeoPropeties::figure_edge);
      m_c_trigger_2d = component_add<Trigger2D>(pr_trigger_2d);
}

void Entity::make_damage(int damage) {
      m_health-=damage;
      if(m_health<=0) { 
            //m_health_text_view->set_string("dead");
            destroy();
      } else if(m_health_text_view) {
            m_health_text_view->set_string(std::to_string(m_health));
      }
}

void Entity::add_health_text_view(TextView *health_text_view) {
      m_health_text_view = health_text_view;
}

void Entity::on_collided(Trigger2D other) {
      if( other.owner()->tag() == "bullet" && m_side != static_cast<Entity*>( other.owner() )->m_side ) {
            make_damage(1);
            printf("health of this object is %i\n", m_health);
      } 
}

void Entity::set_collider_size(sf::Vector2f size) {
      Trigger2DProperties props;
      props.size = Trigger2D::size(size.x, size.y);
      props.callback = CALLBACK(&Entity::on_collided);
      m_c_trigger_2d->set_properties(props);
}