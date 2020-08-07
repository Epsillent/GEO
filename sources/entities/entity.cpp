#include "entities/entity.hpp"
#include "components/sprite_2d.hpp"
#include "components/trigger_2d.hpp"

Entity::Entity(int health) {
      m_health = health;
}

void Entity::make_damage(int damage){
      m_health-=damage;
      if(m_health<=0){
            destroy();
      }
}