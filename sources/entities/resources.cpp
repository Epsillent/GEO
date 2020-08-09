#include "entities/resources.hpp"
#include "ui/ui.hpp"

Resources::Resources(TextView *text_view){
    //text_view->set_text("1");
    m_text_view = text_view;
}

int Resources::get_resources(){
    return m_resources_count;
}

void Resources::resources_increase(int count){
    m_resources_count += count;
    m_text_view->set_text(std::to_string(m_resources_count));
}

void Resources::on_update(float dt){
    timer += dt;
}

void Resources::on_init(){
    
}