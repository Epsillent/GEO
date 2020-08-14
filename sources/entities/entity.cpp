#include "entities/entity.hpp"
#include "components/sprite_2d.hpp"
#include "components/trigger_2d.hpp"
#include "const.hpp"

Entity::Entity(int health) {
      m_health = health;
      Trigger2DProperties pr_trigger_2d;
      pr_trigger_2d.callback = CALLBACK(&Entity::on_collided);
<<<<<<< HEAD
      pr_trigger_2d.size = Trigger2D::size(GeoPropeties::figure_edge, GeoPropeties::figure_edge);
=======
      pr_trigger_2d.size = Trigger2D::size(200, 200);
>>>>>>> caa5cfcb25579d0f43ab3beb76f58f7cbaf74bc9
      m_c_trigger_2d = component_add<Trigger2D>(pr_trigger_2d);
}

void Entity::make_damage(int damage){
      m_health-=damage;
      if(m_health<=0){
            destroy();
      }
}

<<<<<<< HEAD
void Entity::on_collided(Trigger2D other){
=======

void Entity::on_collided(Trigger2D other){
      printf("123\n");
      destroy();
>>>>>>> caa5cfcb25579d0f43ab3beb76f58f7cbaf74bc9
      if(other.owner()->tag()=="bullet"){
            make_damage(1);
            printf("health of this object is %i\n", m_health);
      }
}