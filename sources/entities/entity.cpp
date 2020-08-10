#include "entities/entity.hpp"
#include "components/sprite_2d.hpp"
#include "components/trigger_2d.hpp"

Entity::Entity(int health) {
      m_health = health;
      Trigger2DProperties pr_trigger_2d;
      pr_trigger_2d.callback = CALLBACK(&Entity::on_collided);
      pr_trigger_2d.size = Trigger2D::size(200, 200);
      m_c_trigger_2d = component_add<Trigger2D>(pr_trigger_2d);
}

void Entity::make_damage(int damage){
      m_health-=damage;
      if(m_health<=0){
            destroy();
      }
}


void Entity::on_collided(Trigger2D other){
      printf("123\n");
      destroy();
      if(other.owner()->tag()=="bullet"){
            make_damage(1);
            printf("health of this object is %i\n", m_health);
      }
}