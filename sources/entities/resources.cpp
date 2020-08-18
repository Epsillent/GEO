#include "entities/resources.hpp"
#include "ui/ui.hpp"

Resources::Resources(TextView *text_view){
    m_text_view = text_view;
}

int Resources::get_resources(){
    return m_resources_count;
}

void Resources::resources_increase(int count){
    m_resources_count += count;
    m_text_view->set_string(std::to_string(m_resources_count));
}

void Resources::resources_decrease(int count) {
    m_resources_count -= count;
    m_text_view->set_string(std::to_string(m_resources_count));
}

void Resources::on_update(float dt){
    timer += dt;
}